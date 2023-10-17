/*
 * lpuart.h
 *
 *  Created on: Oct 4, 2023
 *      Author: Admin
 */

#ifndef LPUART_H_
#define LPUART_H_
#include "register.h"
/** ===================Prototype===========================	*/
void LPUART1_Init(void);
void LPUART1_transmit_char(char send);
void LPUART1_transmit_string(char string[]);

#endif /* LPUART_H_ */
