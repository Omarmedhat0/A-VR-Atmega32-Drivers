/*
 * Include necessary header files
 */
#include "APP/CTRMain.h"
#ifdef LAB5_TASK1
#include 	"HAL/SevenSegment.h"
#include  	"MCAL/ExternalInterrupt.h"

/* Global variable to hold the interrupt flag */
uint8 g_Interrupt_Flag = 0 ;

/*
 * Prototype for functions which will be send by callback function to ExternalInterrupt
 */
void Seg7_Display_Increment(void);
void Seg7_Display_Decrement(void);


int main(void)
{
	/*
	 * Seven Segment initialization
	 */
	EXINT_INIT();
	/*
	 * External Interrupt initialization
	 */
	SevenSegment_enumInit();

	/*
	 * Set callback functions for External Interrupts
	 */
	EXINT0_setCallBack(Seg7_Display_Increment) ;
	EXINT1_setCallBack(Seg7_Display_Decrement) ;
	while (1)
	{
		/*
		 * Main loop to continuously display the interrupt flag on Seven Segment
		 */
		SevenSegment_enumSetValueForAll(g_Interrupt_Flag);
	}


	return 0 ;
}


/**
 * @brief   :Increment the global interrupt flag for Seven Segment display
 * 			 Reset to 0 if it reaches the maximum value (99).
 * @param   : None
 * @return  : None
 **/
void Seg7_Display_Increment(void)
{
	/* Reset to 0 if it reaches the maximum value (99).*/
	if (g_Interrupt_Flag==99)
	{
		g_Interrupt_Flag = 0;
	}
	/*Increment the global interrupt flag By One*/
	else
	{
		g_Interrupt_Flag ++ ;
	}

}

/**
 * @brief   :Decrement the global interrupt flag for Seven Segment display
 * @param   : None
 * @return  : None
 **/
void Seg7_Display_Decrement(void)
{	/*Decrement the global interrupt flag By One if it not equal to zero*/
	if (g_Interrupt_Flag != 0)
	{
		g_Interrupt_Flag --;
	}
	else
	{
		  /*Do nothing if already at the minimum value*/
	}

}

#endif