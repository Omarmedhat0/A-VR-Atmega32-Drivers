/*
 ============================================================================
 Name        : Task1_main
 Author      : Omar Medhat Mohamed
 Description : Source file for Task1 (Flashing LED on ATmega32) ((POST Compile Configuration))
 Date        : 3/12/2023
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB2_TASK1
// Include necessary header for delay functions
// Include custom DIO (Digital Input/Output) library
#include "MCAL/DIO.h"
#include "MCAL/PORT.h"
#include "CFG/PORT_cfg.h"
/*Configuration Array deleration*/

//Delay Function
void delay (uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}


int main()
{
    /*(POST Compile Configuration)*/
	Int_PORT();
    // Infinite loop for LED flashing
    while (1)
    {
        /*Change Pin2 In PORTB status to HIGH*/
    	for (int i=0 ; i<(NUM_OF_PINS*NUM_OF_PORTS) ; i++)
    	{
    		if (((i/NUM_OF_PINS)==PORT_B)&&((i%NUM_OF_PINS)==DIO_enumPin2))
    		{
    			PORT_PINcfg[i]=PORT_enumOUTPUT_HIGH;
    		}

    	}
		 Int_PORT();
        // Delay for 500 milliseconds
        delay(500);
        /*Change Pin2 In PORTB status to LOW*/
    	for (int i=0 ; i<(FOUR_PORTS*EIGHT_PINS); i++)
    	{
    		if (((i/NUM_OF_PINS)==PORT_B)&&((i%NUM_OF_PINS)==DIO_enumPin2))
    		{
    			PORT_PINcfg[i]=PORT_enumOUTPUT_LOW;
    		}

    	}
   		 Int_PORT();
        // Delay for another 500 milliseconds
        delay(500);
    }

    // This point is unreachable as the program is designed to run indefinitely
    return 0;
}
#endif