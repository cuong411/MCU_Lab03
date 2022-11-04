/*
 * software_timer.h
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

// used for count down number of 7 segments leds
extern int timer1_counter;
extern int timer2_counter;

void set_timer1(int duration);
void set_timer2(int duration);
void set_timer3(int duration);

void timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
