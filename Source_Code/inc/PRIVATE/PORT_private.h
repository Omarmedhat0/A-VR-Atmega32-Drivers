/*
 ============================================================================
 Name        : PORT _private.h
 Author      : Omar Medhat Mohamed
 Description : Header File for the Private values that user will not modify on it 
 Date        : 3/12/2023
 ============================================================================
 */
#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

/* NUM_OF_PORTS Options  */
#define TWO_PORTS 	2
#define THREE_PORTS 3
#define FOUR_PORTS 	4

/* NUM_OF_PINS Options  */
#define ONE_PIN 			1
#define TWO_PINS 			2
#define THREE_PINS			3
#define FOUR_PINS			4
#define FIVE_PINS			5
#define SIX_PINS			6
#define SEVEN_PINS			7
#define EIGHT_PINS			8
#define NINE_PINS       	9
#define TEN_PINS        	10
#define ELEVEN_PINS     	11
#define TWELVE_PINS     	12
#define THIRTEEN_PINS   	13
#define FOURTEEN_PINS   	14
#define FIFTEEN_PINS    	15
#define SIXTEEN_PINS    	16
#define SEVENTEEN_PINS  	17
#define EIGHTEEN_PINS   	18
#define NINETEEN_PINS   	19
#define TWENTY_PINS     	20
#define TWENTY_ONE_PINS 	21
#define TWENTY_TWO_PINS 	22
#define TWENTY_THREE_PINS 	23
#define TWENTY_FOUR_PINS  	24
#define TWENTY_FIVE_PINS  	25
#define TWENTY_SIX_PINS   	26
#define TWENTY_SEVEN_PINS 	27
#define TWENTY_EIGHT_PINS 	28
#define TWENTY_NINE_PINS  	29
#define THIRTY_PINS       	30
#define THIRTY_ONE_PINS   	31
#define THIRTY_TWO_PINS   	32

/*Post_&Pre_CONFIGURATION Options */
#define Pre_Compile_Configuration LOGIC_HIGH
#define POST_Compile_Configuration LOGIC_LOW

/*PIN_CONFIGURATION Options */
#define INPUT_PU 	1
#define INPUT_HI 	2
#define OUTPUT_HIGH 3
#define OUTPUT_LOW 	4
#define NOT_SELECTED 0xFF

#define BINARY_HELPER(p7,p6,p5,p4,p3,p2,p1,p0) ((p7 << 7) | (p6 << 6) | (p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER(p7,p6,p5,p4,p3,p2,p1,p0) BINARY_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONCAT(p7,p6,p5,p4,p3,p2,p1,p0)	CONCAT_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)

#define BINARY_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0) ( (p6 << 6) | (p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0) BINARY_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)
#define CONCAT_Seven(p6,p5,p4,p3,p2,p1,p0)	CONCAT_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)

#define BINARY_HELPER_Six(p5,p4,p3,p2,p1,p0) ((p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER_Six(p5,p4,p3,p2,p1,p0) BINARY_HELPER_Six(p5,p4,p3,p2,p1,p0)
#define CONCAT_Six(p5,p4,p3,p2,p1,p0)	CONCAT_HELPER_SIx(p5,p4,p3,p2,p1,p0)
#endif
