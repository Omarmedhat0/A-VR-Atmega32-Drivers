/*
 ============================================================================
 Name        : LED_cfg.c
 Author      : Omar Medhat Mohamed
 Description : Source Configuration file for the LED driver
 Date        : 12/12/2023
 ============================================================================
 */
#include "CFG/LED_cfg.h"
/* Global array for set configuration for each LED*/
/*Options :
For (.pin): 
{
	LED_enumPIN0 
	LED_enumPIN1  
	LED_enumPIN2 
	LED_enumPIN3 
	LED_enumPIN4 
	LED_enumPIN5 
	LED_enumPIN6 
	LED_enumPIN7 
}
For (.port): 
{
	LED_enumPORTA
	LED_enumPORTB
	LED_enumPORTC
	LED_enumPORTD
}
For (.Active_Status): 
{
	LED_enum_ActiveLow
	LED_enum_ActiveHigh
}
For (.Output_Status): 
{
	LED_enum_Off
	LED_enum_On
}
*/

LED_strCfg LEDS[NUM_OF_LEDS]=
{

[LED1]=
{
.Pin = LED_enumPIN3 ,
.Port= LED_enumPORTC ,
.Active_Status= LED_enum_ActiveLow ,
.Output_Status=LED_enum_Off
}
,
[LED2]=
{
.Pin =LED_enumPIN7 ,
.Port=LED_enumPORTA ,
.Active_Status=LED_enum_ActiveHigh ,
.Output_Status=LED_enum_On
}
,
[LED3]=
{
.Pin =LED_enumPIN0 ,
.Port=LED_enumPORTB ,
.Active_Status=LED_enum_ActiveHigh ,
.Output_Status=LED_enum_On
}

};
