/*
 ============================================================================
 Name        : Task1_main
 Author      : Omar Medhat Mohamed
 Description : Source file for Task1 Testing LED and Switch driver
 Date        : 13/12/2023
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB3
// Include necessary header for delay functions
#include "HAL/LED.h"
#include "HAL/SWITCH.h"
//Delay Function
void delay (uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}


int main()
{
    /* Call initialization function for LED Driver */
	LED_enumInit();
	 /* Call initialization function for LED Driver */
	SWITCH_enumInit ();
    /* Variable to store the state of switches in them*/
	uint8 switch1 = 0;
	uint8 switch2 = 0;
	uint8 switch3= 0;
    while (1)
    {
    	/*Read Switch value of switch 1*/
    	SWITCH_enumReadValue(SWITCH1,&switch1);
    	if (!switch1)
    	{
    		/*for debouncing handle*/
    		delay(30);
    		SWITCH_enumReadValue(SWITCH1,&switch1);
    		/*Check if switch pressed or not */
    		if (!switch1)
    		{
    			/* Turn on LED1 */
    			LED_enumSetValue(LED1,LED_enumLogicHigh);
    		}
    		while (!switch1)
    		{
    			/*Read Switch value of switch 1*/
    			SWITCH_enumReadValue(SWITCH1,&switch1);
    		}
    		/* Turn off LED1 when switch released */
    		LED_enumSetValue(LED1,LED_enumLogicLow);
    	}

    	/*Read Switch value of switch 2*/
    	SWITCH_enumReadValue(SWITCH2,&switch2);
    	if (switch2)
    	{
    		/*for debouncing handle*/
    		delay(30);
    		SWITCH_enumReadValue(SWITCH2,&switch2);
    		/*Check if switch pressed or not */
    		if (switch2)
    		{
    			/* Turn on LED2 */
    			LED_enumSetValue(LED2,LED_enumLogicHigh);
    		}
    		while (switch2)
    		{
    			/*Read Switch value of switch 2*/
    			SWITCH_enumReadValue(SWITCH2,&switch2);
    		}
    		/* Turn off LED2 when switch released */
    		LED_enumSetValue(LED2,LED_enumLogicLow);
    	}

    	/*Read Switch value of switch 3*/
    	SWITCH_enumReadValue(SWITCH3,&switch3);
    	if (switch3)
    	{
    		/*for debouncing handle*/
    		delay(30);
    		/*Read Switch value of switch 3*/
    		SWITCH_enumReadValue(SWITCH3,&switch3);
    		/*Check if switch pressed or not */
    		if (switch3)
    		{
    			/* Turn on LED3 */
    			LED_enumSetValue(LED3,LED_enumLogicHigh);
    		}
    		while (switch3)
    		{
    			/*Check if switch pressed or not */
    			SWITCH_enumReadValue(SWITCH3,&switch3);
    		}
    		/* Turn off LED3 when switch released */
    		LED_enumSetValue(LED3,LED_enumLogicLow);
    	}
    }

    // This point is unreachable as the program is designed to run indefinitely
    return 0;
}
#endif