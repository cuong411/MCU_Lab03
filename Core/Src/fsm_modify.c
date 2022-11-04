/*
 * fsm_modify.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Cuong
 */

#include "fsm_modify.h"

void fsm_modify_run()
{
	switch(mode)
	{
	case 2:
		// blinking red led
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
			HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
		}
		// modify value
		if(button2_flag == 1)
		{
			button2_flag = 0;
			count++;
		}
		if(count > 99) count = 1;
		// set the value
		if(button3_flag == 1)
		{
			button3_flag = 0;
			timer_red = count;
			count = 1;
		}
		break;
	case 3:
		// blinking yellow led
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
			HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
		}
		// modify value
		if(button2_flag == 1)
		{
			button2_flag = 0;
			count++;
		}
		if(count > 99) count = 1;
		// set the value
		if(button3_flag == 1)
		{
			button3_flag = 0;
			timer_yellow = count;
			count = 1;
		}
		break;
	case 4:
		// blinking green led
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
			HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
		}
		// modify value
		if(button2_flag == 1)
		{
			button2_flag = 0;
			count++;
		}
		if(count > 99) count = 1;
		// set the value
		if(button3_flag == 1)
		{
			button3_flag = 0;
			timer_green = count;
			count = 1;
		}
		break;
	default:
		break;
	}
}
