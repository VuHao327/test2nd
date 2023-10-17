/*
 * lpuart.c
 *
 *  Created on: Oct 4, 2023
 *      Author: Admin
 */
#include  "lpuart.h"


void LPUART1_Init(void)
{
    /*Enable Clock for Port C (PTC6&7)*/
    PCC->PCC_PORTC   |= (1u<<30u);  
    /*Set alternate function - ALT2 - file excel_pinout*/         
    PORTC->PCR[6]    |= (2u<<8u);           
    PORTC->PCR[7]    |= (2u<<8u);           
    /*Select Clock source - FIRCDIV2*/
    PCC->PCC_LPUART1  |=  (3u<<24u);      
    /*Enable Clock for UART*/
    PCC->PCC_LPUART1  |=  (1u<<30u);     
    //SELECT BAUD RATE = 9600
    /*Select Oversampling ratio - select 16*/
    LPUART1->BAUD &=(~( 0x1fu<<24u) | (15<<24));
    LPUART1->BAUD &=~ (0x1fffu);                     /* Clear */
    /*Set the Baud Rate Modulo Divisor - (1,8191) - select 78*/
    LPUART1->BAUD |= 312u;
    /*Select Stop bit number - 1 stop bit*/
    LPUART1->BAUD &=~ (0x1u<<13);
    /*Set Data character number - 8 bit format*/
    LPUART1->CTRL &=~ (0x1u<<4);
    /*Set parity bit - no parity*/
    LPUART1->CTRL &=~ (0x1u<<1);
	/*Transmitter Enable*/
    LPUART1->CTRL |= (0x1u<<19);
    /*Receiver enable*/
    LPUART1->CTRL |= (0x1u<<18);
}

void LPUART1_transmit_char(char send) {    /* Function to Transmit single Char */
	while((LPUART1->STAT & (1u << 23)) == 0); /* Wait for transmit buffer to be empty */
	LPUART1->DATA = send;             
}
void LPUART1_transmit_string(char string[]) {  /* Function to Transmit string */
	uint32_t i=0;
	while(string[i] != '\0')  {           /* Send chars one at a time */
		LPUART1_transmit_char(string[i]);
		i++;
	}
}
void LPUART0_RxTx_IRQHandler(){

}


