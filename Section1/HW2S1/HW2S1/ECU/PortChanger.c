/*
 * PortChanger.c
 *
 * Created: 7/19/2022 1:24:33 PM
 *  Author: CARNIVAL
 */ 

#include "./../MCAL/PortChange.h"
#include "PortChanger.h"

void init_port_changer()
{
	init_port();
}

void change_DDR_depends()
{
	bool state = read_pin(INPUT_PIN);
	
	change_DDR(CHANGED_PIN, state);
}