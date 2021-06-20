/*
 * kbdRecord.c
 *
 *  Created on: May 28, 2021
 *      Author: Anthony
 */


#include "kbdRecord.h"
#include "main.h"

uint8_t globalPressedKeys[KEY_PRESS_NB_MAX]={0};
uint8_t currentKeymapLevel=0;
uint8_t currentModifier=0;

extern osMessageQueueId_t keyboardRecordQueueHandle;

char kbdRecord(uint8_t *currentPressedKeys ){

	int i,j;
	int keyIdx=0;
	char matrixChanged = False;
	char found=False;
	uint8_t newKeyPressedMsg[KEY_PRESS_NB_MAX]={0};
	KEYMSGQUEUE_OBJ_t keyMsgQueueObj;

	//changement tableau boutons appuyés
	for (i=0;i<KEY_PRESS_NB_MAX;i++)
	{
		if (currentPressedKeys[i]!=globalPressedKeys[i])
		{
			matrixChanged= True;
			break;
		}
	}

	if (matrixChanged==True)
	{
		memset(&keyMsgQueueObj, 0, sizeof keyMsgQueueObj);
		keyIdx=0;

		//detect newly pressed keys
		for (i=0;i<KEY_PRESS_NB_MAX;i++)
		{
			found=False;
			//find globalPressedKeys elmt in currentPressedKeys
			if (currentPressedKeys[i]!=0x00){
				for (j=0;j<KEY_PRESS_NB_MAX;j++){
					if (currentPressedKeys[i]==globalPressedKeys[j]){
						found=True;
						break;
					}
				}

				//If not found, key newly pressed
				if (found==False)
				{
					keyMsgQueueObj.Buf[keyIdx]=currentPressedKeys[i];
					keyIdx++;
				}
			}

		}


		//send to processRecord in case of key(s) newly pressed
		if (keyIdx != 0){
			keyMsgQueueObj.KeyNbr=keyIdx;
			keyMsgQueueObj.Action=PRESS;
			keyMsgQueueObj.KeyType=UNICODE;
			osMessageQueuePut(keyboardRecordQueueHandle,&keyMsgQueueObj,0U,0U);
		}

		//detect newly released keys
		memset(&keyMsgQueueObj, 0, sizeof keyMsgQueueObj);
		keyIdx=0;
		for (i=0;i<KEY_PRESS_NB_MAX;i++)
		{
			found=False;
			if (globalPressedKeys[i]!=0x00)
			{
				for (j=0;j<KEY_PRESS_NB_MAX;j++)
				{
					if (globalPressedKeys[i]==currentPressedKeys[j]){
						found=True;
						break;
					}
				}

				//If not found, key newly released
				if (found==False)
				{

					keyMsgQueueObj.Buf[keyIdx]= globalPressedKeys[i];
					keyIdx++;
				}
			}
		}

		//send to processRecord in case of key(s) newly released
		if (keyIdx != 0){
			keyMsgQueueObj.KeyNbr=keyIdx;
			keyMsgQueueObj.Action=RELEASE;
			keyMsgQueueObj.KeyType=UNICODE;
			osMessageQueuePut(keyboardRecordQueueHandle,&keyMsgQueueObj,0U,0U);
		}

	}


	//copy currentPressedKeys in globalPressedKeys
	for (i=0;i<KEY_PRESS_NB_MAX;i++)
	{
		globalPressedKeys[i]=currentPressedKeys[i];
	}

	return matrixChanged;

}


void kbdMatrixRead(void){

	matrixState *matrixState;
	uint8_t currentPressedKeys[KEY_PRESS_NB_MAX];
	int i;

	memset(currentPressedKeys, 0, sizeof(currentPressedKeys));
	matrixState=ReadMatrixState();


	for (i=0;i<matrixState->keyCurrentEntriesNb;i++){
		currentPressedKeys[i]=keymap_azerty[currentKeymapLevel][(matrixState->keyTab[i][1])-1][(matrixState->keyTab[i][0])-1];
	}


    kbdRecord(currentPressedKeys);
}
