/*
 ============================================================================
 Name        : ExternalInterrupt_cfg.h
 Author      : Omar Medhat Mohamed
 Description : Header Configuration file for the ExternalInterrupt driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef EXINT_CFG_H_
#define EXINT_CFG_H_

#include "PRIVATE/ExternalInterrupt_private.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NULL ((void*)0)


/*Options :
- The low level of INT0 generates an interrupt request (MCUCR_INT0_MASK_LOW)
- Any logical change on INT0 generates an interrupt request (MCUCR_INT0_MASK_CH)
- The falling edge of INT0 generates an interrupt request (MCUCR_INT0_MASK_FE)
- The rising edge of INT0 generates an interrupt request (MCUCR_INT0_MASK_RE)
*/
#define MCUCR_INT0_CFG_OUT MCUCR_INT0_MASK_FE

/*Options :
- Internal Pull Up Resistor (INTERNAL_PULL_UP_RESISTOR)
- External Pull Down Resistor (EXTERNAL_PULL_DOWN_RESISTOR)
*/
#define INT0_ACTIVE_STATUS INTERNAL_PULL_UP_RESISTOR

/*Options :
- The low level of INT1 generates an interrupt request (MCUCR_INT1_MASK_LOW)
- Any logical change on INT1 generates an interrupt request (MCUCR_INT1_MASK_CH)
- The falling edge of INT1 generates an interrupt request (MCUCR_INT1_MASK_FE)
- The rising edge of INT1 generates an interrupt request (MCUCR_INT1_MASK_RE)
*/
#define MCUCR_INT1_CFG_OUT MCUCR_INT1_MASK_FE
/*Options :
- Internal Pull Up Resistor (INTERNAL_PULL_UP_RESISTOR)
- External Pull Down Resistor (EXTERNAL_PULL_DOWN_RESISTOR)
*/
#define INT1_ACTIVE_STATUS INTERNAL_PULL_UP_RESISTOR

/*Options :
- The falling edge of INT2 generates an interrupt request (MCUCSR_INT2_MASK_FE)
- The rising edge of INT2 generates an interrupt request (MCUCSR_INT2_MASK_RE)
*/
#define MCUCSR_INT2_CFG_OUT MCUCSR_INT2_MASK_FE
/*Options :
- Internal Pull Up Resistor (INTERNAL_PULL_UP_RESISTOR)
- External Pull Down Resistor (EXTERNAL_PULL_DOWN_RESISTOR)
*/
#define INT2_ACTIVE_STATUS INTERNAL_PULL_UP_RESISTOR




#endif
