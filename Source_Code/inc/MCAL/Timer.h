/******************************************************************************
 * Module: Timer
 *
 * File Name : timer.h
 *
 * Description: Header file for the ATmega16 Timer driver
 *
 * Author: Omar Medhat
 ******************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_
#include "LIB/common_macros.h" /* To use the macros like SET_BIT */
#include "LIB/std_types.h"
#include "LIB/Reg_Add.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum//Timer ID to choose which timer will be dealed with
{
	Timer0,Timer1_CHA,Timer1_CHB,Timer2
}Timer_ID;

typedef enum //Clock(Prescaler) select the first row compatible with timer0 , timer 1 and the second compatible with timer2
{
	Stop_clock=0, Fcpu_1=1, Fcpu_8=2, Fcpu_64=3, Fcpu_256=4, Fcpu_1024=5, Clock_on_falling=6, Clock_on_rising=7,
	Fcpu_1_t2=1,Fcpu_8_t2=2,Fcpu_32_t2=3,Fcpu_64_t2=4,Fcpu_128_t2=5,Fcpu_256_t2=6,Fcpu_1024_t2=7

}Clock_Select;

typedef enum//Choose Mode to init the timer with
{
	Over_Flow=0x00 , PWM_Phase_Correct=0xF7 , CTC=0xBF , Fast_PWM=0xFF
}Waveform_Generation_Mode;
typedef enum//Choose Mode to init the timer with
{
	INVERTED = 0x30 , NON_INVERTED = 0x20
}PWM_Mode;
//structure that will be send to configure timer module
typedef struct
{
	Timer_ID 					Timer;
	uint16						Initial_value;
	uint16						Compare_value;
	Waveform_Generation_Mode	Waveform_Generation;
	PWM_Mode					PWMMode;
	Clock_Select				Prescaler;

}Timer_ConfigType;
/**
 *@brief : The Error List Type                                           
 */
typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	Timer_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	Timer_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	Timer_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	Timer_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	Timer_enumWrongConfig    

}Timer_enumError_t;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Description :
 * Initialization the timer module
 * Select which timer that wanted to be used
 */
Timer_enumError_t Timer_init(const Timer_ConfigType * Config_Ptr);

Timer_enumError_t TMR0_enuStart(const Timer_ConfigType *Config_Ptr) ;

/*
 * Description: Function to set the Call Back function address for timer 0.
 */
Timer_enumError_t Timer0_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to disable the Timer0 to stop the Timer Driver
 */
Timer_enumError_t Timer0_diinit(void);


/*
 * Description: Function to set the Call Back function address for timer 1.
 */
Timer_enumError_t Timer1_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to disable the Timer10 to stop the Timer Driver
 */
Timer_enumError_t Timer1_diinit(void);


/* Description :
 * Initialization Timer2 function with specification with Compare Mode or Overflow Mode
 */
Timer_enumError_t Timer2_setCallBack(void(*a_ptr)(void));

/*
 * Description: Function to disable the Timer2 to stop the Timer Driver
 */
Timer_enumError_t Timer2_diinit(void);


#endif /* TIMER_H_ */
