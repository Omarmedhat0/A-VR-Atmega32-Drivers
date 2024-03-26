#ifndef SRC_HAL_TIMERINT_H_
#define SRC_HAL_TIMERINT_H_
/*******************************************************************************
 *                                Includes		                                *
 *******************************************************************************/
#include "MCAL/Timer.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define INT_SRC_OVERFLOW		Over_Flow
#define INT_SRC_COMPARE_MATCH	CTC
#define	INVERTED 				0x30
#define NON_INVERTED  			0x20
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/**
 *@brief : The Error List Type
 */
typedef enum
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	HTimer_enumOk,
	/**
	 *@brief : NULL Pointer is passed.
	 */
	HTimer_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */
	HTimer_enumWrongPort,
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	HTimer_enumWrongPin,
	/**
	 *@brief : Select Configuration type Not Found .
	 */
	HTimer_enumWrongConfig

}HTimer_enumError_t;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

HTimer_enumError_t TMR0_enuStart(void);
HTimer_enumError_t TMR0_enuSetTickTimeMS(uint8 Copy_u8DesiredTime, uint8 Copy_u8InterruptSource);
HTimer_enumError_t TMR0_enuSetDutyCycleFastPWM(uint8 Copy_u8DutyCycle, uint8 Copy_u8PWMType);
HTimer_enumError_t TMR0_enuSetDutyCyclePhaseCorrection(uint8 Copy_u8DutyCycle, uint8 Copy_u8PWMType);
#endif /* SRC_HAL_TIMERINT_C_ */
