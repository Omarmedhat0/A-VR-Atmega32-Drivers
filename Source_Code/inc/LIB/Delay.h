/*
 ============================================================================
 Name        : DELAY.h
 Author      : Omar Medhat Mohamed
 Description : Header file for the DELAY driver
 Date        : 30/12/2023
 ============================================================================
 */
#ifndef DELAY_H_
#define DELAY_H_
/*******************************************************************************
 *                                Includes	                                  *
 *******************************************************************************/
#include  	"std_types.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/**
 * @brief   :  Generates a delay based on a simple loop for a given time in milliseconds.
 * @param   : The desired delay time in milliseconds.
 * @return  : Error State
 **/
void delay(uint16 time) ;

#endif /* DELAY_H_ */
