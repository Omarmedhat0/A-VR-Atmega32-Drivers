/*
 ============================================================================
 Name        : Digital_Timer_Design.c
 Author      : Omar Medhat Mohamed
 Description : Source file for Digital Timer Design
 Date        : 18/12/2023
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB4_TASK2
#include "APP/Digital_Timer_Design.h"
/*********Declare Timer Counter Global Variable*********/
uint8 g_u8TimerCurrentValue = 0 ;

int main(void)
{
	/*********Declare Status Of Switches Variables*********/
	uint8 Loc_u8SwitchStatus1 =0 ;
	uint8 Loc_u8SwitchStatus2 =0 ;
	uint8 Loc_u8SwitchStatus3 =0 ;

	/******** Initiate Required Drivers ********/
	SWITCH_enumInit ();
	LED_enumInit ();
	SevenSegment_enumInit ();
	while(1)
	{
		/* Handle if the Timer Reach to a number by negative value or above 99 seconds to reset to Zero Again*/
		if ((g_u8TimerCurrentValue <0 ) || (g_u8TimerCurrentValue > 99) )
		{

			g_u8TimerCurrentValue =0 ;
		}
		/*Read Switch value of switch 1
		 * Functionality : Increment  the counter by One
		 * */
		SWITCH_enumReadValue(SWITCH1,&Loc_u8SwitchStatus1);
		if (!Loc_u8SwitchStatus1)
		{
			/*for debouncing handle*/
			delay(30);
			SWITCH_enumReadValue(SWITCH1,&Loc_u8SwitchStatus1);
			/*Check if switch pressed or not */
			if (!Loc_u8SwitchStatus1)
			{
				/*Increment  the counter by One*/
				g_u8TimerCurrentValue ++;
				/*Print the value on Seven Segment*/
				SevenSegment_enumSetValueForAll(g_u8TimerCurrentValue);

			}
			while (!Loc_u8SwitchStatus1)
			{
				/*Read Switch value of switch 1*/
				SWITCH_enumReadValue(SWITCH1,&Loc_u8SwitchStatus1);
			}
		}


		/*Read Switch value of switch 2
		 * Functionality : Decrement  the counter by One
		 * */
		SWITCH_enumReadValue(SWITCH2,&Loc_u8SwitchStatus2);
		if (!Loc_u8SwitchStatus2)
		{
			/*for debouncing handle*/
			delay(30);
			SWITCH_enumReadValue(SWITCH2,&Loc_u8SwitchStatus2);
			/*Check if switch pressed or not */
			if (!Loc_u8SwitchStatus2)
			{
				 /*Decrement  the counter by One*/
				g_u8TimerCurrentValue --;
				/*Print the value on Seven Segment*/
				SevenSegment_enumSetValueForAll(g_u8TimerCurrentValue);
			}
			while (!Loc_u8SwitchStatus2)
			{
				/*Read Switch value of switch 1*/
				SWITCH_enumReadValue(SWITCH2,&Loc_u8SwitchStatus2);
			}
		}

		/*Read Switch value of switch 3
		 * Functionality : Initiate The timer and flash the LED when it ends
		 * */
		SWITCH_enumReadValue(SWITCH3,&Loc_u8SwitchStatus3);
		if (!Loc_u8SwitchStatus3)
		{
			/*for debouncing handle*/
			delay(30);
			SWITCH_enumReadValue(SWITCH3,&Loc_u8SwitchStatus3);
			/*Check if switch pressed or not */
			if (!Loc_u8SwitchStatus3)
			{
				/* Decrement  the counter by One every 1 Sec*/
				while(g_u8TimerCurrentValue > 0 )
				{
					SevenSegment_enumSetValueForAll(g_u8TimerCurrentValue);
					g_u8TimerCurrentValue --;
					delay(1000);
				}
				/*Print the value on Seven Segment*/
				SevenSegment_enumSetValueForAll(g_u8TimerCurrentValue);
				/*Flash LED 3 Times*/
				LED_enumSetLedState(ALARM_LED,LED_enumLogicHigh);
				delay(500);
				LED_enumSetLedState(ALARM_LED,LED_enumLogicLow);
				delay(500);
				LED_enumSetLedState(ALARM_LED,LED_enumLogicHigh);
				delay(500);
				LED_enumSetLedState(ALARM_LED,LED_enumLogicLow);
				delay(500);
				LED_enumSetLedState(ALARM_LED,LED_enumLogicHigh);
				delay(500);
				LED_enumSetLedState(ALARM_LED,LED_enumLogicLow);
				delay(500);
			}
			while (!Loc_u8SwitchStatus3)
			{
				/*Read Switch value of switch 1*/
				SWITCH_enumReadValue(SWITCH3,&Loc_u8SwitchStatus3);
			}
		}
		/*Print the value on Seven Segment*/
		SevenSegment_enumSetValueForAll(g_u8TimerCurrentValue);
	}
	return 0 ;
}

/*********Delay Function*********/
void delay (uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}
#endif