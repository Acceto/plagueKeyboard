/*
 * kbdKeymap.h
 *
 *  Created on: May 28, 2021
 *      Author: Anthony
 */

#ifndef SRC_KBDMATRIXREAD_KBDKEYMAP_H_
#define SRC_KBDMATRIXREAD_KBDKEYMAP_H_

#include "stm32f1xx_hal.h"
#include "usb_keycode.h"
#include "kbdLayout.h"


const uint16_t keymap_azerty[][MATRIX_COLS][MATRIX_ROWS] = {
    LAYOUT(\
        KEY_ESC, 		KEY_1,			KEY_2,		KEY_3,   KEY_4,   KEY_5,   KEY_6,   KEY_7,   KEY_8,   KEY_9,   		KEY_0,   		KEY_MINUS,		KEY_EQUAL, 		KEY_BACKSPACE,\
		KEY_TAB, 		KEY_Q,			KEY_W,		KEY_E,   KEY_R,   KEY_T,   KEY_Y,   KEY_U,   KEY_I,   KEY_O,   		KEY_P,   		KEY_LEFTBRACE,	KEY_RIGHTBRACE, KEY_ENTER,\
		KEY_CAPSLOCK, 	KEY_A,			KEY_S,		KEY_D,   KEY_F,   KEY_G,   KEY_H,   KEY_J,   KEY_K,   KEY_L,   		KEY_SEMICOLON,  KEY_APOSTROPHE,	KEY_HASHTILDE, 	KEY_ENTER,\
		KEY_LEFTSHIFT, 	KEY_BACKSLASH,	KEY_Z,		KEY_X,   KEY_C,   KEY_V,   KEY_B,   KEY_N,   KEY_M,   KEY_COMMA,	KEY_DOT,   		KEY_SLASH,		KEY_UP, 		KEY_RIGHTSHIFT,\
		KEY_LEFTCTRL, 	KEY_HOME,		KEY_LEFTALT,KEY_3,   KEY_4,   KEY_5,       KEY_SPACE,    KEY_8,   KEY_RIGHTALT,   		KEY_RIGHTCTRL,   		KEY_LEFT,		KEY_DOWN, 		KEY_RIGHT \
    )
};


#endif /* SRC_KBDMATRIXREAD_KBDKEYMAP_H_ */
#define KEY_LEFTCTRL 0xe0 // Keyboard Left Control
#define KEY_LEFTSHIFT 0xe1 // Keyboard Left Shift
#define KEY_LEFTALT  0xe2 // Keyboard Left Alt
#define KEY_LEFTMETA 0xe3 // Keyboard Left GUI
#define KEY_RIGHTCTRL 0xe4 // Keyboard Right Control
#define KEY_RIGHTSHIFT 0xe5 // Keyboard Right Shift
#define KEY_RIGHTALT 0xe6 // Keyboard Right Alt
#define KEY_RIGHTMETA 0xe7 // Keyboard Right GUI
