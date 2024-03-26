/*
 ============================================================================
 Name        : DIO_Reg_Add.h
 Author      : Omar Medhat Mohamed
 Description : Header file for register addresses
 Date        : 27/11/2023
 ============================================================================
 */

#ifndef Reg_Add_H_
#define Reg_Add_H_
#include "std_types.h"
#define DDRA *((volatile uint8 *)0x3A)
#define DDRB *((volatile uint8 *)0x37)
#define DDRC *((volatile uint8 *)0x34)
#define DDRD *((volatile uint8 *)0x31)

#define PORTA *((volatile uint8 *)0x3B)
#define PORTB *((volatile uint8 *)0x38)
#define PORTC *((volatile uint8 *)0x35)
#define PORTD *((volatile uint8 *)0x32)

#define PINA *((volatile uint8 *)0x39)
#define PINB *((volatile uint8 *)0x36)
#define PINC *((volatile uint8 *)0x33)
#define PIND *((volatile uint8 *)0x30)

#define MCUCR	*((volatile uint8 *)0x55)
#define MCUCSR	*((volatile uint8 *)0x54)
#define GICR	*((volatile uint8 *)0x5B)
#define SREG	*((volatile uint8 *)0x5F)

#define TCCR0   *((volatile uint8 *)0x53)
#define TCNT0   *((volatile uint8 *)0x52) 
#define OCR0   *((volatile uint8 *)0x5C)    
#define TIMSK   *((volatile uint8 *)0x59)  
#define TIFR   *((volatile uint8 *)0x58) 

#define SFIOR   *((volatile uint8 *)0x50)
#define TCCR1A  *((volatile uint8 *)0x4F)
#define TCCR1B  *((volatile uint8 *)0x4E)
#define	TCNT1	*((volatile uint8 *)0x4C)
#define TCNT1H  *((volatile uint8 *)0x4D)
#define TCNT1L  *((volatile uint8 *)0x4C)
#define OCR1A  	*((volatile uint8 *)0x4A)
#define OCR1AH  *((volatile uint8 *)0x4B)
#define OCR1AL  *((volatile uint8 *)0x4A)
#define OCR1B	*((volatile uint8 *)0x48)
#define OCR1BH  *((volatile uint8 *)0x49)
#define OCR1BL  *((volatile uint8 *)0x48)
#define ICR1H   *((volatile uint8 *)0x47)
#define ICR1L   *((volatile uint8 *)0x46)
#define TCCR2   *((volatile uint8 *)0x45)
#define TCNT2   *((volatile uint8 *)0x44)
#define OCR2    *((volatile uint8 *)0x43)

/**************************************************/
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#define OCF2    7 
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3   
#define TOV1    2
#define OCF0    1   
#define TOV0    0

#define FOC0    7 
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2   
#define CS01    1
#define CS00    0


#define ADTS2   7 
#define ADTS1   6
#define ADTS0   5
#define ACME    3
#define PUD     2
#define PSR2    1
#define PSR10   0

#define COM1A1  7 
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2   
#define WGM11   1
#define WGM10   0

#define ICNC1   7 
#define ICES1   6
#define WGM13   4 
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2   
#define CS21    1
#define CS20    0

#endif /*Reg_Add_H_ */
