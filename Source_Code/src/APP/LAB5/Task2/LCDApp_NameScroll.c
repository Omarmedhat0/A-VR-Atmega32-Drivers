/*
 ============================================================================
 Name        : Digital_Timer_Design.c
 Author      : Omar Medhat Mohamed
 Description : Source file for Digital Timer Design
 Date        : 18/12/2023
 ============================================================================
 */
#include "APP/CTRMain.h"
#ifdef LAB5_TASK2
#include "HAL/LCD.h"
#include "LIB/Delay.h"
#define NAME_SIZE	12

int main(void)
{
	/* Initialize the LCD */
	LCD_INIT();

	/* Define a name and variables */
	uint8 Name[NAME_SIZE]="Omar Medhat";
	uint8 counter =0 ;
	uint8 flag = 0 ;
	uint8* ptr = Name ;
	while(1)
	{

		  /* Check if the counter reaches the end of the LCD line */
	    if (counter == 16)
	    {
	    		/* flag by one to start move from righ to left*/
	        	flag = 1;
	         /* Clear the LCD and delay */
		      LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
		      delay(150);
		      /* Decrement the counter to start moving left */
		      counter--;
	    }

	    /* Check if the flag is not set (moving right) */
	    else if (flag == 0)
	    {
	    		/* Move to the next position, display the name, and delay */
	        	LCD_enuGotoDDRAM_XY(LCD_DISPLAY_LINE1, counter);
	       	LCD_enuWriteString(Name, NAME_SIZE);
	       	delay(150);
	         /* Clear the LCD after displaying */
	        	LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
	        	/* Increment the counter to continue moving right */
	        	counter++;
	    }
	    /* Check if the flag is set (moving left) */
	    else if ((flag == 1)&&(counter>0))
	    {
	    		/* Move to the previous position, display the name, and delay */
	       	LCD_enuGotoDDRAM_XY(LCD_DISPLAY_LINE1, counter);
	        	LCD_enuWriteString(Name, NAME_SIZE);
	        	delay(150);
	        	/* Clear the LCD after displaying */
	        	LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
	        	/* Decrement the counter to continue moving left */
	        	counter--;
	    }
	    /* Check if the flag is set and the counter is at the beginning */
	    else if ((flag == 1)&&(counter==0))
        {
        		/* Move the pointer to the next character in the name */
            ptr++;
            /* Check if the end of the name is reached */
            if (*ptr == '\0')
            {
            	 /* Clear the LCD and delay */
            	 LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
            	 delay(150);
            	 /* Loop through the name characters and display them in reverse order */
            	 for (uint8 itr =0 ; itr<(NAME_SIZE-2) ; itr ++)
            	 {
            	 	 /* Move the pointer back */
            		 ptr--;
            		 /* Display the substring of the name and delay */
            		 LCD_enuGotoDDRAM_XY(LCD_DISPLAY_LINE1, 0);
                   LCD_enuWriteString(ptr, NAME_SIZE);
                   delay(150);
                   /* Clear the LCD after displaying */
                   LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
            	 }
            	 /* Reset the flag and pointer to the beginning of the name */
            	 flag = 0 ;
            	 ptr = Name ;
            }
            else
            {
            /* Display the substring of the name and delay */
            LCD_enuGotoDDRAM_XY(LCD_DISPLAY_LINE1,counter);
            LCD_enuWriteString(ptr, NAME_SIZE);
            delay(150);
            /* Clear the LCD after displaying */
            LCD_enuWriteCommand(LCD_CLEAR_COMMAND);
            }
        }
	}
	return 0;
}
#endif