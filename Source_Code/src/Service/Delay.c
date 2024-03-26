/*
 ============================================================================
 Name        : DELAY.c
 Author      : Omar Medhat Mohamed
 Description : Source file for DELAY
 Date        : 30/12/2023
 ============================================================================
 */
#include "LIB/Delay.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* If Frequency is 1 MHZ*/
#if (F_CPU == 1000000UL)

/**
 * @brief   :  Generates a delay based on a simple loop for a given time in milliseconds.
 * @param   : The desired delay time in milliseconds.
 * @return  : Error State
 * Note: This function is specifically configured for a 1 MHz AVR clock.
 **/
void delay(uint16 time)
{
	uint16 i , j ;
	for (i=0;i<time;i++)
		for(j=0;j<100;j++);
}
/* If Frequency 8 MHZ*/
#elif(F_CPU == 8000000UL)
/**
 * @brief   :  Generates a delay based on a simple loop for a given time in milliseconds.
 * @param   : The desired delay time in milliseconds.
 * @return  : Error State
 * Note: This function is specifically configured for a 8 MHz AVR clock.
 **/
void delay(uint16 time)
{
	volatile uint16 i, j;
	volatile uint16 itr = ((uint16)(F_CPU / 10000UL))/2; ;
    // Adjust the loop counts based on the desired delay time
    for (i = 0; i < time; i++)
        for (j = 0; j <itr ; j++);  // Adjusted for 8 MHz AVR clock
}
#else
#error "Driver not support this F cpu"
#endif
