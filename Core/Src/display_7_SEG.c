/*
 * display_7_SEG.c
 *
 *  Created on: Oct 26, 2022
 *      Author: Cuong
 */

#include "display_7_SEG.h"

int enabled_7SEG = EN0;
int countdown0 = 0;
int countdown1 = 0;

void display7SEG1(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
}

void display7SEG2(int num)
{
	if(num < 0 || num > 9) return;
	if(num == 1 || num == 4) HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	if(num == 5 || num == 6) HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	if(num == 2) HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 4 || num == 7) HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	if(num % 2 == 1 || num == 4) HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
	if(num == 1 || num == 2 || num == 3 || num == 7) HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	if(num == 0 || num == 1 || num == 7) HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
}

void display_7SEG_automatic()
{
	switch(enabled_7SEG)
	{
	case EN0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(countdown0 / 10);
		display7SEG2(countdown0 % 10);
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			set_timer3(500);
			enabled_7SEG = EN1;
			countdown0--;
		}
		break;
	case EN1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG1(countdown1 / 10);
		display7SEG2(countdown1 % 10);
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			set_timer3(500);
			enabled_7SEG = EN0;
			countdown1--;
		}
		break;
	default:
		break;
	}
}

void display_7SEG_modify()
{
	switch(enabled_7SEG)
	{
	case EN0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		display7SEG1(0);
		display7SEG2(mode);
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			set_timer3(500);
			enabled_7SEG = EN1;
		}
		break;
	case EN1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		display7SEG1(count / 10);
		display7SEG2(count % 10);
		if(timer3_flag == 1)
		{
			timer3_flag = 0;
			set_timer3(500);
			enabled_7SEG = EN0;
		}
		break;

	}
}
