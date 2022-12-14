/*
 * fsm_automatic.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#include "fsm_automatic.h"

int status1 = INIT;
int status2 = INIT;
int timer_red = 7;
int timer_yellow = 2;
int timer_green = 3;

void fsm_automatic_run()
{
	// traffic light 1
	switch(status1)
	{
	case INIT:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
		set_timer1(timer_red * 1000);
		status1 = AUTO_RED;
		countdown0 = timer_red;
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
		if(timer1_flag == 1)
		{
			timer1_flag = 0;
			set_timer1(timer_green * 1000);
			status1 = AUTO_GREEN;
			countdown0 = timer_green;
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
		if(timer1_flag == 1)
		{
			timer1_flag = 0;
			set_timer1(timer_red * 1000);
			status1 = AUTO_RED;
			countdown0 = timer_red;
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
		if(timer1_flag == 1)
		{
			timer1_flag = 0;
			set_timer1(timer_yellow * 1000);
			status1 = AUTO_YELLOW;
			countdown0 = timer_yellow;
		}
		break;
	default:
		status1 = INIT;
		break;
	}
	// traffic light 2
	switch(status2)
	{
	case INIT:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
		set_timer2(timer_green * 1000);
		status2 = AUTO_GREEN;
		countdown1 = timer_green;
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
		if(timer2_flag == 1)
		{
			timer2_flag = 0;
			set_timer2(timer_green * 1000);
			status2 = AUTO_GREEN;
			countdown1 = timer_green;
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
		if(timer2_flag == 1)
		{
			timer2_flag = 0;
			set_timer2(timer_red * 1000);
			status2 = AUTO_RED;
			countdown1 = timer_red;
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
		if(timer2_flag == 1)
		{
			timer2_flag = 0;
			set_timer2(timer_yellow * 1000);
			status2 = AUTO_YELLOW;
			countdown1 = timer_yellow;
		}
		break;
	default:
		status2 = INIT;
		break;
	}
}

