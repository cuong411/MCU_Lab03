/*
 * button.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NORMAL_STATE	SET
#define PRESSED_STATE	RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

void getKeyInput1();
void getKeyInput2();
void getKeyInput3();


#endif /* INC_BUTTON_H_ */
