/*
 * Intput_Capture_mode.c
 *
 * Created: 8/3/2022 10:35:21 PM
 * Author : CARNIVAL
 */ 

#include <util/delay.h>
#include "./ECU/Button/Button.h"
#include "./ECU/LCD/LCD.h"

int main(void)
{  
	init_LCD();
	init_button();
	double res;
    while (1)
    {
		res = read_button();
		send_command(0x01);
		send_float(res);
		send_char('S');
	}
}

