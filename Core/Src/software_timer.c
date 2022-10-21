/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#include "software_timer.h"

int timer1_counter = 0;
int timer0_counter = 100;

int timer0_flag = 0;
int timer1_flag = 0;

void set_timer1(int duration)
{
	timer1_counter = duration;
	timer1_flag = 0;
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
	// controls others
	if(timer1_counter <= 0) timer1_flag = 1;
	else timer1_counter--;
}
