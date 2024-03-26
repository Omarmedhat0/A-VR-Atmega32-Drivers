/*
 ============================================================================
 Name        : Task1_main
 Author      : Omar Medhat Mohamed
 Description : Source file for Task1 (Flashing LED on ATmega32)
 Date        : 27/11/2023
 ============================================================================
 */

// Include custom DIO (Digital Input/Output) library
#include "APP/CTRMain.h"
#ifdef LAB1_TASK1
#include "MCAL/DIO.h"

//Delay Function
void delay (uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}

int main()
{
    // Configure pin 2 of port B as an output
    DIO_enumSetPinConfig(DIO_enumPortB, DIO_enumPin2, DIO_enumOutput);

    // Set pin 2 of port B to logic low
    DIO_enumSetPin(DIO_enumPortB, DIO_enumPin2, DIO_enumLogicLow);

    // Infinite loop for LED flashing
    while (1)
    {
        // Set pin 2 of port B to logic high (LED ON)
        DIO_enumSetPin(DIO_enumPortB, DIO_enumPin2, DIO_enumLogicHigh);

        // Delay for 500 milliseconds
        delay(500);
        // Set pin 2 of port B to logic low (LED OFF)
        DIO_enumSetPin(DIO_enumPortB, DIO_enumPin2, DIO_enumLogicLow);

        // Delay for another 500 milliseconds
        delay(500);
    }

    // This point is unreachable as the program is designed to run indefinitely
    return 0;
}
#endif