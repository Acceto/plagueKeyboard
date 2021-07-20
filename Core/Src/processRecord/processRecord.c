/*
 * processRecord.c
 *
 *  Created on: 3 juin 2021
 *      Author: Anthony
 */

#include "main.h"
#include "cmsis_os.h"
#include "processRecord.h"
#include "usb_device.h"

extern osMessageQueueId_t keyboardRecordQueueHandle;
extern USBD_HandleTypeDef hUsbDeviceFS;


/*void processModifier(){}


void processU*/


void processRecord(void){

	KEYMSGQUEUE_OBJ_t keyMsgQueueObj;
	uint32_t queueCount;
	osStatus_t status;
	uint8_t i,keycodeIdx;

	queueCount= osMessageQueueGetCount(keyboardRecordQueueHandle);

	if (queueCount>=1){
		status=osMessageQueueGet(keyboardRecordQueueHandle,&keyMsgQueueObj,NULL,0U);

		if(keyMsgQueueObj.Action==PRESS)
		{

			keycodeIdx=0;
			keyboardhid=keyboardhid_empty;
			keyboardhid.MODIFIER=globalState.MODIFIER;

			for(i=0;i<keyMsgQueueObj.KeyNbr;i++)
			{

				switch (keyMsgQueueObj.Buf[i])
					{

					case KEY_LEFTCTRL:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_LCTRL);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTSHIFT:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_LSHIFT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTALT:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_LALT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTMETA:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_LMETA);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTCTRL:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_RCTRL);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTSHIFT:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_RSHIFT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTALT:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_RALT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTMETA:
						keyboardhid.MODIFIER = (globalState.MODIFIER | KEY_MOD_RMETA);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;

					default:
						switch (keycodeIdx)
						{
							case 0:
								keyboardhid.KEYCODE1=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
							case 1:
								keyboardhid.KEYCODE2=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
							case 2:
								keyboardhid.KEYCODE3=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
							case 3:
								keyboardhid.KEYCODE4=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
							case 4:
								keyboardhid.KEYCODE5=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
							case 5:
								keyboardhid.KEYCODE6=keyMsgQueueObj.Buf[i];
								keycodeIdx++;
								break;
						}
					}
				}


			//Envoi de la trame USB
			USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));

			}




		if(keyMsgQueueObj.Action==RELEASE){

			keycodeIdx=0;
			keyboardhid=keyboardhid_empty;
			keyboardhid.MODIFIER=globalState.MODIFIER;

			for(i=0;i<keyMsgQueueObj.KeyNbr;i++)
			{


				switch (keyMsgQueueObj.Buf[i])
					{
					case KEY_LEFTCTRL:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_LCTRL);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTSHIFT:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_LSHIFT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTALT:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_LALT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_LEFTMETA:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_LMETA);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTCTRL:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_RCTRL);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTSHIFT:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_RSHIFT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTALT:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_RALT);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;
					case KEY_RIGHTMETA:
						keyboardhid.MODIFIER = (globalState.MODIFIER ^ KEY_MOD_RMETA);
						globalState.MODIFIER = keyboardhid.MODIFIER ;
						break;

					default:
						switch (keycodeIdx)
						{
							case 0:
								keyboardhid.KEYCODE1=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
							case 1:
								keyboardhid.KEYCODE2=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
							case 2:
								keyboardhid.KEYCODE3=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
							case 3:
								keyboardhid.KEYCODE4=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
							case 4:
								keyboardhid.KEYCODE5=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
							case 5:
								keyboardhid.KEYCODE6=(keyMsgQueueObj.Buf[i] | 0x80);
								keycodeIdx++;
								break;
						}
					}
				}


			//Envoi de la trame USB
			USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof (keyboardhid));


		}

	}

}
