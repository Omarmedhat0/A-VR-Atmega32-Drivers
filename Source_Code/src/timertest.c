/*
 * timertest.c
 *
 *  Created on: Mar 23, 2024
 *      Author: OmarMedhat
 */

#ifndef TIMERTEST
#define TIMERTEST
#include <HAL/HTimer.h>
#include "APP/CTRMain.h"
void ledon(void)
{
	static uint8 g_tick ;
	g_tick++;
	if(g_tick == 123)
	{
		PORTC |= 0x01;
	}
}
Timer_ConfigType Time0conf = { Timer0 , 0 , 255 , CTC , 0 , Fcpu_256 };
int main()
{
	DDRC  |= 0x01;     // Configure the first four pins in PORTC as output pins.
	PORTC &= 0x00;     // Initialize the 7-seg display zero at the beginning.
	SREG  |= (1<<7);   // Enable global interrupts in MC.
	Timer0_setCallBack(ledon);
	Timer0_init (&Time0conf);
	TMR0_enuStart();
	while(1)
	{

	}

}
#endif
