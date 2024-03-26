 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: Common_Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Omar Medhat
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

// Get bit BIT in REG           
#define GET_BIT(REG,BIT) ((REG >> BIT) & 0x01)
          
// Set high nibble in REG
#define SET_HIGH_NIB(REG) ((REG) |= 0xF0)
// Clear high nibble in REG          
#define CLR_HIGH_NIB(REG) ((REG) &= 0x0F)
// Get high nibble in REG          
#define GET_HIGH_NIB(REG)  (((REG) >> 4) & 0x0F)
// Toggle high nibble in REG       
#define TGL_HIGH_NIB(REG) ((REG) ^= 0xF0)
// Set low nibble in REG         
#define SET_LOW_NIB(REG) ((REG) |= 0x0F)
// Clear low nibble in REG           
#define CLR_LOW_NIB(REG) ((REG) &= 0xF0)
// Get low nibble in REG            
#define GET_LOW_NIB(REG) ((REG) & 0x0F)
// Toggle low nibble in REG            
#define TGL_LOW_NIB(REG)       ((REG) ^= 0x0F)              

// Assign VALUE to REG
#define ASSIGN_REG(REG,VALUE)   ((REG) = (VALUE))   
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG,VALUE) ((REG) = (((REG) & 0x0F) | ((VALUE) << 4)))
// Assign VALUE to low nibble REG 
#define ASSIGN_LOW_NIB(REG,VALUE) ((REG) = (((REG) & 0xF0) | ((VALUE) & 0x0F)))
// Right shift by NO in REG
#define RSHFT_REG(REG, NO) ((REG) >>= (NO))
// Left shift by NO in REG
#define LSHFT_REG(REG, NO) ((REG) <<= (NO))         
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO) (REG= ((REG) >> (NO)) | ((REG) << (8 - (NO))))
// Circular left shift by NO in REG
#define CLSHFT_REG(REG,NO)  (REG=((REG) << (NO)) | ((REG) >> (8 - (NO))))    


#endif
