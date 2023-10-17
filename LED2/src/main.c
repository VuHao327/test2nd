// LED GREEN : PTD16
/*******************************************************************************/
#include <stdint.h>
#define  PCC_Base 				(0x40065000U)        // PCC = Peripheral Clock Controller
#define  PCC_PORTD_Offset 		(0x130U)
#define  PCC_PORTD_Base 		*((volatile int*) (PCC_Base + PCC_PORTD_Offset))
#define  PCC_PORTD_Enable 		(0x1U<<30)

#define  PORTD_Base				(0x4004C000U)
#define  PORT_PCR16_MUX			*((volatile int*) (PORTD_Base + 0x40U))

#define  GPIOD_Base				(0x400FF0C0U)
#define  GPIO_PDDR_Offset		(0x14U)
#define  GPIO_PDDR_Base 		*((volatile int*) (GPIOD_Base + GPIO_PDDR_Offset))
#define  GPIO_PDDR_OUTPUT		(0x1U<<16)

#define  GPIO_PDOR_Base 		*((volatile int*) (GPIOD_Base))
#define  LED_PIN16				(1U<<16)
#define  GPIO_PTOR_Base 		*((volatile int*) (GPIOD_Base + 0xC))
/*
 * set bit 10 to 0: & =~ (1U<<10)
 * set bit 9 to 0: & =~ (1U<<9)
 * set bit 8 to 1: = (1U<<8)
*/
int main(void){
	/*1. Enable Clock for Port D*/
	PCC_PORTD_Base |= PCC_PORTD_Enable;
	/*2. Set pin16 as GPIO*/
	PORT_PCR16_MUX |= (1U<<8);
	/*3. Set pin16 as OUTPUT*/
	GPIO_PDDR_Base |= GPIO_PDDR_OUTPUT;
	/*4. Set LED on*/
	while(1){
		GPIO_PDOR_Base ^= LED_PIN16;
		for (int i=300000;i>0;i--){}
	}
}
