/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#include "software_timer.h"

int timer0_counter = 100;
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;

int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int timer3_flag = 0;

void set_timer1(int duration)
{
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

void set_timer2(int duration)
{
	timer2_counter = duration / TICK;
	timer2_flag = 0;
}

void set_timer3(int duration)
{
	timer3_counter = duration / TICK;
	timer3_flag = 0;
}

void timer_run()
{
	// red led exclusive
	if(timer0_counter <= 0)
	{
		timer0_flag = 1;
		timer0_counter = 100;
	}
	else timer0_counter--;
	// controls first traffic light
	if(timer1_counter <= 0) timer1_flag = 1;
	else timer1_counter--;
	// controls second traffic light
	if(timer2_counter <= 0) timer2_flag = 1;
	else timer2_counter--;
	// controls 7 segment leds
	if(timer3_counter <= 0) timer3_flag = 1;
	else timer3_counter--;
}
