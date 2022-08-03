/*
 * Button.c
 *
 * Created: 8/4/2022 12:18:16 AM
 *  Author: CARNIVAL
 */ 

#include "./../../MCAL/InputCapture/InputCapture.h"
#include "Button.h"

void init_button()
{
	init_input_capture();
}

double read_button()
{
	return read_on_time();
}