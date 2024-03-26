/*
 ============================================================================
 Name        : PORT_cfg.c
 Author      : Omar Medhat Mohamed
 Description : Source Configuration file for the PORT driver
 Date        : 3/12/2023
 ============================================================================
 */
#include "CFG/PORT_cfg.h"
#include "MCAL/PORT.H"
/*If the User Choose Pre_Compile_Configuration*/
#if (CONFIGURATION_TYPE == POST_Compile_Configuration)
/*Allocate an global array of NUM_OF_PORTS * NUM_OF_PINS(for each port)*/
		 PORT_enumpinopt_t PORT_PINcfg [TOTAL_NUMBER_OF_PINS] =
		{
			/* FILL PINS state according to total PINsnumber */
			PORT_enumINPUT_HI,/*PIN0*/
			PORT_enumINPUT_HI,/*PIN1*/
			PORT_enumINPUT_HI,/*PIN2*/
			PORT_enumINPUT_HI,/*PIN3*/
			PORT_enumINPUT_HI,/*PIN4*/
			PORT_enumINPUT_HI,/*PIN5*/
			PORT_enumINPUT_HI,/*PIN6*/
			PORT_enumINPUT_HI,/*PIN7*/
			PORT_enumINPUT_HI,/*PIN8*/
			PORT_enumINPUT_HI,/*PIN9*/
			PORT_enumOUTPUT_LOW,/*PIN10*/
			PORT_enumINPUT_HI,/*PIN11*/
			PORT_enumINPUT_HI,/*PIN12*/
			PORT_enumINPUT_HI,/*PIN13*/
			PORT_enumINPUT_HI,/*PIN14*/
			PORT_enumINPUT_HI,/*PIN15*/
			PORT_enumINPUT_HI,/*PIN16*/
			PORT_enumINPUT_HI,/*PIN17*/
			PORT_enumINPUT_HI,/*PIN18*/
			PORT_enumINPUT_HI,/*PIN19*/
			PORT_enumINPUT_HI,/*PIN20*/
			PORT_enumINPUT_HI,/*PIN21*/
			PORT_enumINPUT_HI,/*PIN22*/
			PORT_enumINPUT_HI,/*PIN23*/
			PORT_enumINPUT_HI,/*PIN24*/
			PORT_enumINPUT_HI,/*PIN25*/
			PORT_enumINPUT_HI,/*PIN26*/
			PORT_enumINPUT_HI,/*PIN27*/
			PORT_enumINPUT_HI,/*PIN28*/
			PORT_enumINPUT_HI,/*PIN29*/
			PORT_enumINPUT_HI,/*PIN30*/
			PORT_enumINPUT_HI,/*PIN31*/
		};

#endif
	
