/*
 * matrixRead.h
 *
 *  Created on: May 28, 2021
 *      Author: Anthony
 */

#ifndef SRC_KBDMATRIXREAD_MATRIXREAD_H_
#define SRC_KBDMATRIXREAD_MATRIXREAD_H_




#include "stm32f1xx_hal.h"

void bWriteColumnState(int, uint8_t);
int bReadRowState(int);
int intReadRowState(void);


typedef struct
{
	uint8_t keyCurrentEntriesNb;
	uint8_t KeylastEntryIdx;
	uint16_t keyTab[70][2];
} matrixState;




int * intReadMatrix(void);

matrixState * ReadMatrixState(void);


#endif /* SRC_KBDMATRIXREAD_MATRIXREAD_H_ */
