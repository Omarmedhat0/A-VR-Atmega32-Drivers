/*
 ============================================================================
 Name        : ExternalInterrupt.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the ExternalInterrupt driver
 Date        : 30/12/2023
 ============================================================================
 */
#include "MCAL/ExternalInterrupt.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global variables to hold the address of the call back function in the application */
 static  void (*g_EXINT0_ISR)(void)=NULL ;
 static  void (*g_EXINT1_ISR)(void)=NULL ;
 static  void (*g_EXINT2_ISR)(void)=NULL ;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

/**
 * @brief   : External Interrupt Service Routine for INT0
 **/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (g_EXINT0_ISR != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		g_EXINT0_ISR();
	}
}

/*
 * @brief   : External Interrupt Service Routine for INT1
 **/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (g_EXINT1_ISR != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		g_EXINT1_ISR();
	}
}

/**
 * @brief   : External Interrupt Service Routine for INT2
 **/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (g_EXINT2_ISR != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		g_EXINT2_ISR();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/**
 * @brief   : Function to initiat Pins as external Interrupt
 * @param   : Nothing
 * @return  : Error State
 **/
EXINT_enumError_t EXINT_INIT (void)
{
	/* 
	 * Error status variable for External Interrupt initialization
	 * Initialized to EXINT_enumOk to indicate no error by default
	 */
	EXINT_enumError_t Loc_enumReturnEXINTErrorStatus = EXINT_enumOk;
	/*
	 * Variable to store the value of the MCUCR register for INT0 and INT1
	 * Used for configuring the external interrupt modes for INT0 and INT1
	 */
	uint8 Loc_u8RegValue = MCUCR ;
	/*
	 * Variable to store the value of the MCUCSR register for INT2
	 * Used for configuring the external interrupt mode for INT2
	 */
	uint8 Loc_u8RegValue2 = MCUCSR ;

	/* 
	 * Set the Global Interrupt Enable (I) bit in the Status Register (SREG)
	 * This enables global interrupts for the microcontroller
	 */
	SET_BIT(SREG,7);

	/********************************** For INT0 **********************************/
	/* If INT0_Mode ids Enable */
	#if (INT0_Mode==Enable)
		/* 
		 * Configure control bits (ISC00 & ISC01) related to External Interrupt 0 
		 *(INT0) in the MCU Control Register (MCUCR)
		 * by clearing the corresponding bits using the MCUCR_INT0_MASK mask
		 */
		Loc_u8RegValue &=  MCUCR_INT0_MASK ;
		/*
		 * Set the corresponding pin for External Interrupt 0 (INT0) as an input by 
		 * clearing the Data Direction Register (DDRD)for the specified pin using the CLEAR_BIT macro
		 */
		CLEAR_BIT(DDRD,EXINT_enumPin2);
	/* Check Active status if it was PULL_UP_RESISTOR)*/
	#if (INT0_ACTIVE_STATUS==INTERNAL_PULL_UP_RESISTOR)
		/* 
	     * Set the pin's corresponding bit in the Port D register (PORTD) to enable the internal pull-up resistor 
	     * since the active status for INT0 is configured as INTERNAL_PULL_UP_RESISTOR
	     */
		SET_BIT(PORTD,EXINT_enumPin2);
	/* Check Active status if it was EXTERNAL_PULL_DOWN_RESISTOR)*/
	#elif (INT0_ACTIVE_STATUS==EXTERNAL_PULL_DOWN_RESISTOR)
		/* 
	     * Clear the pin's corresponding bit in the Port D register (PORTD) to enable the external pull-down resistor 
	     *  since the active status for INT0 is configured as EXTERNAL_PULL_DOWN_RESISTOR
	     */
		CLEAR_BIT(PORTD,EXINT_enumPin2);
	#else
	/*
     * Display a preprocessor error message if an invalid configuration for INT0 Active Status is detected
     */
	#error  "Invalid configuration for INT0 Active Status"
	#endif
	/*
	 * Set the bit corresponding to External Interrupt 0 (INT0) in the General Interrupt Control Register (GICR)
	 * using the SET_BIT macro to enable INT0
	 */
	SET_BIT(GICR,6);
	/*
     * Based on the configuration defined for INT0 in MCUCR_INT0_CFG_OUT, set the corresponding bits in Loc_u8RegValue
     */
	/*Case The low level of INT0 generates an interrupt request*/
	#if (MCUCR_INT0_CFG_OUT == MCUCR_INT0_MASK_LOW)
		/* Assign MCUCR_INT0_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT0_MASK_LOW ;
		/* Write the configured value to the MCUCR register to set the mode for INT0*/
		MCUCR = Loc_u8RegValue ;
	/*Case Any logical change on INT0 generates an interrupt request.*/
	#elif(MCUCR_INT0_CFG_OUT==MCUCR_INT0_MASK_CH)
		/* Assign MCUCR_INT0_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT0_MASK_CH ;
		/* Write the configured value to the MCUCR register to set the mode for INT0*/
		MCUCR = Loc_u8RegValue ;
	/*Case The falling edge of INT0 generates an interrupt request.*/
	#elif(MCUCR_INT0_CFG_OUT==MCUCR_INT0_MASK_FE)
		/* Assign MCUCR_INT0_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT0_MASK_FE ;
		/* Write the configured value to the MCUCR register to set the mode for INT0*/
		MCUCR = Loc_u8RegValue ;
	/*Case The rising edge of INT0 generates an interrupt request..*/
	#elif(MCUCR_INT0_CFG_OUT==MCUCR_INT0_MASK_RE)
		/* Assign MCUCR_INT0_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT0_MASK_RE ;
		/* Write the configured value to the MCUCR register to set the mode for INT0*/
		MCUCR = Loc_u8RegValue ;
	#else
 	/* If none of the conditions for INT0 configuration are met, raise a compilation error*/
	#error  "Invalid configuration for INT0"
	#endif
	/*endif For INT0 check if it was enable or not */
	#endif

	/********************************** For INT1 **********************************/
	/* If (INT1_Mode == Enable) */
	#if (INT1_Mode==Enable)
		/* 
		 * Configure control bits (ISC10 & ISC11) related to External Interrupt 1 
		 *(INT1) in the MCU Control Register (MCUCR)
		 * by clearing the corresponding bits using the MCUCR_INT1_MASK mask
		 */
		Loc_u8RegValue &=  MCUCR_INT1_MASK ;
		/*
		 * Set the corresponding pin for External Interrupt 1 (INT01 as an input by 
		 * clearing the Data Direction Register (DDRD)for the specified pin using the CLEAR_BIT macro
		 */
		CLEAR_BIT(DDRD,EXINT_enumPin3);
	/* Check Active status if it was PULL_UP_RESISTOR)*/
	#if (INT1_ACTIVE_STATUS==INTERNAL_PULL_UP_RESISTOR)
		/* 
	     * Set the pin's corresponding bit in the Port D register (PORTD) to enable the internal pull-up resistor 
	     * since the active status for INT0 is configured as INTERNAL_PULL_UP_RESISTOR
	     */
		SET_BIT(PORTD,EXINT_enumPin3);
	/* Check Active status if it was EXTERNAL_PULL_DOWN_RESISTOR)*/
	#elif (INT1_ACTIVE_STATUS==EXTERNAL_PULL_DOWN_RESISTOR)
		/* 
	     * Clear the pin's corresponding bit in the Port D register (PORTD) to enable the external pull-down resistor 
	     *  since the active status for INT0 is configured as EXTERNAL_PULL_DOWN_RESISTOR
	     */
		CLEAR_BIT(PORTD,EXINT_enumPin3);
	#else
	/*
     * Display a preprocessor error message if an invalid configuration for INT0 Active Status is detected
     */
	#error  "Invalid configuration for INT1 Active Status"
	#endif
	/*
	 * Set the bit corresponding to External Interrupt 0 (INT0) in the General Interrupt Control Register (GICR)
	 * using the SET_BIT macro to enable INT0
	 */
	SET_BIT(GICR,7);
	/*
     * Based on the configuration defined for INT1 in MCUCR_INT1_CFG_OUT, set the corresponding bits in Loc_u8RegValue
     */
	/*Case The low level of INT1 generates an interrupt request*/
	#if (MCUCR_INT1_CFG_OUT==MCUCR_INT1_MASK_LOW)
		/* Assign MCUCR_INT1_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT1_MASK_LOW ;
		/* Write the configured value to the MCUCR register to set the mode for INT1*/
		MCUCR = Loc_u8RegValue ;
	/*Case Any logical change on INT1 generates an interrupt request.*/
	#elif(MCUCR_INT1_CFG_OUT==MCUCR_INT1_MASK_CH)
		/* Assign MCUCR_INT1_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT1_MASK_CH ;
		/* Write the configured value to the MCUCR register to set the mode for INT1*/
		MCUCR = Loc_u8RegValue ;
	/*Case The falling edge of INT1 generates an interrupt request.*/
	#elif(MCUCR_INT1_CFG_OUT==MCUCR_INT1_MASK_FE)
		/* Assign MCUCR_INT1_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT1_MASK_FE ;
		/* Write the configured value to the MCUCR register to set the mode for INT1*/
		MCUCR = Loc_u8RegValue ;
	/*Case The rising edge of INT1 generates an interrupt request..*/
	#elif(MCUCR_INT1_CFG_OUT==MCUCR_INT1_MASK_RE)
		/* Assign MCUCR_INT1_MASK for this case in Loc_u8RegValue */
		Loc_u8RegValue |= MCUCR_INT1_MASK_RE ;
		/* Write the configured value to the MCUCR register to set the mode for INT1*/
		MCUCR = Loc_u8RegValue ;
	#else
	/* If none of the conditions for INT1 configuration are met, raise a compilation error*/
	#error  "Invalid configuration for INT1"
	#endif
	/*endif For INT1 check if it was enable or not */
	#endif

	/********************************** For INT2 **********************************/
	/* If (INT2_Mode == Enable) */
	#if (INT2_Mode==Enable)
		/* 
		 * Configure control bit related to External Interrupt 2 
		 *(INT2) in the MCU Control Register (MCUCSR)
		 * by clearing the corresponding bits using the MCUCSR_INT2_MASK mask
		 */
		Loc_u8RegValue2 &=  MCUCSR_INT2_MASK ;
		/*
		 * Set the corresponding pin for External Interrupt 2(INT2) as an input by 
		 * clearing the Data Direction Register (DDRBB)for the specified pin using the CLEAR_BIT macro
		 */
		CLEAR_BIT(DDRB,EXINT_enumPin2);
	/* Check Active status if it was PULL_UP_RESISTOR)*/
	#if (INT2_ACTIVE_STATUS==INTERNAL_PULL_UP_RESISTOR)
		/* 
	     * Set the pin's corresponding bit in the Port B register (PORTB) to enable the internal pull-up resistor 
	     * since the active status for INT2 is configured as INTERNAL_PULL_UP_RESISTOR
	     */
		SET_BIT(PORTB,EXINT_enumPin2);
	#elif (INT2_ACTIVE_STATUS==EXTERNAL_PULL_DOWN_RESISTOR)
		/* 
	     * Clear the pin's corresponding bit in the Port B register (PORTB) to enable the external pull-down resistor 
	     *  since the active status for INT2 is configured as EXTERNAL_PULL_DOWN_RESISTOR
	     */
		CLEAR_BIT(PORTB,EXINT_enumPin2);
	#else
	/*
     * Display a preprocessor error message if an invalid configuration for INT0 Active Status is detected
     */
	#error  "Invalid configuration for INT2 Active Status"
	#endif
	/*
	 * Set the bit corresponding to External Interrupt 2 (INT2) in the General Interrupt Control Register (GICR)
	 * using the SET_BIT macro to enable INT2
	 */
	SET_BIT(GICR,5);
	/*
     * Based on the configuration defined for INT2 in MCUCSR_INT2_CFG_OUT, set the corresponding bits in Loc_u8RegValue2
     */
	/*Case The low level of INT2 generates an interrupt request*/
	#if(MCUCSR_INT2_CFG_OUT==MCUCSR_INT2_MASK_FE)
		/* Assign MCUCSR_INT2_MASK_FE for this case in Loc_u8RegValue2 */
		Loc_u8RegValue2 |= MCUCSR_INT2_MASK_FE ;
		/* Write the configured value to the MCUCSR register to set the mode for INT2*/
		MCUCSR = Loc_u8RegValue2 ;
	/*Case The rising edge of INT2 generates an interrupt request..*/
	#elif(MCUCSR_INT2_CFG_OUT==MCUCSR_INT2_MASK_RE)
		/* Assign MCUCSR_INT2_MASK_FE for this case in Loc_u8RegValue2 */
		Loc_u8RegValue |= MCUCSR_INT2_MASK_RE ;
		/* Write the configured value to the MCUCSR register to set the mode for INT2*/
		MCUCSR = Loc_u8RegValue2 ;
	#else
	/* If none of the conditions for INT0 configuration are met, raise a compilation error*/
	#error  "Invalid configuration for INT2"
	#endif
	/*Enif For INT0 check if it was enable or not */
	#endif
		
	/*
	 * Return the status of External Interrupt initialization
	 */
	return Loc_enumReturnEXINTErrorStatus ;

}

/**
 * @brief   : Set callback function for External Interrupt INT0
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT0_setCallBack(void (*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_EXINT0_ISR = a_ptr;
}

/**
 * @brief   : Set callback function for External Interrupt INT1
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT1_setCallBack(void (*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_EXINT1_ISR = a_ptr;
}

/**
 * @brief   : Set callback function for External Interrupt INT2
 * @param   : a_ptr - Pointer to the callback function
 * @return  : None
 **/
void EXINT2_setCallBack(void (*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_EXINT2_ISR = a_ptr;
}
