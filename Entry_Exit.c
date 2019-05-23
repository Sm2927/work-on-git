/*Use PC0 for sensor and LED PB1 and PB2 for
LED Connection.
*/

#include <avr/io.h>
#include <util/delay.h>

void pb1(void);
void pb12(void);
void pb4(void);
void pb14(void);

int main (void)
{
	int x, y, number = 0;
	DDRB = 0b11111111;
	DDRC = 0b00000000;
	DDRD = 0b11111111;
	while(1)
	{
		x = PINC & 0b00000001;
		y = PINC & 0b00000010;
		while(x == 1)
		{
			x = PINC & 0b00000001;
			if(x == 0)
				number++;
		}
		while(y == 2)
		{
			y = PINC & 0b00000010;
			if(y == 0)
				number--;
		}	
		if(number < 0 || number>15)
			PORTD=0b00000010;
		PORTB = number;
	}
}
