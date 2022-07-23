/*
 * calculator.c
 *
 * Created: 7/22/2022 7:23:58 PM
 *  Author: CARNIVAL
 */ 

#include "calculator.h"

float calc(char num1, char num2, char oper)
{
	switch (oper)
	{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case 'X':
			return num1 * num2;
		case '/':
			return ((double)num1) / num2;
		default:
			return -1;
	}
}