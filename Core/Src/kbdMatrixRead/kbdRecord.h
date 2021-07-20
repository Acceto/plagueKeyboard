/*
 * kbdRecord.h
 *
 *  Created on: May 28, 2021
 *      Author: Anthony
 */

#ifndef SRC_KBDMATRIXREAD_KBDRECORD_H_
#define SRC_KBDMATRIXREAD_KBDRECORD_H_

#include "matrixRead.h"
#include "kbdConfig.h"
#include "kbdKeymap.h"
#include "cmsis_os.h"



char kbdRecord(uint8_t *);
void kbdMatrixRead(void);
char isValueInArray(uint8_t, uint8_t*, uint8_t);

#endif /* SRC_KBDMATRIXREAD_KBDRECORD_H_ */
