/*
 * gpio.c
 *
 *  Created on: Oct 1, 2023
 *      Author: Admin
 */
#include "register.h"
#include "gpio.h"

void BUTTON_Init(void)
{
	/* Pins definitions
	 * ===================================================
	 * Pin number        | Function
	 * ----------------- |------------------
	 * PTC12             | GPIO [BUTTON1]
	 * PTC13             | GPIO [BUTTON2]
	 */
	/*Enable Clock for Port C*/
	PCC->PCC_PORTC |= (1u << 30u); 

	/*Set pin as GPIO function - BUTTON at pin12, pin13 - MUX: bits 8-10*/
	PORTC->PCR[BUTTON1] |= (1u << 8u);
	PORTC->PCR[BUTTON2] |= (1u << 8u);

	/*Disable Pull-up/pull-down - PE: bit 1*/
	PORTC->PCR[BUTTON1] &= ~(1u << 1u); 
	PORTC->PCR[BUTTON2] &= ~(1u << 1u); 

	/*Set interrupt type - IRQC: bit 16-19 - interrupt falling edge*/
	PORTC->PCR[BUTTON1] |= (10u << 16u); 
	PORTC->PCR[BUTTON2] |= (10u << 16u); 

	/*Set input Pin - pin12,pin13*/
	GPIOC->PDDR &=~ (1u << BUTTON1); 
	GPIOC->PDDR &=~ (1u << BUTTON2); 
}

void LED_Init(void)
{
	/* Pins definitions
	 * ===================================================
	 * Pin number        | Function
	 * ----------------- |------------------
	 * PTD0              | GPIO [BLUE LED]
	 * PTD15             | GPIO [RED LED]
	 * PTD16             | GPIO [GREEN LED]
	 */

	/*Enable Clock for Port D*/
	PCC->PCC_PORTD |= (1u << 30u);

	/*Set pins as GPIO function*/
	PORTD->PCR[LED_BLUE]	|= (1 << 8u);
	PORTD->PCR[LED_RED]		|= (1 << 8u);
	PORTD->PCR[LED_GREEN]	|= (1 << 8u);

	/*Set pins as output pin*/
	GPIOD->PDDR |= (1 << 0u);
	GPIOD->PDDR |= (1 << 15u);
	GPIOD->PDDR |= (1 << 16u);
}

void CLKOUT_Init(void)
{
		/* Pins definitions
	 * ===================================================
	 * Pin number        | Function
	 * ----------------- |------------------
	 * PTE10             | ClockOut
	 */
	/*Enable Clock for Port E*/
	PCC->PCC_PORTE	|=	(1u	<<	30u);

	/*Set pin10 as Alternative 2 - CLKOUT*/
	PORTE->PCR[PIN10]	|=	(2u	<<	8u);

}



void Gpio_SetPinValue(GPIO_Type *GPIO_Port, E_GPIO_Pin_Type GPIO_PinNum_E, const unsigned int GPIO_Value)
{
	if (GPIO_Value == 1u)
	{
		GPIO_Port->PDOR |= (1u << GPIO_PinNum_E);
	}
	else if (GPIO_Value == 0u)
	{
		GPIO_Port->PDOR &= ~(1u << GPIO_PinNum_E);
	}
}

void Gpio_GetPinValue(GPIO_Type *GPIO_Port, E_GPIO_Pin_Type GPIO_PinNum_E, unsigned int *GPIO_value)
{
	*GPIO_value = (GPIO_Port->PDIR >> GPIO_PinNum_E) & 1u;
}


unsigned int Port_ReadBitValue(PORT_Type *PORT_PCRn, E_GPIO_Pin_Type PORT_PinNum_E, unsigned int PORT_BitField)
{
	unsigned int Bit_Value = (PORT_PCRn->PCR[PORT_PinNum_E] >> PORT_BitField & 1u);

	return Bit_Value;
}


void Port_WriteBitValue(PORT_Type *PORT_PCRn, E_GPIO_Pin_Type PORT_PinNum_E, unsigned int PORT_BitField, unsigned int PORT_Value)
{
	if (PORT_Value == 1u)
	{
		PORT_PCRn->PCR[PORT_PinNum_E] |= (1u << PORT_BitField);
	}
	else
		PORT_PCRn->PCR[PORT_PinNum_E] &= ~(1u << PORT_BitField);
}

void Gpio_ClearAllLed(void)
{
	Gpio_SetPinValue(GPIOD, PIN0, LEVEL_HIGH);	/*  Turn off led_blue */
	Gpio_SetPinValue(GPIOD, PIN15, LEVEL_HIGH); /*  Turn off led_red  */
	Gpio_SetPinValue(GPIOD, PIN16, LEVEL_HIGH); /*  Turn off led_green  */
}


void Gpio_ToggleLed (void)
{
	GPIOD->PDOR ^= (1u<<0u);
}



void PORTC_IRQHandler(void)
{

		/* Check interrupt flag of BUTTON1 */
    if (Port_ReadBitValue(PORTC,PIN12,24u))
    {
			Port_WriteBitValue(PORTC, PIN12, 24u, LEVEL_HIGH);	/* Clear interrupt flag for BUTTON1 - Write 1 to clear */
			Gpio_SetPinValue(GPIOD, PIN0, LEVEL_LOW);	/*  Turn off led_blue */
			Gpio_SetPinValue(GPIOD, PIN15, LEVEL_HIGH); /*  Turn off led_red  */
			Gpio_SetPinValue(GPIOD, PIN16, LEVEL_HIGH); /*  Turn off led_green  */

    }
		/* Check interrupt flag of BUTTON2 */
    if (Port_ReadBitValue(PORTC,PIN13,24u))
    {
			Port_WriteBitValue(PORTC, PIN13, 24u, LEVEL_HIGH); /* Clear interrupt flag for BUTTON2 - Write 1 to clear	*/
			Gpio_SetPinValue(GPIOD, PIN0, LEVEL_HIGH);	/*  Turn off led_blue */
			Gpio_SetPinValue(GPIOD, PIN15, LEVEL_LOW); /*  Turn off led_red  */
			Gpio_SetPinValue(GPIOD, PIN16, LEVEL_HIGH); /*  Turn off led_green  */

    }
}

