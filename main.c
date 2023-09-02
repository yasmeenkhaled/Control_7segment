#define F_CPU (16000000UL)
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"

void SEVEN_SEG_voidInit(void){
	SET_BIT(DDRC,3);
	DDRD |= 0b00010111;
}
void SEVEN_SEG_voidDisplay(int number){
	PORTD &=0b11101000;
	PORTD |= (((number & 0b00001000) << 1 ) | (number & 0b0000111));
}
void push_button_sw1(void){
	SET_BIT(DDRD,2);
	CLR_BIT(PORTD,2);
	
	CLR_BIT(DDRA,1);
	SET_BIT(PORTA,1);
}
void push_button_sw2(void){
	SET_BIT(DDRD,2);
	CLR_BIT(PORTD,2);
	
	CLR_BIT(DDRA,0);
	SET_BIT(PORTA,0);
}

int main(void)
{
	int count = 0;
		push_button_sw1();
		push_button_sw2();
		SEVEN_SEG_voidInit();
	
	while(1)
	{
		if (GET_BIT(PINA,1) == 0)
		{
			_delay_ms(150);
			if (GET_BIT(PINA,1) == 0)
			{
			if (count < 9)
			{
				count++;
				SEVEN_SEG_voidDisplay(count%10);
				
			}
		}
		}
		if (GET_BIT(PINA,0) == 0)
		{
			_delay_ms(150);
			if (GET_BIT(PINA,0) == 0)
			{
			if (count > 0)
			{
				count--;
				SEVEN_SEG_voidDisplay(count%10);
				
			}
			}
		}
		
	}
}

