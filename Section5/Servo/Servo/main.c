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
	uint16_t last_res = 181;
    while (1) 
    {
		res = read_controller(0);
		if (last_res != res && last_res - 1 != res && last_res + 1 != res)
		{
			send_command(0x01);
			write_servo(res);
			send_int(180 * (res / 1023.0));
			send_string("Deg");
			_delay_ms(250);
			last_res = res;
		}
		
	}
}

