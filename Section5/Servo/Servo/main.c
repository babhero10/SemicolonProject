/*
 * Servo.c
 *
 * Created: 7/31/2022 11:10:40 PM
 * Author : CARNIVAL
 */ 

#define F_CPU 1000000UL

#include <util/delay.h>
#include <stdint.h>

#include "./ECU/Controller/Controller.h"
#include "./ECU/Servo/Servo.h"
#include "./ECU/LCD/LCD.h"

int main(void)
{
	init_LCD();
    init_controller();
	init_servo();
	uint16_t res;
    while (1) 
    {
		res = read_controller(0);
		write_servo(res);
		send_int(180 * (res / 1023.0));
		send_string("Deg");
		_delay_ms(500);
		send_command(0x01);
	}
}

