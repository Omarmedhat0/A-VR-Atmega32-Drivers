/*
 ============================================================================
 Name        : Task2_main
 Author      : Omar Medhat Mohamed
 Description : Source file for Task2 (Flashing LED on ATmega32)
 Date        : 27/11/2023
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB1_TASK2
// Include necessary header for delay functions
#include <util/delay.h>

// Include custom DIO (Digital Input/Output) library
#include "MCAL/DIO.h"

int main()
{
	// Configure pins 0-3 of port C as output pins
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin0, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin1, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin2, DIO_enumOutput);
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin3, DIO_enumOutput);

	// Set pins 0-3 of port C to logic low
	DIO_enumSetPin(DIO_enumPortC, DIO_enumPin0, DIO_enumLogicLow);
	DIO_enumSetPin(DIO_enumPortC, DIO_enumPin1, DIO_enumLogicLow);
	DIO_enumSetPin(DIO_enumPortC, DIO_enumPin2, DIO_enumLogicLow);
	DIO_enumSetPin(DIO_enumPortC, DIO_enumPin3, DIO_enumLogicLow);

	// Configure pin 4 of port C as an input with internal pull-up resistor
	DIO_enumSetPinConfig(DIO_enumPortC, DIO_enumPin4, DIO_enumInputInternalPU);

	// Initialize variables
	uint8 Number = 0;
	uint8 Button = DIO_enumLogicHigh;

	// Main loop
	while (1)
	{
		// Read the state of pin 4 of port C into the 'Button' variable
		DIO_enumReadState(DIO_enumPortC, DIO_enumPin4, &Button);

		// Check if the button is pressed (low)
		if (!Button)
		{
			// Delay for debouncing
			DIO_DelayMs(30);

			// Re-check the button state after the delay
			DIO_enumReadState(DIO_enumPortC, DIO_enumPin4, &Button);

			// Check if the button is still pressed
			if (!Button)
			{
				// If 'Number' is already 15, reset it to 0; otherwise, increment it
				if (Number == 15)
				{
					Number = 0;
				}
				else
				{
					Number++;
				}
				/*Rest Pins to zero */
				DIO_enumSetPin(DIO_enumPortC, DIO_enumPin0, DIO_enumLogicLow);
				DIO_enumSetPin(DIO_enumPortC, DIO_enumPin1, DIO_enumLogicLow);
				DIO_enumSetPin(DIO_enumPortC, DIO_enumPin2, DIO_enumLogicLow);
				DIO_enumSetPin(DIO_enumPortC, DIO_enumPin3, DIO_enumLogicLow);
				// Display the lower nibble of 'Number' on pins 0-3 of port C
				if (Number & (1<<DIO_enumPin0))
					DIO_enumSetPin(DIO_enumPortC, DIO_enumPin0, DIO_enumLogicHigh);
				else {}
				if (Number & (1<<DIO_enumPin1))
					DIO_enumSetPin(DIO_enumPortC, DIO_enumPin1, DIO_enumLogicHigh);
				else {}
				if (Number & (1<<DIO_enumPin2))
					DIO_enumSetPin(DIO_enumPortC, DIO_enumPin2, DIO_enumLogicHigh);
				else {}
				if (Number & (1<<DIO_enumPin3))
					DIO_enumSetPin(DIO_enumPortC, DIO_enumPin3, DIO_enumLogicHigh);
				else {}

				// Wait until the button is released before proceeding
				while (!Button)
				{
					// Re-read the button state
					DIO_enumReadState(DIO_enumPortC, DIO_enumPin4, &Button);
				}
			}
		}
	}

	// This point is unreachable as the program is designed to run indefinitely
	return 0;
}
#endif