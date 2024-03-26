/*
 * TimerInt.c
 *
 *  Created on: Mar 23, 2024
 *      Author: OmarMedhat
 */
#include "HAL/HTimer.h"

#define RESET				0X00
#define FREQ_IN_MGH			8
#define TIMER0_NO_COUNTS	256
#define TIMER_10MS			10
#define TIMER_100MS			10
#define TIMER_5S			5000
#define FCPU8				8
#define FCPU256				256
#define FCPU1024			1024
#define CONVERT_MILLISEC_TO_MICRPSEC 1000


static Timer_ConfigType Time0conf ;




HTimer_enumError_t TMR0_enuStart(void)
{
	Timer_enumError_t Loc_ErrorState = HTimer_enumOk;
	Loc_ErrorState = TMR0_enuStart(&Time0conf);
	return Loc_ErrorState;
}
HTimer_enumError_t TMR0_enuSetTickTimeMS(uint16 Copy_u8DesiredTime, uint8 Copy_u8InterruptSource)
{

	Timer_enumError_t Loc_ErrorState = HTimer_enumOk;
	if (Copy_u8InterruptSource != INT_SRC_OVERFLOW &&
			Copy_u8InterruptSource != INT_SRC_COMPARE_MATCH)
	{
		Loc_ErrorState = HTimer_enumWrongConfig;
	}
	else if ( Copy_u8DesiredTime > TIMER_5S)
	{
		Loc_ErrorState = HTimer_enumWrongConfig;
	}
	else
	{
		Time0conf.Timer = Timer0 ;
		Time0conf.Waveform_Generation = Copy_u8InterruptSource ;
		Time0conf.PWMMode = RESET;
		uint16 Loc_Prescaler = 0;
		if (Copy_u8InterruptSource == Over_Flow)
		{

			if (Copy_u8DesiredTime >= TIMER_10MS)
			{
				Time0conf.Prescaler = Fcpu_8 ;/* For Prescaler of clkIO/8 */
				Loc_Prescaler = FCPU8 ;
			}
			else if (Copy_u8DesiredTime >= TIMER_10MS && Copy_u8DesiredTime <= TIMER_100MS)
			{
				Time0conf.Prescaler = Fcpu_256 ;/* For Prescaler of clkIO/256 */
				Loc_Prescaler = FCPU256 ;

			}
			else if (Copy_u8DesiredTime > TIMER_100MS && Copy_u8DesiredTime <= TIMER_5S)
			{
				/* For Prescaler of clkIO/1024 */
				Time0conf.Prescaler = Fcpu_1024 ;
				Loc_Prescaler = FCPU1024 ;
			}
			else
			{/* Do Nothing */}
			uint32 Loc_T_OverFlow = (TIMER0_NO_COUNTS*(Loc_Prescaler))/FREQ_IN_MGH ;
			uint32 Loc_T_Remain= Copy_u8DesiredTime*CONVERT_MILLISEC_TO_MICRPSEC-Loc_T_OverFlow;
			if (Loc_T_OverFlow < Loc_T_Remain)
			{
				Loc_T_Remain = Loc_T_Remain % Loc_T_OverFlow ;
			}
			else{};
			uint32	Loc_T_INTIAL = Loc_T_OverFlow - Loc_T_Remain ;
			uint8 Loc_IntialValue_Result = (uint8)((uint32)(Loc_T_INTIAL*TIMER0_NO_COUNTS)/Loc_T_OverFlow);
			if ((uint8)(((uint32)(Loc_T_INTIAL*TIMER0_NO_COUNTS))%Loc_T_OverFlow)!=0)
			{
				Loc_IntialValue_Result ++;
			}
			else{}

		}
		else
		{

		}


	}



	return Loc_ErrorState;
}
HTimer_enumError_t TMR0_enuSetDutyCycleFastPWM(uint8 Copy_u8DutyCycle, uint8 Copy_u8PWMType)
{
	Timer_enumError_t Loc_ErrorState = HTimer_enumOk;
	//uint8 Loc_DutyCompValue =
	if ((Copy_u8DutyCycle >= 100) || ((Copy_u8PWMType!=INVERTED)&&(Copy_u8PWMType!=NON_INVERTED)) )
	{
		Loc_ErrorState = HTimer_enumWrongConfig ;
	}
	else
	{

	}
	return Loc_ErrorState;
}

HTimer_enumError_t TMR0_enuSetDutyCyclePhaseCorrection(uint8 Copy_u8DutyCycle, uint8 Copy_u8PWMType)
{
	Timer_enumError_t Loc_ErrorState = HTimer_enumOk;
	return Loc_ErrorState;
}
//Over_Flow=0x00 , PWM_Phase_Correct=0xF7 , CTC=0xBF , Fast_PWM=0xFF
//#define	INVERTED 				0x30
//#define NON_INVERTED  			0x20
/*
 *    int result = operand1 / operand2;
    int remainder = operand1 % operand2;

    // Check if there is a fractional part
    if (remainder != 0) {
        // Increment the result by one
        result += 1;
    }
 *
 */
