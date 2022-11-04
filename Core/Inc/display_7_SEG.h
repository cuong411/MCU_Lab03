/*
 * display_7_SEG.h
 *
 *  Created on: Oct 26, 2022
 *      Author: Cuong
 */

#ifndef INC_DISPLAY_7_SEG_H_
#define INC_DISPLAY_7_SEG_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"

#define EN0	0
#define EN1	1

void display7SEG1();
void display7SEG2();

void display_7SEG_automatic();
void display_7SEG_modify();

#endif /* INC_DISPLAY_7_SEG_H_ */
