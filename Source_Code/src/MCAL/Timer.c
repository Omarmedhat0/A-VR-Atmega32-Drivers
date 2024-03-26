/******************************************************************************
 * Module: Timer
 *
 * File Name : timer.c
 *
 * Description: Source file for the ATmega16 Timer driver
 *
 * Author: Omar Medhat
 ******************************************************************************/
#include "MCAL/Timer.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define I_BIT						7
#define RESET 						0
#define TIMER0_PRE_SCALER_CLR_MASK 0xF8
#define TIMER0_MODE_CLR_MASK 0XB7
#define TIMER0_SET_OVER_FLOW_MODE 0X00
#define TIMER0_SET_CTC_MODE 0X40
#define TIMER0_INTR_CLR_MASK 0xFC
#define TIMER0_INTR_ENB_OVR_MASK 0x01
#define TIMER0_INTR_ENB_CMP_MASK 0x02
#define TIMER0_PWM_INV_MODE_CLR_MASK 0XCF
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application for timer 0 */
static volatile void (*g_callBackPtr0)(void) = NULL_PTR;
/* Global variables to hold the address of the call back function in the application for timer 1 */
static volatile void (*g_callBackPtr1)(void) = NULL_PTR;
/* Global variables to hold the address of the call back function in the application for timer 2 */
static volatile void (*g_callBackPtr2)(void) = NULL_PTR;
/*******************************************************************************
 *                         Static Function Prototypes		                   *
 *******************************************************************************/
