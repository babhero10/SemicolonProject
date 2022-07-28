/*
 * keypad.c
 *
 * Created: 7/22/2022 6:09:22 PM
 *  Author: CARNIVAL
 */ 

#include "keypad.h"

/*const unsigned char KEYPAD[4][4] =
{
	{'7','8','9','/'},
	{'4','5','6','X'},
	{'1','2','3','-'},
	{'C','0','=','+'}
};*/

const unsigned char KEYPAD[4][4] =
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','X'},
	{'C','0','=','/'}
};

void init_keypad()
{
	KEYPAD_DDR = 0x00;
	KEYPAD_DDR |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
	
	KEYPAD_PORT = 0xFF;
}

unsigned char read_input()
{
	unsigned char x = -1, y = -1;
	bool c = 1;
	while (1)
	{
		for (unsigned char i = 0; i < 4; i++)
		{
			KEYPAD_PORT &= ~(1 << i);
			KEYPAD_PORT |= (1 << ((i + 3) % 4));
			
			for (unsigned char j = 0; j < 4; j++)
			{
				if ((KEYPAD_PIN & (1 << (j + 4))) == 0)
				{
					while ((KEYPAD_PIN & (1 << (j + 4))) == 0);
					x = i;
					y = j;
					c = 0;
					break;		
				}
			}
			
			if (c == 0)
			{
				init_keypad();
				return KEYPAD[x][y];
			}
			
			_delay_ms(1);
			
		}
	}
}