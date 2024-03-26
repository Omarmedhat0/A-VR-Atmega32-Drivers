/*
 ============================================================================
 Name        : SWITCH_cfg.c
 Author      : Omar Medhat Mohamed
 Description : Source Configuration file for the SWITCH driver
 Date        : 12/12/2023
 ============================================================================
 */
#include "CFG/SWITCH_Cfg.h"
/* Global array for set configuration for each SWITCH*/
/*Options :
For (.pin): 
{
	SWITCH_enumPIN0 
	SWITCH_enumPIN1  
	SWITCH_enumPIN2 
	SWITCH_enumPIN3 
	SWITCH_enumPIN4 
	SWITCH_enumPIN5 
	SWITCH_enumPIN6 
	SWITCH_enumPIN7 
}
For (.port): 
{
	SWITCH_enumPORTA
	SWITCH_enumPORTB
	SWITCH_enumPORTC
	SWITCH_enumPORTD
}
For (.Active_Status): 
{
	SWITCH_enum_PullUpRes
	SWITCH_enum_ExternalPullDown
}

*/

SWITCH_strCfg SWITCHS[NUM_OF_SWITCHS]=
{

[SWITCH1]=
{
.Pin = SWITCH_enumPIN2 ,
.Port= SWITCH_enumPORTC ,
.Active_Status= SWITCH_enum_PullUpRes
}
,
[SWITCH2]=
{
.Pin =SWITCH_enumPIN6 ,
.Port=SWITCH_enumPORTA ,
.Active_Status=SWITCH_enum_ExternalPullDown
}
,
[SWITCH3]=
{
.Pin =SWITCH_enumPIN1 ,
.Port=SWITCH_enumPORTB ,
.Active_Status=SWITCH_enum_ExternalPullDown
}

};
