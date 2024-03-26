/*
 ============================================================================
 Name        : PORT.h
 Author      : Omar Medhat Mohamed
 Description : Header File for the PORT driver
 Date        : 3/12/2023
 ============================================================================
 */
#ifndef PORT_H_H_
#define PORT_H_H_
#include "CFG/PORT_cfg.h"
/*Configuration Array deleration*/
/*Set global array whice will be used*/
extern PORT_enumpinopt_t PORT_PINcfg [TOTAL_NUMBER_OF_PINS];
		
/**
 @brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin and tc configure them by PrE or POST Configuration.
 @param  : Nothing
 @return : Nothing                                               
 */	
void Int_PORT(void);
#endif
