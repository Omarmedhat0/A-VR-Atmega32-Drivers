/*
 ============================================================================
 Name        : EXINT_private.h
 Author      : Omar Medhat Mohamed
 Description : Header private file for the ExternalInterrupt driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef EXINT_PRIVATE_H_
#define EXINT_PRIVATE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*************************** MCUCR Masks for INT0 ***************************/
#define MCUCR_INT0_MASK 0xFC
#define MCUCR_INT0_MASK_LOW 0x00
#define MCUCR_INT0_MASK_CH 0x01
#define MCUCR_INT0_MASK_FE 0x02
#define MCUCR_INT0_MASK_RE 0x03

/*************************** MCUCR Masks for INT1 ***************************/
#define MCUCR_INT1_MASK 0xF3
#define MCUCR_INT1_MASK_LOW 0x00
#define MCUCR_INT1_MASK_CH 0x04
#define MCUCR_INT1_MASK_FE 0x08
#define MCUCR_INT1_MASK_RE 0x0C

/*************************** MCUCSR Masks for INT2 ***************************/
#define MCUCSR_INT2_MASK 0xBF
#define MCUCSR_INT2_MASK_FE 0x00
#define MCUCSR_INT2_MASK_RE 0x40

/*************************** Active Status ***************************/
#define INTERNAL_PULL_UP_RESISTOR	0x00
#define EXTERNAL_PULL_DOWN_RESISTOR	0x01
#define Enable 1
#define Disable 0


#endif
