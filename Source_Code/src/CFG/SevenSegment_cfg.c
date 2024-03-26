/*
 ============================================================================
 Name        : SevenSegment_cfg.c
 Author      : Omar Medhat Mohamed
 Description : Source Configuration file for the SevenSegment driver
 Date        : 18/12/2023
 ============================================================================
 */

#include "CFG/SevenSegment_Cfg.h"
/* Global array for set configuration for each SevenSegment*/
/*Options :
For (.pin): 
{
	SevenSegment_enumPIN0 
	SevenSegment_enumPIN1  
	SevenSegment_enumPIN2 
	SevenSegment_enumPIN3 
	SevenSegment_enumPIN4 
	SevenSegment_enumPIN5 
	SevenSegment_enumPIN6 
	SevenSegment_enumPIN7 
}
For (.port): 
{
	SevenSegment_enumPORTA
	SevenSegment_enumPORTB
	SevenSegment_enumPORTC
	SevenSegment_enumPORTD
}
For (.Active_Status): 
{
	SevenSegment_enum_CommonCathode
	SevenSegment_enum_CommonAnode
}
*/
SevenSegment_strCfg SevenSegmentS[NUM_OF_SEVENSEGMENTS]=
{

[SEVENSEGMENTS1]=
{
	.LEDA_Port=	SevenSegment_enumPORTA	,
	.LEDA_Pin=	SevenSegment_enumPIN0	,
	.LEDB_Port=	SevenSegment_enumPORTA	,
	.LEDB_Pin=	SevenSegment_enumPIN1 	,
	.LEDC_Port=	SevenSegment_enumPORTA	,
	.LEDC_Pin=	SevenSegment_enumPIN2	,
	.LEDD_Port=	SevenSegment_enumPORTA	,
	.LEDD_Pin=	SevenSegment_enumPIN3	,
	.LEDE_Port=	SevenSegment_enumPORTA	,
	.LEDE_Pin=	SevenSegment_enumPIN4	,
	.LEDF_Port=	SevenSegment_enumPORTA	,
	.LEDF_Pin=	SevenSegment_enumPIN5	,
	.LEDG_Port=	SevenSegment_enumPORTA	,
	.LEDG_Pin=	SevenSegment_enumPIN6	,
	.LEDDP_Port=SevenSegment_enumPORTA	,
	.LEDDP_Pin=	SevenSegment_enumPIN7	,
	.Active_Status=	SevenSegment_enum_CommonCathode
}
,
[SEVENSEGMENTS2]=
{
	.LEDA_Port=	SevenSegment_enumPORTB	,
	.LEDA_Pin=	SevenSegment_enumPIN0	,
	.LEDB_Port=	SevenSegment_enumPORTB	,
	.LEDB_Pin=	SevenSegment_enumPIN1 	,
	.LEDC_Port=	SevenSegment_enumPORTB	,
	.LEDC_Pin=	SevenSegment_enumPIN2	,
	.LEDD_Port=	SevenSegment_enumPORTB	,
	.LEDD_Pin=	SevenSegment_enumPIN3	,
	.LEDE_Port=	SevenSegment_enumPORTB	,
	.LEDE_Pin=	SevenSegment_enumPIN4	,
	.LEDF_Port=	SevenSegment_enumPORTB	,
	.LEDF_Pin=	SevenSegment_enumPIN5	,
	.LEDG_Port=	SevenSegment_enumPORTB	,
	.LEDG_Pin=	SevenSegment_enumPIN6	,
	.LEDDP_Port=SevenSegment_enumPORTB	,
	.LEDDP_Pin=	SevenSegment_enumPIN7	,
	.Active_Status=	SevenSegment_enum_CommonAnode
}
,
[SEVENSEGMENTS3]=
{
	.LEDA_Port=	SevenSegment_enumPORTC	,
	.LEDA_Pin=	SevenSegment_enumPIN0	,
	.LEDB_Port=	SevenSegment_enumPORTC	,
	.LEDB_Pin=	SevenSegment_enumPIN1 	,
	.LEDC_Port=	SevenSegment_enumPORTC	,
	.LEDC_Pin=	SevenSegment_enumPIN2	,
	.LEDD_Port=	SevenSegment_enumPORTC	,
	.LEDD_Pin=	SevenSegment_enumPIN3	,
	.LEDE_Port=	SevenSegment_enumPORTC	,
	.LEDE_Pin=	SevenSegment_enumPIN4	,
	.LEDF_Port=	SevenSegment_enumPORTC	,
	.LEDF_Pin=	SevenSegment_enumPIN5	,
	.LEDG_Port=	SevenSegment_enumPORTC	,
	.LEDG_Pin=	SevenSegment_enumPIN6	,
	.LEDDP_Port=SevenSegment_enumPORTC	,
	.LEDDP_Pin=	SevenSegment_enumPIN7	,
	.Active_Status=	SevenSegment_enum_CommonAnode
}
,
[SEVENSEGMENTS4]=
{
	.LEDA_Port=	SevenSegment_enumPORTD	,
	.LEDA_Pin=	SevenSegment_enumPIN0	,
	.LEDB_Port=	SevenSegment_enumPORTD	,
	.LEDB_Pin=	SevenSegment_enumPIN1 	,
	.LEDC_Port=	SevenSegment_enumPORTD	,
	.LEDC_Pin=	SevenSegment_enumPIN2	,
	.LEDD_Port=	SevenSegment_enumPORTD	,
	.LEDD_Pin=	SevenSegment_enumPIN3	,
	.LEDE_Port=	SevenSegment_enumPORTD	,
	.LEDE_Pin=	SevenSegment_enumPIN4	,
	.LEDF_Port=	SevenSegment_enumPORTD	,
	.LEDF_Pin=	SevenSegment_enumPIN5	,
	.LEDG_Port=	SevenSegment_enumPORTD	,
	.LEDG_Pin=	SevenSegment_enumPIN6	,
	.LEDDP_Port=SevenSegment_enumPORTD	,
	.LEDDP_Pin=	SevenSegment_enumPIN7	,
	.Active_Status=	SevenSegment_enum_CommonAnode
}
};
