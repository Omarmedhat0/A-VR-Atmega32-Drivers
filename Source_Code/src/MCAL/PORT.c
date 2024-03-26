/*
 ============================================================================
 Name        : PORT.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the PORT driver
 Date        : 12/3/2023
 ============================================================================
 */
#include "MCAL/PORT.h"
#include "CFG/PORT_cfg.h"
#include "LIB/Reg_Add.h"

/*Set global array whice will be used*/
extern PORT_enumpinopt_t PORT_PINcfg [TOTAL_NUMBER_OF_PINS];


/**
 @brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin and tc configure them by PrE or POST Configuration.
 @param  : Nothing
 @return : Nothing                                               
 */	
void Int_PORT(void)
{
	/*If the User Choose Pre_Compile_Configuration*/
#if(CONFIGURATION_TYPE == Pre_Compile_Configuration)

	/**********************************************************TWO_PORTS Case**********************************************************/
#if ((NUM_OF_PORTS == TWO_PORTS) ||(NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS))
	/* PIN0 Configuration */
#if (PORT_PIN0 == INPUT_PU)
	/* Set PIN0 as an input with pull-up enabled */
#define PIN0_DIR PORT_LOW
#define PIN0_PORT PORT_HIGH
#elif (PORT_PIN0 == INPUT_HI)
	/* Set PIN0 as an input with high impedance */
#define PIN0_DIR PORT_LOW
#define PIN0_PORT PORT_LOW
#elif (PORT_PIN0 == OUTPUT_HIGH)
	/* Set PIN0 as an output with high value */
#define PIN0_DIR PORT_HIGH
#define PIN0_PORT PORT_HIGH
#elif (PORT_PIN0 == OUTPUT_LOW)
	/* Set PIN0 as an output with low value */
#define PIN0_DIR PORT_HIGH
#define PIN0_PORT PORT_LOW
#elif (PORT_PIN0 == NOT_SELECTED)
	/* No configuration selected for PIN0 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN0 */
#endif

	/* PIN1 Configuration */
#if (PORT_PIN1 == INPUT_PU)
	/* Set PIN1 as an input with pull-up enabled */
#define PIN1_DIR PORT_LOW
#define PIN1_PORT PORT_HIGH
#elif (PORT_PIN1 == INPUT_HI)
	/* Set PIN1 as an input with high impedance */
#define PIN1_DIR PORT_LOW
#define PIN1_PORT PORT_LOW
#elif (PORT_PIN1 == OUTPUT_HIGH)
	/* Set PIN1 as an output with high value */
#define PIN1_DIR PORT_HIGH
#define PIN1_PORT PORT_HIGH
#elif (PORT_PIN1 == OUTPUT_LOW)
	/* Set PIN1 as an output with low value */
#define PIN1_DIR PORT_HIGH
#define PIN1_PORT PORT_LOW
#elif (PORT_PIN1 == NOT_SELECTED)
	/* No configuration selected for PIN1 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN1 */
#endif

	/* PIN2 Configuration */
#if (PORT_PIN2 == INPUT_PU)
	/* Set PIN2 as an input with pull-up enabled */
#define PIN2_DIR PORT_LOW
#define PIN2_PORT PORT_HIGH
#elif (PORT_PIN2 == INPUT_HI)
	/* Set PIN2 as an input with high impedance */
#define PIN2_DIR PORT_LOW
#define PIN2_PORT PORT_LOW
#elif (PORT_PIN2 == OUTPUT_HIGH)
	/* Set PIN2 as an output with high value */
#define PIN2_DIR PORT_HIGH
#define PIN2_PORT PORT_HIGH
#elif (PORT_PIN2 == OUTPUT_LOW)
	/* Set PIN2 as an output with low value */
#define PIN2_DIR PORT_HIGH
#define PIN2_PORT PORT_LOW
#elif (PORT_PIN2 == NOT_SELECTED)
	/* No configuration selected for PIN2 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN2 */
#endif

	/* PIN3 Configuration */
#if (PORT_PIN3 == INPUT_PU)
	/* Set PIN3 as an input with pull-up enabled */
#define PIN3_DIR PORT_LOW
#define PIN3_PORT PORT_HIGH
#elif (PORT_PIN3 == INPUT_HI)
	/* Set PIN3 as an input with high impedance */
#define PIN3_DIR PORT_LOW
#define PIN3_PORT PORT_LOW
#elif (PORT_PIN3 == OUTPUT_HIGH)
	/* Set PIN3 as an output with high value */
#define PIN3_DIR PORT_HIGH
#define PIN3_PORT PORT_HIGH
#elif (PORT_PIN3 == OUTPUT_LOW)
	/* Set PIN3 as an output with low value */
#define PIN3_DIR PORT_HIGH
#define PIN3_PORT PORT_LOW
#elif (PORT_PIN3 == NOT_SELECTED)
	/* No configuration selected for PIN3 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN3 */
#endif

	/* PIN4 Configuration */
#if (PORT_PIN4 == INPUT_PU)
	/* Set PIN4 as an input with pull-up enabled */
#define PIN4_DIR PORT_LOW
#define PIN4_PORT PORT_HIGH
#elif (PORT_PIN4 == INPUT_HI)
	/* Set PIN4 as an input with high impedance */
#define PIN4_DIR PORT_LOW
#define PIN4_PORT PORT_LOW
#elif (PORT_PIN4 == OUTPUT_HIGH)
	/* Set PIN4 as an output with high value */
#define PIN4_DIR PORT_HIGH
#define PIN4_PORT PORT_HIGH
#elif (PORT_PIN4 == OUTPUT_LOW)
	/* Set PIN4 as an output with low value */
#define PIN4_DIR PORT_HIGH
#define PIN4_PORT PORT_LOW
#elif (PORT_PIN4 == NOT_SELECTED)
	/* No configuration selected for PIN4 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN4 */
#endif

	/* PIN5 Configuration */
#if (PORT_PIN5 == INPUT_PU)
	/* Set PIN5 as an input with pull-up enabled */
#define PIN5_DIR PORT_LOW
#define PIN5_PORT PORT_HIGH
#elif (PORT_PIN5 == INPUT_HI)
	/* Set PIN5 as an input with high impedance */
#define PIN5_DIR PORT_LOW
#define PIN5_PORT PORT_LOW
#elif (PORT_PIN5 == OUTPUT_HIGH)
	/* Set PIN5 as an output with high value */
#define PIN5_DIR PORT_HIGH
#define PIN5_PORT PORT_HIGH
#elif (PORT_PIN5 == OUTPUT_LOW)
	/* Set PIN5 as an output with low value */
#define PIN5_DIR PORT_HIGH
#define PIN5_PORT PORT_LOW
#elif (PORT_PIN5 == NOT_SELECTED)
	/* No configuration selected for PIN5 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN5 */
#endif
#if (NUM_OF_PINS>SIX_PINS)
	/* PIN6 Configuration */
#if (PORT_PIN6 == INPUT_PU)
	/* Set PIN6 as an input with pull-up enabled */
#define PIN6_DIR PORT_LOW
#define PIN6_PORT PORT_HIGH
#elif (PORT_PIN6 == INPUT_HI)
	/* Set PIN6 as an input with high impedance */
#define PIN6_DIR PORT_LOW
#define PIN6_PORT PORT_LOW
#elif (PORT_PIN6 == OUTPUT_HIGH)
	/* Set PIN6 as an output with high value */
#define PIN6_DIR PORT_HIGH
#define PIN6_PORT PORT_HIGH
#elif (PORT_PIN6 == OUTPUT_LOW)
	/* Set PIN6 as an output with low value */
#define PIN6_DIR PORT_HIGH
#define PIN6_PORT PORT_LOW
#elif (PORT_PIN6 == NOT_SELECTED)
	/* No configuration selected for PIN6 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN6 */
#endif
#endif

#if (NUM_OF_PINS>SEVEN_PINS)
	/* PIN7 Configuration */
#if (PORT_PIN7 == INPUT_PU)
	/* Set PIN7 as an input with pull-up enabled */
#define PIN7_DIR PORT_LOW
#define PIN7_PORT PORT_HIGH
#elif (PORT_PIN7 == INPUT_HI)
	/* Set PIN7 as an input with high impedance */
#define PIN7_DIR PORT_LOW
#define PIN7_PORT PORT_LOW
#elif (PORT_PIN7 == OUTPUT_HIGH)
	/* Set PIN7 as an output with high value */
#define PIN7_DIR PORT_HIGH
#define PIN7_PORT PORT_HIGH
#elif (PORT_PIN7 == OUTPUT_LOW)
	/* Set PIN7 as an output with low value */
#define PIN7_DIR PORT_HIGH
#define PIN7_PORT PORT_LOW
#elif (PORT_PIN7 == NOT_SELECTED)
	/* No configuration selected for PIN7 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN7 */
#endif
#endif

	/* PIN8 Configuration */
#if (PORT_PIN8 == INPUT_PU)
	/* Set PIN8 as an input with pull-up enabled */
#define PIN8_DIR PORT_LOW
#define PIN8_PORT PORT_HIGH
#elif (PORT_PIN8 == INPUT_HI)
	/* Set PIN8 as an input with high impedance */
#define PIN8_DIR PORT_LOW
#define PIN8_PORT PORT_LOW
#elif (PORT_PIN8 == OUTPUT_HIGH)
	/* Set PIN8 as an output with high value */
#define PIN8_DIR PORT_HIGH
#define PIN8_PORT PORT_HIGH
#elif (PORT_PIN8 == OUTPUT_LOW)
	/* Set PIN8 as an output with low value */
#define PIN8_DIR PORT_HIGH
#define PIN8_PORT PORT_LOW
#elif (PORT_PIN8 == NOT_SELECTED)
	/* No configuration selected for PIN8 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN8 */
#endif

	/* PIN9 Configuration */
#if (PORT_PIN9 == INPUT_PU)
	/* Set PIN9 as an input with pull-up enabled */
#define PIN9_DIR PORT_LOW
#define PIN9_PORT PORT_HIGH
#elif (PORT_PIN9 == INPUT_HI)
	/* Set PIN9 as an input with high impedance */
#define PIN9_DIR PORT_LOW
#define PIN9_PORT PORT_LOW
#elif (PORT_PIN9 == OUTPUT_HIGH)
	/* Set PIN9 as an output with high value */
#define PIN9_DIR PORT_HIGH
#define PIN9_PORT PORT_HIGH
#elif (PORT_PIN9 == OUTPUT_LOW)
	/* Set PIN9 as an output with low value */
#define PIN9_DIR PORT_HIGH
#define PIN9_PORT PORT_LOW
#elif (PORT_PIN9 == NOT_SELECTED)
	/* No configuration selected for PIN9 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN9 */
#endif


	/* PIN10 Configuration */
#if (PORT_PIN10 == INPUT_PU)
	/* Set PIN10 as an input with pull-up enabled */
#define PIN10_DIR PORT_LOW
#define PIN10_PORT PORT_HIGH
#elif (PORT_PIN10 == INPUT_HI)
	/* Set PIN10 as an input with high impedance */
#define PIN10_DIR PORT_LOW
#define PIN10_PORT PORT_LOW
#elif (PORT_PIN10 == OUTPUT_HIGH)
	/* Set PIN10 as an output with high value */
#define PIN10_DIR PORT_HIGH
#define PIN10_PORT PORT_HIGH
#elif (PORT_PIN10 == OUTPUT_LOW)
	/* Set PIN10 as an output with low value */
#define PIN10_DIR PORT_HIGH
#define PIN10_PORT PORT_LOW
#elif (PORT_PIN10 == NOT_SELECTED)
	/* No configuration selected for PIN10 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN10 */
#endif

	/* PIN11 Configuration */
#if (PORT_PIN11 == INPUT_PU)
	/* Set PIN11 as an input with pull-up enabled */
#define PIN11_DIR PORT_LOW
#define PIN11_PORT PORT_HIGH
#elif (PORT_PIN11 == INPUT_HI)
	/* Set PIN11 as an input with high impedance */
#define PIN11_DIR PORT_LOW
#define PIN11_PORT PORT_LOW
#elif (PORT_PIN11 == OUTPUT_HIGH)
	/* Set PIN11 as an output with high value */
#define PIN11_DIR PORT_HIGH
#define PIN11_PORT PORT_HIGH
#elif (PORT_PIN11 == OUTPUT_LOW)
	/* Set PIN11 as an output with low value */
#define PIN11_DIR PORT_HIGH
#define PIN11_PORT PORT_LOW
#elif (PORT_PIN11 == NOT_SELECTED)
	/* No configuration selected for PIN11 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN11 */
#endif

	/* PIN12 Configuration */
#if (PORT_PIN12 == INPUT_PU)
	/* Set PIN12 as an input with pull-up enabled */
#define PIN12_DIR PORT_LOW
#define PIN12_PORT PORT_HIGH
#elif (PORT_PIN12 == INPUT_HI)
	/* Set PIN12 as an input with high impedance */
#define PIN12_DIR PORT_LOW
#define PIN12_PORT PORT_LOW
#elif (PORT_PIN12 == OUTPUT_HIGH)
	/* Set PIN12 as an output with high value */
#define PIN12_DIR PORT_HIGH
#define PIN12_PORT PORT_HIGH
#elif (PORT_PIN12 == OUTPUT_LOW)
	/* Set PIN12 as an output with low value */
#define PIN12_DIR PORT_HIGH
#define PIN12_PORT PORT_LOW
#elif (PORT_PIN12 == NOT_SELECTED)
	/* No configuration selected for PIN12 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN12 */
#endif

	/* PIN13 Configuration */
#if (PORT_PIN13 == INPUT_PU)
	/* Set PIN13 as an input with pull-up enabled */
#define PIN13_DIR PORT_LOW
#define PIN13_PORT PORT_HIGH
#elif (PORT_PIN13 == INPUT_HI)
	/* Set PIN13 as an input with high impedance */
#define PIN13_DIR PORT_LOW
#define PIN13_PORT PORT_LOW
#elif (PORT_PIN13 == OUTPUT_HIGH)
	/* Set PIN13 as an output with high value */
#define PIN13_DIR PORT_HIGH
#define PIN13_PORT PORT_HIGH
#elif (PORT_PIN13 == OUTPUT_LOW)
	/* Set PIN13 as an output with low value */
#define PIN13_DIR PORT_HIGH
#define PIN13_PORT PORT_LOW
#elif (PORT_PIN13 == NOT_SELECTED)
	/* No configuration selected for PIN13 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN13 */
#endif

#if (NUM_OF_PINS>SIX_PINS)
	/* PIN14 Configuration */
#if (PORT_PIN14 == INPUT_PU)
	/* Set PIN14 as an input with pull-up enabled */
#define PIN14_DIR PORT_LOW
#define PIN14_PORT PORT_HIGH
#elif (PORT_PIN14 == INPUT_HI)
	/* Set PIN14 as an input with high impedance */
#define PIN14_DIR PORT_LOW
#define PIN14_PORT PORT_LOW
#elif (PORT_PIN14 == OUTPUT_HIGH)
	/* Set PIN14 as an output with high value */
#define PIN14_DIR PORT_HIGH
#define PIN14_PORT PORT_HIGH
#elif (PORT_PIN14 == OUTPUT_LOW)
	/* Set PIN14 as an output with low value */
#define PIN14_DIR PORT_HIGH
#define PIN14_PORT PORT_LOW
#elif (PORT_PIN14 == NOT_SELECTED)
	/* No configuration selected for PIN14 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN14 */
#endif
#endif

#if (NUM_OF_PINS>SEVEN_PINS)
	/* PIN15 Configuration */
#if (PORT_PIN15 == INPUT_PU)
	/* Set PIN15 as an input with pull-up enabled */
#define PIN15_DIR PORT_LOW
#define PIN15_PORT PORT_HIGH
#elif (PORT_PIN15 == INPUT_HI)
	/* Set PIN15 as an input with high impedance */
#define PIN15_DIR PORT_LOW
#define PIN15_PORT PORT_LOW
#elif (PORT_PIN15 == OUTPUT_HIGH)
	/* Set PIN15 as an output with high value */
#define PIN15_DIR PORT_HIGH
#define PIN15_PORT PORT_HIGH
#elif (PORT_PIN15 == OUTPUT_LOW)
	/* Set PIN15 as an output with low value */
#define PIN15_DIR PORT_HIGH
#define PIN15_PORT PORT_LOW
#elif (PORT_PIN15 == NOT_SELECTED)
	/* No configuration selected for PIN15 */
#endif
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN15 */
#endif
	/**********************************************************THREE_PORTS Case or FOUR_PORTS Case**********************************************************/
#if ((NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS))
	/* PIN16 Configuration */
#if (PORT_PIN16 == INPUT_PU)
	/* Set PIN16 as an input with pull-up enabled */
#define PIN16_DIR PORT_LOW
#define PIN16_PORT PORT_HIGH
#elif (PORT_PIN16 == INPUT_HI)
	/* Set PIN16 as an input with high impedance */
#define PIN16_DIR PORT_LOW
#define PIN16_PORT PORT_LOW
#elif (PORT_PIN16 == OUTPUT_HIGH)
	/* Set PIN16 as an output with high value */
#define PIN16_DIR PORT_HIGH
#define PIN16_PORT PORT_HIGH
#elif (PORT_PIN16 == OUTPUT_LOW)
	/* Set PIN16 as an output with low value */
#define PIN16_DIR PORT_HIGH
#define PIN16_PORT PORT_LOW
#elif (PORT_PIN16 == NOT_SELECTED)
	/* No configuration selected for PIN16 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN16 */
#endif

	/* PIN17 Configuration */
#if (PORT_PIN17 == INPUT_PU)
	/* Set PIN17 as an input with pull-up enabled */
#define PIN17_DIR PORT_LOW
#define PIN17_PORT PORT_HIGH
#elif (PORT_PIN17 == INPUT_HI)
	/* Set PIN17 as an input with high impedance */
#define PIN17_DIR PORT_LOW
#define PIN17_PORT PORT_LOW
#elif (PORT_PIN17 == OUTPUT_HIGH)
	/* Set PIN17 as an output with high value */
#define PIN17_DIR PORT_HIGH
#define PIN17_PORT PORT_HIGH
#elif (PORT_PIN17 == OUTPUT_LOW)
	/* Set PIN17 as an output with low value */
#define PIN17_DIR PORT_HIGH
#define PIN17_PORT PORT_LOW
#elif (PORT_PIN17 == NOT_SELECTED)
	/* No configuration selected for PIN17 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN17 */
#endif

	/* PIN18 Configuration */
#if (PORT_PIN18 == INPUT_PU)
	/* Set PIN18 as an input with pull-up enabled */
#define PIN18_DIR PORT_LOW
#define PIN18_PORT PORT_HIGH
#elif (PORT_PIN18 == INPUT_HI)
	/* Set PIN18 as an input with high impedance */
#define PIN18_DIR PORT_LOW
#define PIN18_PORT PORT_LOW
#elif (PORT_PIN18 == OUTPUT_HIGH)
	/* Set PIN18 as an output with high value */
#define PIN18_DIR PORT_HIGH
#define PIN18_PORT PORT_HIGH
#elif (PORT_PIN18 == OUTPUT_LOW)
	/* Set PIN18 as an output with low value */
#define PIN18_DIR PORT_HIGH
#define PIN18_PORT PORT_LOW
#elif (PORT_PIN18 == NOT_SELECTED)
	/* No configuration selected for PIN18 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN18 */
#endif

	/* PIN19 Configuration */
#if (PORT_PIN19 == INPUT_PU)
	/* Set PIN19 as an input with pull-up enabled */
#define PIN19_DIR PORT_LOW
#define PIN19_PORT PORT_HIGH
#elif (PORT_PIN19 == INPUT_HI)
	/* Set PIN19 as an input with high impedance */
#define PIN19_DIR PORT_LOW
#define PIN19_PORT PORT_LOW
#elif (PORT_PIN19 == OUTPUT_HIGH)
	/* Set PIN19 as an output with high value */
#define PIN19_DIR PORT_HIGH
#define PIN19_PORT PORT_HIGH
#elif (PORT_PIN19 == OUTPUT_LOW)
	/* Set PIN19 as an output with low value */
#define PIN19_DIR PORT_HIGH
#define PIN19_PORT PORT_LOW
#elif (PORT_PIN19 == NOT_SELECTED)
	/* No configuration selected for PIN19 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN19 */
#endif

	/* PIN20 Configuration */
#if (PORT_PIN20 == INPUT_PU)
	/* Set PIN20 as an input with pull-up enabled */
#define PIN20_DIR PORT_LOW
#define PIN20_PORT PORT_HIGH
#elif (PORT_PIN20 == INPUT_HI)
	/* Set PIN20 as an input with high impedance */
#define PIN20_DIR PORT_LOW
#define PIN20_PORT PORT_LOW
#elif (PORT_PIN20 == OUTPUT_HIGH)
	/* Set PIN20 as an output with high value */
#define PIN20_DIR PORT_HIGH
#define PIN20_PORT PORT_HIGH
#elif (PORT_PIN20 == OUTPUT_LOW)
	/* Set PIN20 as an output with low value */
#define PIN20_DIR PORT_HIGH
#define PIN20_PORT PORT_LOW
#elif (PORT_PIN20 == NOT_SELECTED)
	/* No configuration selected for PIN20 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN20 */
#endif


	/* PIN21 Configuration */
#if (PORT_PIN21 == INPUT_PU)
	/* Set PIN21 as an input with pull-up enabled */
#define PIN21_DIR PORT_LOW
#define PIN21_PORT PORT_HIGH
#elif (PORT_PIN21 == INPUT_HI)
	/* Set PIN21 as an input with high impedance */
#define PIN21_DIR PORT_LOW
#define PIN21_PORT PORT_LOW
#elif (PORT_PIN21 == OUTPUT_HIGH)
	/* Set PIN21 as an output with high value */
#define PIN21_DIR PORT_HIGH
#define PIN21_PORT PORT_HIGH
#elif (PORT_PIN21 == OUTPUT_LOW)
	/* Set PIN21 as an output with low value */
#define PIN21_DIR PORT_HIGH
#define PIN21_PORT PORT_LOW
#elif (PORT_PIN21 == NOT_SELECTED)
	/* No configuration selected for PIN21 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN21 */
#endif

#if (NUM_OF_PINS > SIX_PINS)	
	/* PIN22 Configuration */
#if (PORT_PIN22 == INPUT_PU)
	/* Set PIN22 as an input with pull-up enabled */
#define PIN22_DIR PORT_LOW
#define PIN22_PORT PORT_HIGH
#elif (PORT_PIN22 == INPUT_HI)
	/* Set PIN22 as an input with high impedance */
#define PIN22_DIR PORT_LOW
#define PIN22_PORT PORT_LOW
#elif (PORT_PIN22 == OUTPUT_HIGH)
	/* Set PIN22 as an output with high value */
#define PIN22_DIR PORT_HIGH
#define PIN22_PORT PORT_HIGH
#elif (PORT_PIN22 == OUTPUT_LOW)
	/* Set PIN22 as an output with low value */
#define PIN22_DIR PORT_HIGH
#define PIN22_PORT PORT_LOW
#elif (PORT_PIN22 == NOT_SELECTED)
	/* No configuration selected for PIN22 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN22 */
#endif
#endif

#if (NUM_OF_PINS > SEVEN_PINS)
	/* PIN23 Configuration */
#if (PORT_PIN23 == INPUT_PU)
	/* Set PIN23 as an input with pull-up enabled */
#define PIN23_DIR PORT_LOW
#define PIN23_PORT PORT_HIGH
#elif (PORT_PIN23 == INPUT_HI)
	/* Set PIN23 as an input with high impedance */
#define PIN23_DIR PORT_LOW
#define PIN23_PORT PORT_LOW
#elif (PORT_PIN23 == OUTPUT_HIGH)
	/* Set PIN23 as an output with high value */
#define PIN23_DIR PORT_HIGH
#define PIN23_PORT PORT_HIGH
#elif (PORT_PIN23 == OUTPUT_LOW)
	/* Set PIN23 as an output with low value */
#define PIN23_DIR PORT_HIGH
#define PIN23_PORT PORT_LOW
#elif (PORT_PIN23 == NOT_SELECTED)
	/* No configuration selected for PIN23 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN23 */
#endif
#endif

#endif


	/**********************************************************FOUR_PORTS Case**********************************************************/
#if (NUM_OF_PORTS == FOUR_PORTS)

	/* PIN24 Configuration */
#if (PORT_PIN24 == INPUT_PU)
	/* Set PIN24 as an input with pull-up enabled */
#define PIN24_DIR PORT_LOW
#define PIN24_PORT PORT_HIGH
#elif (PORT_PIN24 == INPUT_HI)
	/* Set PIN24 as an input with high impedance */
#define PIN24_DIR PORT_LOW
#define PIN24_PORT PORT_LOW
#elif (PORT_PIN24 == OUTPUT_HIGH)
	/* Set PIN24 as an output with high value */
#define PIN24_DIR PORT_HIGH
#define PIN24_PORT PORT_HIGH
#elif (PORT_PIN24 == OUTPUT_LOW)
	/* Set PIN24 as an output with low value */
#define PIN24_DIR PORT_HIGH
#define PIN24_PORT PORT_LOW
#elif (PORT_PIN24 == NOT_SELECTED)
	/* No configuration selected for PIN24 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN24 */
#endif

	/* PIN25 Configuration */
#if (PORT_PIN25 == INPUT_PU)
	/* Set PIN25 as an input with pull-up enabled */
#define PIN25_DIR PORT_LOW
#define PIN25_PORT PORT_HIGH
#elif (PORT_PIN25 == INPUT_HI)
	/* Set PIN25 as an input with high impedance */
#define PIN25_DIR PORT_LOW
#define PIN25_PORT PORT_LOW
#elif (PORT_PIN25 == OUTPUT_HIGH)
	/* Set PIN25 as an output with high value */
#define PIN25_DIR PORT_HIGH
#define PIN25_PORT PORT_HIGH
#elif (PORT_PIN25 == OUTPUT_LOW)
	/* Set PIN25 as an output with low value */
#define PIN25_DIR PORT_HIGH
#define PIN25_PORT PORT_LOW
#elif (PORT_PIN25 == NOT_SELECTED)
	/* No configuration selected for PIN25 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN25 */
#endif

	/* PIN26 Configuration */
#if (PORT_PIN26 == INPUT_PU)
	/* Set PIN26 as an input with pull-up enabled */
#define PIN26_DIR PORT_LOW
#define PIN26_PORT PORT_HIGH
#elif (PORT_PIN26 == INPUT_HI)
	/* Set PIN26 as an input with high impedance */
#define PIN26_DIR PORT_LOW
#define PIN26_PORT PORT_LOW
#elif (PORT_PIN26 == OUTPUT_HIGH)
	/* Set PIN26 as an output with high value */
#define PIN26_DIR PORT_HIGH
#define PIN26_PORT PORT_HIGH
#elif (PORT_PIN26 == OUTPUT_LOW)
	/* Set PIN26 as an output with low value */
#define PIN26_DIR PORT_HIGH
#define PIN26_PORT PORT_LOW
#elif (PORT_PIN26 == NOT_SELECTED)
	/* No configuration selected for PIN26 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN26 */
#endif

	/* PIN27 Configuration */
#if (PORT_PIN27 == INPUT_PU)
	/* Set PIN27 as an input with pull-up enabled */
#define PIN27_DIR PORT_LOW
#define PIN27_PORT PORT_HIGH
#elif (PORT_PIN27 == INPUT_HI)
	/* Set PIN27 as an input with high impedance */
#define PIN27_DIR PORT_LOW
#define PIN27_PORT PORT_LOW
#elif (PORT_PIN27 == OUTPUT_HIGH)
	/* Set PIN27 as an output with high value */
#define PIN27_DIR PORT_HIGH
#define PIN27_PORT PORT_HIGH
#elif (PORT_PIN27 == OUTPUT_LOW)
	/* Set PIN27 as an output with low value */
#define PIN27_DIR PORT_HIGH
#define PIN27_PORT PORT_LOW
#elif (PORT_PIN27 == NOT_SELECTED)
	/* No configuration selected for PIN27 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN27 */
#endif

	/* PIN28 Configuration */
#if (PORT_PIN28 == INPUT_PU)
	/* Set PIN28 as an input with pull-up enabled */
#define PIN28_DIR PORT_LOW
#define PIN28_PORT PORT_HIGH
#elif (PORT_PIN28 == INPUT_HI)
	/* Set PIN28 as an input with high impedance */
#define PIN28_DIR PORT_LOW
#define PIN28_PORT PORT_LOW
#elif (PORT_PIN28 == OUTPUT_HIGH)
	/* Set PIN28 as an output with high value */
#define PIN28_DIR PORT_HIGH
#define PIN28_PORT PORT_HIGH
#elif (PORT_PIN28 == OUTPUT_LOW)
	/* Set PIN28 as an output with low value */
#define PIN28_DIR PORT_HIGH
#define PIN28_PORT PORT_LOW
#elif (PORT_PIN28 == NOT_SELECTED)
	/* No configuration selected for PIN28 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN28 */
#endif

	/* PIN29 Configuration */
#if (PORT_PIN29 == INPUT_PU)
	/* Set PIN29 as an input with pull-up enabled */
#define PIN29_DIR PORT_LOW
#define PIN29_PORT PORT_HIGH
#elif (PORT_PIN29 == INPUT_HI)
	/* Set PIN29 as an input with high impedance */
#define PIN29_DIR PORT_LOW
#define PIN29_PORT PORT_LOW
#elif (PORT_PIN29 == OUTPUT_HIGH)
	/* Set PIN29 as an output with high value */
#define PIN29_DIR PORT_HIGH
#define PIN29_PORT PORT_HIGH
#elif (PORT_PIN29 == OUTPUT_LOW)
	/* Set PIN29 as an output with low value */
#define PIN29_DIR PORT_HIGH
#define PIN29_PORT PORT_LOW
#elif (PORT_PIN29 == NOT_SELECTED)
	/* No configuration selected for PIN29 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN29 */
#endif

#if (NUM_OF_PINS>SIX_PINS)
	/* PIN30 Configuration */
#if (PORT_PIN30 == INPUT_PU)
	/* Set PIN30 as an input with pull-up enabled */
#define PIN30_DIR PORT_LOW
#define PIN30_PORT PORT_HIGH
#elif (PORT_PIN30 == INPUT_HI)
	/* Set PIN30 as an input with high impedance */
#define PIN30_DIR PORT_LOW
#define PIN30_PORT PORT_LOW
#elif (PORT_PIN30 == OUTPUT_HIGH)
	/* Set PIN30 as an output with high value */
#define PIN30_DIR PORT_HIGH
#define PIN30_PORT PORT_HIGH
#elif (PORT_PIN30 == OUTPUT_LOW)
	/* Set PIN30 as an output with low value */
#define PIN30_DIR PORT_HIGH
#define PIN30_PORT PORT_LOW
#elif (PORT_PIN30 == NOT_SELECTED)
	/* No configuration selected for PIN30 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN30 */
#endif
#endif

#if (NUM_OF_PINS>SEVEN_PINS)
	/* PIN31 Configuration */
#if (PORT_PIN31 == INPUT_PU)
	/* Set PIN31 as an input with pull-up enabled */
#define PIN31_DIR PORT_LOW
#define PIN31_PORT PORT_HIGH
#elif (PORT_PIN31 == INPUT_HI)
	/* Set PIN31 as an input with high impedance */
#define PIN31_DIR PORT_LOW
#define PIN31_PORT PORT_LOW
#elif (PORT_PIN31 == OUTPUT_HIGH)
	/* Set PIN31 as an output with high value */
#define PIN31_DIR PORT_HIGH
#define PIN31_PORT PORT_HIGH
#elif (PORT_PIN31 == OUTPUT_LOW)
	/* Set PIN31 as an output with low value */
#define PIN31_DIR PORT_HIGH
#define PIN31_PORT PORT_LOW
#elif (PORT_PIN31 == NOT_SELECTED)
	/* No configuration selected for PIN31 */
#else
#error "InvalidConfig" /* Error for an invalid configuration for PIN31 */
#endif
#endif
#endif

	/**********************************************************SET DDR AND PORT Registers**********************************************************/
	/**********************************************************TWO_PORTS Case**********************************************************/
#if (NUM_OF_PORTS == TWO_PORTS)
	{
#if (NUM_OF_PINS == SIX_PINS)
		DDRA =  CONCAT_Six(PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
		PORTA = CONCAT_Six(PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
		DDRB =  CONCAT_Six(PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR,PIN6_DIR) ;
		PORTB = CONCAT_Six(PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT,PIN6_PORT) ;

#elif(NUM_OF_PINS==SEVEN_PINS)
		DDRA =  CONCAT_Seven(PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
		PORTA = CONCAT_Seven(PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
		DDRB =  CONCAT_Seven(PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR) ;
		PORTB = CONCAT_Seven(PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT) ;

#elif(NUM_OF_PINS==EIGHT_PINS)
		DDRA =  CONCAT(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
		PORTA = CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
		DDRB =  CONCAT(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR) ;
		PORTB = CONCAT(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT) ;
#endif

	}
	/**********************************************************THREE_PORTS Case**********************************************************/
#elif (NUM_OF_PORTS == THREE_PORTS)
#if (NUM_OF_PINS == SIX_PINS)
	DDRA	= CONCAT_Six(PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT_Six(PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT_Six(PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR,PIN6_DIR) ;
	PORTB 	= CONCAT_Six(PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT,PIN6_PORT) ;
	DDRC	= CONCAT_Six(PIN17_DIR,PIN16_DIR,PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR) ;
	PORTC 	= CONCAT_Six(PIN17_PORT,PIN16_PORT,PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT) ;

#elif(NUM_OF_PINS==SEVEN_PINS)
	DDRA 	= CONCAT_Seven(PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT_Seven(PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT_Seven(PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR) ;
	PORTC 	= CONCAT_Seven(PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT) ;
	DDRC 	= CONCAT_Seven(PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR,PIN15_DIR,PIN14_DIR) ;
	PORTC 	= CONCAT_Seven(PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT,PIN15_PORT,PIN14_PORT) ;

#elif(NUM_OF_PINS==EIGHT_PINS)
	DDRA	= CONCAT(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR) ;
	PORTB 	= CONCAT(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT) ;
	DDRC 	= CONCAT(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR) ;
	PORTC 	= CONCAT(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT) ;
#endif
}
/**********************************************************FOUR_PORTS Case**********************************************************/
#elif (NUM_OF_PORTS == FOUR_PORTS)
{

#if (NUM_OF_PINS == SIX_PINS)
	DDRA	= CONCAT_Six(PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT_Six(PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT_Six(PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR,PIN6_DIR) ;
	PORTB 	= CONCAT_Six(PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT,PIN6_PORT) ;
	DDRC	= CONCAT_Six(PIN17_DIR,PIN16_DIR,PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR) ;
	PORTC 	= CONCAT_Six(PIN17_PORT,PIN16_PORT,PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT) ;
	DDRD 	= CONCAT_Six(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR) ;
	PORTD 	= CONCAT_Six(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT) ;

#elif(NUM_OF_PINS==SEVEN_PINS)
	DDRA 	= CONCAT_Seven(PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT_Seven(PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT_Seven(PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR,PIN7_DIR) ;
	PORTC 	= CONCAT_Seven(PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT,PIN7_PORT) ;
	DDRC 	= CONCAT_Seven(PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR,PIN15_DIR,PIN14_DIR) ;
	PORTC 	= CONCAT_Seven(PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT,PIN15_PORT,PIN14_PORT) ;
	DDRD 	= CONCAT_Seven(PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_DIR,PIN23_DIR,PIN22_DIR,PIN21_DIR) ;
	PORTD 	= CONCAT_Seven(PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT,PIN23_PORT,PIN22_PORT,PIN21_PORT) ;

#elif(NUM_OF_PINS==EIGHT_PINS)
	DDRA 	= CONCAT(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR) ;
	PORTA 	= CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT) ;
	DDRB 	= CONCAT(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR) ;
	PORTB 	= CONCAT(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT) ;
	DDRC 	= CONCAT(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR) ;
	PORTC 	= CONCAT(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT) ;
	DDRD 	= CONCAT(PIN31_DIR,PIN30_DIR,PIN23_DIR,PIN28_DIR,PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_DIR) ;
	PORTD 	= CONCAT(PIN31_PORT,PIN30_PORT,PIN23_PORT,PIN28_PORT,PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT) ;
#endif
}
#else
{
	/* Error for an invalid configuration for SET PORT & DDR  Registers*/
#error "InvalidConfig"
}
#endif
#else
{
	/* Error for an invalid configuration for SET PORT & DDR  Registers*/
#error "InvalidConfig for Port Number"
}
#endif

/*If the User Choose  POST_Compile_Configuration*/
#elif (CONFIGURATION_TYPE==POST_Compile_Configuration)
{
	/* Iterate through all pins*/
	for (int i =0 ; i < (NUM_OF_PINS*NUM_OF_PORTS) ; i++ )
	{
		/* Determine the port number and pin number from the index*/
		PORT_enumPortNum_t Loc_enumPortNum = (PORT_enumPortNum_t)(i / NUM_OF_PINS) ;
		/* Determine the pin number and pin number from the index*/
		uint8 Loc_U8PinNum = (uint8)(i % NUM_OF_PINS) ;
		/*Switch based on the port number*/
		switch(Loc_enumPortNum)
		{
		case PORT_A:
		{
			/*Switch based on the pin configuration*/
			switch (PORT_PINcfg[i])
			{
			case PORT_enumINPUT_PU:
			{
				/*Set the pin as an input with pull-up enabled*/
				CLEAR_BIT(DDRA,Loc_U8PinNum);
				SET_BIT(PORTA,Loc_U8PinNum);
				break;
			}
			case PORT_enumINPUT_HI:
			{
				/*Set the pin as an input with high impedance*/
				CLEAR_BIT(DDRA,Loc_U8PinNum);
				CLEAR_BIT(PORTA,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_HIGH:
			{
				/*Set the pin as an output with high value*/
				SET_BIT(DDRA,Loc_U8PinNum);
				SET_BIT(PORTA,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_LOW:
			{
				/*Set the pin as an output with low value*/
				SET_BIT(DDRA,Loc_U8PinNum);
				CLEAR_BIT(PORTA,Loc_U8PinNum);
				break;
			}
			default :
				break ;	
			}
			break ;
		}
		case PORT_B:
		{
			/*Switch based on the pin configuration*/
			switch (PORT_PINcfg[i])
			{
			case PORT_enumINPUT_PU:
			{
				/*Set the pin as an input with pull-up enabled*/
				CLEAR_BIT(DDRB,Loc_U8PinNum);
				SET_BIT(PORTB,Loc_U8PinNum);
				break;
			}
			case PORT_enumINPUT_HI:
			{
				/*Set the pin as an input with high impedance*/
				CLEAR_BIT(DDRB,Loc_U8PinNum);
				CLEAR_BIT(PORTB,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_HIGH:
			{
				/*Set the pin as an output with high value*/
				SET_BIT(DDRB,Loc_U8PinNum);
				SET_BIT(PORTB,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_LOW:
			{
				/*Set the pin as an output with low value*/
				SET_BIT(DDRB,Loc_U8PinNum);
				CLEAR_BIT(PORTB,Loc_U8PinNum);
				break;
			}
			default :
				break ;	
			}
			break ;
		}
		case PORT_C:
		{
			/*Switch based on the pin configuration*/
			switch (PORT_PINcfg[i])
			{
			case PORT_enumINPUT_PU:
			{
				/*Set the pin as an input with pull-up enabled*/
				CLEAR_BIT(DDRC,Loc_U8PinNum);
				SET_BIT(PORTC,Loc_U8PinNum);
				break;
			}
			case PORT_enumINPUT_HI:
			{
				/*Set the pin as an input with high impedance*/
				CLEAR_BIT(DDRC,Loc_U8PinNum);
				CLEAR_BIT(PORTC,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_HIGH:
			{
				/*Set the pin as an output with high value*/
				SET_BIT(DDRC,Loc_U8PinNum);
				SET_BIT(PORTC,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_LOW:
			{
				/*Set the pin as an output with low value*/
				SET_BIT(DDRC,Loc_U8PinNum);
				CLEAR_BIT(PORTC,Loc_U8PinNum);
				break;
			}
			default :
				break ;	
			}
			break ;
		}
		case PORT_D:
		{
			/*Switch based on the pin configuration*/
			switch (PORT_PINcfg[i])
			{
			case PORT_enumINPUT_PU:
			{
				/*Set the pin as an input with pull-up enabled*/
				CLEAR_BIT(DDRD,Loc_U8PinNum);
				SET_BIT(PORTD,Loc_U8PinNum);
				break;
			}
			case PORT_enumINPUT_HI:
			{
				/*Set the pin as an input with high impedance*/
				CLEAR_BIT(DDRD,Loc_U8PinNum);
				CLEAR_BIT(PORTD,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_HIGH:
			{
				/*Set the pin as an output with high value*/
				SET_BIT(DDRD,Loc_U8PinNum);
				SET_BIT(PORTD,Loc_U8PinNum);
				break;
			}
			case PORT_enumOUTPUT_LOW:
			{
				/*Set the pin as an output with low value*/
				SET_BIT(DDRD,Loc_U8PinNum);
				CLEAR_BIT(PORTD,Loc_U8PinNum);
				break;
			}
			default :
				break ;	
			}
			break ;
		}
		default:
			break;
		}
	}
}
}
#endif



