/*
 * gpio.h
 *
 *  Created on: Oct 1, 2023
 *      Author: Admin
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "register.h"
/** =================Define===========================	*/

#define	LED_BLUE			(0u)
#define	LED_RED				(15u)
#define LED_GREEN			(16u)
#define	BUTTON1				(12u)
#define BUTTON2				(13u)

#define	LEVEL_HIGH			(1u)
#define	LEVEL_LOW			(0u)

/** =================Variable===========================	*/


/** =================Type===========================	*/
typedef enum	GPIO_Pin_Type
{
	PIN0 = 0u,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31
} E_GPIO_Pin_Type;

/** ===================Prototype===========================	*/
void PORTC_IRQHandler(void);
void BUTTON_Init(void);
void LED_Init(void);
void Gpio_SetPinValue(GPIO_Type *GPIO_Port, E_GPIO_Pin_Type GPIO_PinNum_E, const unsigned int GPIO_Value);
void Gpio_GetPinValue(GPIO_Type *GPIO_Port, E_GPIO_Pin_Type GPIO_PinNum_E, unsigned int *GPIO_value);
unsigned int Port_ReadBitValue(PORT_Type *PORT_PCRn, E_GPIO_Pin_Type PORT_PinNum_E, unsigned int PORT_BitField);
void Port_WriteBitValue(PORT_Type *PORT_PCRn, E_GPIO_Pin_Type PORT_PinNum_E, unsigned int PORT_BitField, unsigned int PORT_Value);

void Gpio_ClearAllLed(void);

void Gpio_ToggleLed (void);

void CLKOUT_Init(void);


#endif /* GPIO_H_ */
