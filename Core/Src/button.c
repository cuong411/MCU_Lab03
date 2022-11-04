/*
 * button.c
 *
 *  Created on: Oct 21, 2022
 *      Author: Cuong
 */

#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress = 500;
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int button1_count = 0;
int button2_count = 0;
int button3_count = 0;

void getKeyInput1()
{
	if(HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == GPIO_PIN_RESET)
	{
		button1_count++;
		if(button1_count == 3)
		{
			button1_flag = 1;
		}
	}
	else
	{
		if(button1_count < 3)
		{
			button1_flag = 0;
		}
		button1_count = 0;
	}
}

void getKeyInput2()
{
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	KeyReg0 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
	if((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2))
	{
		if(KeyReg2 != KeyReg3)
		{
			KeyReg3 = KeyReg2;
			if(KeyReg3 == PRESSED_STATE)
			{
				TimeOutForKeyPress = 10;
				button2_flag = 1;
			}
		}
		else
		{
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress <= 0) KeyReg3 = NORMAL_STATE;
		}
	}
	else
	{
		button2_flag = 0;
	}
}

void getKeyInput3()
{
	if(HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == GPIO_PIN_RESET)
	{
		button3_count++;
		if(button3_count == 3)
		{
			button3_flag = 1;
		}
	}
	else
	{
		if(button3_count < 3)
		{
			button3_flag = 0;
		}
		button3_count = 0;
	}
}
