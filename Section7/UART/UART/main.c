#define F_CPU 1000000UL			

#include "ECU/Terminal/Terminal.h"

int main()
{
	init_terminal();
	
	//UART_SendString("\n\t Echo Test ");	
	while(1)
	{
		send_terminal(read_terminal());
	}	
}