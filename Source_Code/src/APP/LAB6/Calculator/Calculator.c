/*
 ============================================================================
 Name        : Calculator.c
 Author      : Omar Medhat Mohamed
 Description : Source file for the Calculator Application
 Date        : 10/2/2024
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB6_TASK1
#include "APP/Calculator.h"
int main(void)
{
	/*Local Variable to hold which key is pressed*/
	uint8 getchar ;
	/*Local Variable to handle Debounce*/
	uint8 prevkey = Debounce_Handler ;
	/*Buffer Array to hold Operand one value */
	uint8 Operand1Arr[OP1_SIZE]="";
	/*Buffer Array to hold Operand two value */
	uint8 Operand2Arr[OP2_SIZE]="";
	/*Local Variable to hold the type of desired operation which pressed from keypad*/
	uint8 operationtype = 0;
	/*Index to opeerand 1 buffer array*/
	uint8 Oper1index = 0 ;
	/*Index to opeerand 2 buffer array*/
	uint8 Oper2index = 0 ;
	/*Local Variable to hold the value of operand one in integral form*/
	uint16 Operand1 =0  ;
	/*Local Variable to hold the value of operand two in integral form*/
	uint16 Operand2 =0 ;
	/*Local Variable to hold the value of the result in integral form*/
	uint16 result = 0;
	/*Flag to state in which operand the user will type the current number*/
	uint8 flag = 0 ;
	/*Flag to prevent user from writing on operand one after the first process*/
	uint8 flag2 = 0 ;
	/*Initiate LCD and Keypad drivers*/
	LCD_INIT();
	Keypad_INIT();
	/*Programe Loop*/
	while(1)
	{
		/*Wait unilt user enter an character*/
		Keypad_enuGetKey(&getchar);
		/*Check debouncy*/
		if (prevkey == getchar)
		{
			// Same key is pressed again, wait for debouncing
			delay(1000);
			/*Assign the value of Debounce_Handler in prev key to take another from 0:9 only
			 and not not equal '+'or '-' or '*' or '/' or '='
			 */
		}
		/*Wait unilt user enter an character*/
		Keypad_enuGetKey(&getchar);
		/*First senario to enter first operand*/
		if ( (flag == 0) &&(getchar>=0 && getchar<=9) )
		{
			/* Write the current numer on LCD*/
			LCD_enuWriteNumber(getchar);
			/*Save the number that has been entered by user in the buffer array*/
			Operand1Arr[Oper1index] = getchar;
			/*Increament the index of first buffer array*/
			Oper1index ++ ;

		}
		/*Second senario to enter Second operand*/
		else if ( (flag == 1) &&(getchar>=0 && getchar<=9) )
		{
			/* Write the current numer on LCD*/
			LCD_enuWriteNumber(getchar);
			/*Save the number that has been entered by user in the buffer array*/
			Operand2Arr[Oper2index] = getchar;
			/*Increament the index of first buffer array*/
			Oper2index ++ ;
		}
		/*Handle the operation type*/
		else if ((getchar=='+') || (getchar=='-') || (getchar=='/') || (getchar=='*') )
		{
			/* Write the operation numer on LCD*/
			LCD_enuWriteData(getchar);
			/*Save the operation that has been entered by user in the operaton type variable*/
			operationtype = getchar ;
			/* Set flag by one to give the access to user to start to enter operand 2 */
			flag = 1 ;
		}
		/* When User request the result senario*/
		else if (getchar=='=')
		{
			/*Clear the screen*/
			LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
			/* Check if it's first time to enter operands or not*/
			if (flag2==0)
			{
				/*convert the number in the buffer array 1 into integral number*/
				for (int index =0 ; index<Oper1index;index++)
				{
					Operand1 = Operand1*10+Operand1Arr[index];
				}
			}
			/*Convert the number in the buffer array 2 into integral number*/
			for (int index =0 ; index<Oper2index;index++)
			{
				Operand2 = Operand2*10+Operand2Arr[index];
			}
			/*Switch on the opeartion that has been set*/
			switch (operationtype)
			{
			/*Add case to add operand 1 to operand 2*/
			case '+':
				result = Operand1 + Operand2 ;
				break ;
			/*Subtarct case to Subtarct operand 2 from operand 1*/
			case '-':
				result = Operand1 - Operand2 ;
				break ;
			/*Divide case to Divide 1 with operand 2*/
			case '/':
				result = (uint64)Operand1 / Operand2 ;
				break ;
			/*Multiplication case to Multiply 1 with operand 2*/
			case '*':
				result = Operand1 * Operand2 ;
				break ;
			default :
				break ;
			}
			/*Print the result on screen*/
			LCD_enuWriteNumber(result);
			/*Set the result to operand 1 for the next opration*/
			Operand1 = result;
			/*Set flag 2 by one to prevent the app from Re-convert the buffer array 
			 of opeerand 1 to integral value
			*/
			flag2=1;
			/*Reset operand1 and 2 indexes and operand 2 value*/
			Oper1index =0 ;
			Oper2index =0 ;
			Operand2 = 0 ;
		}
		/*Clear the result the previous operation case */
		else
		{
			/*Clear Screen*/
			LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
			/*Reset all flags and variables*/
			flag =0 ;
			flag2 = 0 ;
			Oper1index =0 ;
			Oper2index =0 ;
			Operand1 = 0 ;
			Operand2 = 0 ;


		}
		/*Debounce handler*/
		prevkey = getchar;

	}
	return 0 ;
}



#endif