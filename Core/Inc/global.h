/*
 * global.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_modify.h"

// define duration of 1 tick
#define TICK	10

// states of led status
#define INIT		1
#define AUTO_RED	2
#define AUTO_YELLOW	3
#define AUTO_GREEN	4

#define MOD_RED		12
#define MOD_GREEN	13
#define MOD_YELLOW	14

extern int status1;
extern int status2;

// duration of traffic led
extern int timer_red;
extern int timer_yellow;
extern int timer_green;

// mod section
extern int mode;
extern int count;

#endif /* INC_GLOBAL_H_ */
