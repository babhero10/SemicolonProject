/*
 * Light.c
 *
 * Created: 7/17/2022 8:40:42 PM
 *  Author: CARNIVAL
 */ 

#include "Light.h"

void Light_init()
{
	Led_init();
}

void flicker() 
{
	toggle();
}