//static Timer_enumError_t Timer1_init(const Timer_ConfigType *Config_Ptr);
//static Timer_enumError_t Timer2_init(const Timer_ConfigType *Config_Ptr);
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
// Interrupt Service Routine for timer 0 Overflow Mode
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (g_callBackPtr0 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr0)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 0 Compare Mode
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (g_callBackPtr0 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr0)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 1 Overflow Mode
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if (g_callBackPtr1 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr1)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 1 Compare Mode Channel A
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if (g_callBackPtr1 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr1)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 1 Compare Mode Channel B
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if (g_callBackPtr1 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr1)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 2 Compare Mode
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	if (g_callBackPtr2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
// Interrupt Service Routine for timer 2 Compare Mode
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if (g_callBackPtr2 != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr2)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* Description :
 * Initialization the timer module
 * Select which timer that wanted to be used
 */
Timer_enumError_t Timer_init(const Timer_ConfigType *Config_Ptr)
{
	Timer_enumError_t Loc_ErrorState = Timer_enumOk;
	if ((Config_Ptr->Timer) == Timer0) // Select Timer 0
	{
		Timer0_init(Config_Ptr);
	}
//	else if (((Config_Ptr->Timer) == Timer1_CHA) | ((Config_Ptr->Timer) == Timer1_CHB)) // Select Timer 1 and which channel needs to work on
//	{
//		Timer1_init(Config_Ptr);
//	}
//	else if ((Config_Ptr->Timer) == Timer2) // Select Timer 2
//	{
//		Timer2_init(Config_Ptr);
//	}

	return Loc_ErrorState;
}

/* Description :
 * Initialization Timer0 function with specification with Compare Mode or Overflow Mode
 */

 Timer_enumError_t Timer0_init(const Timer_ConfigType *Config_Ptr)
{
	Timer_enumError_t Loc_ErrorState = Timer_enumOk;
	uint8 Loc_TCCR0_Value = TCCR0;
	uint8 Loc_TIMS0_Value = TIMSK;
	uint8 Loc_TIMS_Temp = 0;
	if (Config_Ptr == NULL_PTR)
	{
		Loc_ErrorState = Timer_enumNullPointer;
	}
	else
	{

		if (GET_BIT(SREG, I_BIT) == RESET)
		{
			SET_BIT(SREG, I_BIT);
		}
		/* Configure the timer control register*/
		// Set The required Timer initial value in TCNT0 Registers
		TCNT0 = Config_Ptr->Initial_value;
		// Set The required Timer Compare value in compare mode in OCR0 Registers
		OCR0 = Config_Ptr->Compare_value;
		/*************************** Configure TCCR0 register***************************/
		Loc_TCCR0_Value = (Loc_TCCR0_Value & TIMER0_MODE_CLR_MASK) | (Config_Ptr->Waveform_Generation);
		/*************************** Configure TIMSK register***************************/
		if (Config_Ptr->Waveform_Generation == Over_Flow || Config_Ptr->Waveform_Generation == CTC)
		{
			Loc_TIMS_Temp = (Config_Ptr->Waveform_Generation == Over_Flow) ? TIMER0_INTR_ENB_OVR_MASK : TIMER0_INTR_ENB_CMP_MASK;
			Loc_TIMS0_Value = (Loc_TIMS0_Value & TIMER0_INTR_CLR_MASK) | Loc_TIMS_Temp;
			TIMSK = Loc_TIMS0_Value;
		}
		else if (Config_Ptr->Waveform_Generation == PWM_Phase_Correct || Config_Ptr->Waveform_Generation == Fast_PWM)
		{
			Loc_TCCR0_Value = (Loc_TCCR0_Value & TIMER0_PWM_INV_MODE_CLR_MASK) | Config_Ptr->PWMMode;
		}
		else
		{Loc_ErrorState = Timer_enumWrongConfig ;}
	}
	CLEAR_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	TCCR0 = Loc_TCCR0_Value;
	return Loc_ErrorState;
}



/*
 * Description: Function to set the Call Back function address for timer 0.
 */
Timer_enumError_t Timer0_setCallBack(void (*a_ptr)(void))

{
	Timer_enumError_t Loc_ErrorState = Timer_enumOk;
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr0 = a_ptr;
	return Loc_ErrorState;
}

// /*
//  * Description: Function to disable the Timer0 to stop the Timer Driver
//  */
// Timer_enumError_t Timer0_diinit(void)
// {
// 	TCNT0 = 0;
// 	OCR0 = 0;
// 	TCCR0 = 0;
// 	TIMSK = 0;
// }

// /* Description :
//  * Initialization Timer1 function with specification with Compare Mode or Overflow Mode and configure channels
//  */
// static Timer_enumError_t Timer1_init(const Timer_ConfigType *Config_Ptr)
// {
// 	/* Configure the timer control registesr*/

// 	// Set The required Timer initial value in TCNT1 Registers for both channels
// 	TCNT1 = Config_Ptr->Initial_value;

// 	// Insert the required Clock Select Prescaler through COM10:2 BITS
// 	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->Prescaler);

// 	/*Description
// 	 * Set The required Timer Compare value in compare mode for both channels
// 	 * Adjust TCCR1A and TCCR1B  Register
// 	 * Insert the required Compare Output mode
// 	 * Enabled Interrupt for Overflow or Compare mode as required
// 	 */

// 	if ((Config_Ptr->Timer) == Timer1_CHA) // Setup Channel A in timer 1
// 	{

// 		SET_BIT(TCCR1A, FOC1A); // Non PWM mode FOC1A=1,FOC1B=1
// 		SET_BIT(TCCR1A, FOC1B);

// 		// To set Compare Output and waveform mode In case of Overflow Mode
// 		if ((Config_Ptr->Waveform_Generation) == Over_Flow)
// 		{
// 			// Insert the required Waveform Generation mode which is overflow at this case
// 			CLEAR_BIT(TCCR1A, WGM10);
// 			CLEAR_BIT(TCCR1A, WGM11);
// 			CLEAR_BIT(TCCR1B, WGM12);
// 			CLEAR_BIT(TCCR1B, WGM13);
// 			// Insert the required Compare Output mode
// 			//  Reset Bit COM1A0 & COM1A1
// 			/*CLEAR_BIT(TCCR1A,COM1A0);
// 			CLEAR_BIT(TCCR1A,COM1A1);*/
// 			SET_BIT(TIMSK, TOIE1); // Enabled Interrupt
// 		}
// 		// To set Compare Output mode and waveform in case of Compare Mode
// 		else if ((Config_Ptr->Waveform_Generation) == Compare)
// 		{
// 			OCR1A = Config_Ptr->Compare_value; // Compare value for channel A
// 			// Insert the required Waveform Generation mode which is compare at this case
// 			CLEAR_BIT(TCCR1A, WGM10);
// 			CLEAR_BIT(TCCR1A, WGM11);
// 			SET_BIT(TCCR1B, WGM12);
// 			CLEAR_BIT(TCCR1B, WGM13);
// 			// Insert the required Compare Output mode
// 			//  SET Bit COM1A0 & COM1A1
// 			/*SET_BIT(TCCR1A,COM1A0);
// 			SET_BIT(TCCR1A,COM1A1);*/
// 			SET_BIT(TIMSK, OCIE1A); // Enabled Interrupt
// 		}
// 	}
// 	else if ((Config_Ptr->Timer) == Timer1_CHB) // Setup Channel B in timer 1
// 	{

// 		SET_BIT(TCCR1A, FOC1B); // Non PWM mode FOC1A=1,FOC1B=1
// 		SET_BIT(TCCR1A, FOC1A);

// 		// To set Compare Output and waveform mode In case of Overflow Mode
// 		if ((Config_Ptr->Waveform_Generation) == Over_Flow)
// 		{
// 			// Insert the required Waveform Generation mode through WGM10:3 BITS
// 			CLEAR_BIT(TCCR1A, WGM10);
// 			CLEAR_BIT(TCCR1A, WGM11);
// 			CLEAR_BIT(TCCR1B, WGM12);
// 			CLEAR_BIT(TCCR1B, WGM13);
// 			// Insert the required Compare Output mode
// 			//  Reset Bit COM1B0 & COM1B1
// 			/*CLEAR_BIT(TCCR1A,COM1B0);
// 			CLEAR_BIT(TCCR1A,COM1B1);*/
// 			SET_BIT(TIMSK, TOIE1); // Enabled Interrupt
// 		}
// 		// To set Compare Output and waveform mode In case of Compare Mode
// 		else if ((Config_Ptr->Waveform_Generation) == Compare)
// 		{
// 			OCR1B = Config_Ptr->Compare_value; // Compare value for channel B
// 			// Insert the required Waveform Generation mode through WGM10:3 BITS
// 			CLEAR_BIT(TCCR1A, WGM10);
// 			CLEAR_BIT(TCCR1A, WGM11);
// 			SET_BIT(TCCR1B, WGM12);
// 			CLEAR_BIT(TCCR1B, WGM13);
// 			// Insert the required Compare Output mode
// 			//  SET Bit COM1B0 & COM1B1
// 			/*SET_BIT(TCCR1A,COM1B0);
// 			SET_BIT(TCCR1A,COM1B1);*/
// 			SET_BIT(TIMSK, OCIE1B); // Enabled Interrupt
// 		}
// 	}
// }

// /*
//  * Description: Function to set the Call Back function address for timer 1.
//  */
// Timer_enumError_t Timer1_setCallBack(void (*a_ptr)(void))
// {
// 	/* Save the address of the Call back function in a global variable */
// 	g_callBackPtr1 = a_ptr;
// }

// /*
//  * Description: Function to disable the Timer1 to stop the Timer Driver
//  */
// Timer_enumError_t Timer1_diinit(void)
// {
// 	TCNT1 = 0;
// 	OCR1A = 0;
// 	OCR1B = 0;
// 	TCCR1A = 0;
// 	TCCR1B = 0;
// 	TIMSK = 0;
// }

// /* Description :
//  * Initialization Timer2 function with specification with Compare Mode or Overflow Mode
//  */
// static Timer_enumError_t Timer2_init(const Timer_ConfigType *Config_Ptr)

// {
// 	/* Configure the timer control registesr*/

// 	// Set The required Timer initial value in TCNT2 Registers
// 	TCNT2 = Config_Ptr->Initial_value;

// 	// Set The required Timer Compare value in compare mode in OCR2 Registers
// 	OCR2 = Config_Ptr->Compare_value;

// 	/*************************** Configure TCCR0 register***************************/
// 	// Non PWM mode FOC2=1
// 	SET_BIT(TCCR2, FOC2);

// 	// Insert the required Waveform Generation mode through WGM20:1 BITS
// 	TCCR2 = (TCCR2 & 0xBF) | (((Config_Ptr->Waveform_Generation) & 0x01) << 6);
// 	TCCR2 = (TCCR2 & 0xF7) | (((Config_Ptr->Waveform_Generation) & 0x02) << 2);

// 	// Insert the required Clock Select Prescaler through COM20:2 BITS
// 	TCCR2 = (TCCR2 & 0xF8) | (Config_Ptr->Prescaler);

// 	// Insert the required Compare Output mode through COM20:1 BITS
// 	// Enabled Interrupt for Overflow or Compare mode as required
// 	if ((Config_Ptr->Waveform_Generation) == Over_Flow) // Overflow mode
// 	{
// 		CLEAR_BIT(TCCR2, COM20);
// 		CLEAR_BIT(TCCR2, COM21);
// 		SET_BIT(TIMSK, TOIE2);
// 	}
// 	else if ((Config_Ptr->Waveform_Generation) == Compare) // compare mode
// 	{
// 		CLEAR_BIT(TCCR2, COM20);
// 		CLEAR_BIT(TCCR2, COM21);
// 		SET_BIT(TIMSK, OCIE2);
// 	}
// }

// /*
//  * Description: Function to set the Call Back function address for timer 2.
//  */
// Timer_enumError_t Timer2_setCallBack(void (*a_ptr)(void))
// {
// 	/* Save the address of the Call back function in a global variable */
// 	g_callBackPtr2 = a_ptr;
// }

// /*
//  * Description: Function to disable the Timer2 to stop the Timer Driver
//  */
// Timer_enumError_t Timer2_diinit(void)
// {
// 	TCNT2 = 0;
// 	OCR2 = 0;
// 	TCCR2 = 0;
// 	TIMSK = 0;
// }
