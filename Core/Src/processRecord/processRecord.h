/*
 * processRecord.h
 *
 *  Created on: 17 juin 2021
 *      Author: Anthony
 */

#ifndef SRC_PROCESSRECORD_PROCESSRECORD_H_
#define SRC_PROCESSRECORD_PROCESSRECORD_H_




typedef struct
{
       uint8_t MODIFIER;
       uint8_t RESERVED;
       uint8_t KEYCODE1;
       uint8_t KEYCODE2;
       uint8_t KEYCODE3;
       uint8_t KEYCODE4;
       uint8_t KEYCODE5;
       uint8_t KEYCODE6;
} keyboardHID;


keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};
const keyboardHID keyboardhid_empty = {0,0,0,0,0,0,0,0};




typedef struct
{
	uint8_t PAGE;
	uint8_t MODIFIER;
	char	MAJ_LOCK;
	char 	SCROLL_LOCL;

} KBDglobalState;

KBDglobalState globalState;


#endif /* SRC_PROCESSRECORD_PROCESSRECORD_H_ */
