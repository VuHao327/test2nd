/*
 * lpit.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Admin
 */
#include  "lpit.h"
#include  "register.h"
#include  "gpio.h"
#include  "lpuart.h"
#include  <stdio.h>
char buffer[100]; // "buffer" will contain the value of CounterVariable which transmit from INTEGER to STRING
void LPIT0_Init(void)
{
    /*Enable NVIC for LPIT channel 0 - S32K144_DMA_Interrupt_Mapping.excel
	NVIC Interrupt ID - LPIT channel 0 = 48
    48 mod 32 = 16 => NVICISER1[16] - NVIC interrupt set enable register*/
	NVIC->ISER[1] |= (1u<<16u);
	NVIC->ISER[1] |= (1u<<17u);
	
	/*Clock sourse select (PCS) -  bit 24-26: 011b - option 3 = FIRCDIV2_CLK*/
	PCC->PCC_LPIT |= (3u<<24u);
	
	/*Enable clock - bit 30: 1*/
	PCC->PCC_LPIT |= (1u<<30u);

    /*Module Control Register: MCR(M_CEN) - Enable Module Clock - bit 0: 1*/
	LPIT->LPIT_MCR |= (1u<<0u);
	
	/*Timer continue run in Debug mode: MCR(DBG_EN) - bit 3: 1*/
	LPIT->LPIT_MCR |= (1u<<3u);
	
	/*Channel 0 Timer Interrupt Enable: MIER(TIE0) - bit 0: 1*/
	LPIT->LPIT_MIER |= (1u<<0u);

	/*Channel 0: TVAL0 - Set Timer value*/
	LPIT->LPIT_TVAL0 = (0x493E00); //FIRCDIV2_CLK = 48 Mhz => Timer Value = 4800000 = 0.1 second
	/*Channel 1: TVAL1 - Set Timer value*/
	LPIT->LPIT_TVAL1 = (0x16E3600); //FIRCDIV2_CLK = 48 Mhz => Timer Value = 24000000 = 0.5 second

	/*Channel 0: TCTRL0 - Timer Operation Mode - (MODE) - bit 2-3: 00 - 32 bit Periodic Counter*/
	LPIT->LPIT_TCTRL0 &= ~(3u<<2u);
	/*Channel 1: TCTRL1 - Timer Operation Mode - (MODE) - bit 2-3: 00 - 32 bit Periodic Counter*/
	LPIT->LPIT_TCTRL1 &= ~(3u<<2u);
	
	/*Channel 0: TCTRL0 - Timer Enable - (T_EN) - bit 0: 1*/
	LPIT->LPIT_TCTRL0 |= (1u<<0u);
	LPIT->LPIT_TCTRL1 |= (1u<<0u);
}
void LPIT0_Ch0_IRQHandler (void)
{
	Counter_Flag++;
	Flag_UART++;
    /*Clear Flag interrupt Timer0*/
	LPIT->LPIT_MSR = 0x1;
}
// void LPIT1_Init(void)
// {
//     /*Enable NVIC for LPIT channel 1 - S32K144_DMA_Interrupt_Mapping.excel
// 	NVIC Interrupt ID - LPIT channel 1 = 49
//     49 mod 32 = 17 => NVICISER1[17] - NVIC interrupt set enable register*/
// 	NVIC->ISER[1] |= (1u<<17u);
	
// 	//Already setting in LPIT channel 0
// 	// /*Clock sourse select (PCS) -  bit 24-26: 011b - option 3 = FIRCDIV2_CLK*/
// 	// PCC->PCC_LPIT |= (3u<<24u);
// 	// /*Enable clock - bit 30: 1*/
// 	// PCC->PCC_LPIT |= (1u<<30u);
//     // /*Module Control Register: MCR(M_CEN) - Enable Module Clock - bit 0: 1*/
// 	// LPIT->LPIT_MCR |= (1u<<0u);
// 	// /*Timer continue run in Debug mode: MCR(DBG_EN) - bit 3: 1*/
// 	// LPIT->LPIT_MCR |= (1u<<3u);
	
// 	/*Channel 1 Timer Interrupt Enable: MIER(TIE1) - bit 1: 1*/
// 	LPIT->LPIT_MIER |= (1u<<1u);

// 	/*Channel 1: TVAL1 - Set Timer value*/
// 	LPIT->LPIT_TVAL1 = (0x16E3600); //FIRCDIV2_CLK = 48 Mhz => Timer Value = 24000000 = 0.5 second

// 	/*Channel 1: TCTRL1 - Timer Operation Mode - (MODE) - bit 2-3: 00 - 32 bit Periodic Counter*/
// 	LPIT->LPIT_TCTRL1 &= ~(3u<<2u);
	
// 	/*Channel 1: TCTRL1 - Timer Enable - (T_EN) - bit 0: 1*/
// 	LPIT->LPIT_TCTRL1 |= (1u<<0u);
// }
// void LPIT0_Ch1_IRQHandler(void){
// 	sprintf(buffer, "%d", CounterVariable); // Change from INTEGER to STRING
// 	LPUART1_transmit_string(buffer);
// 	/*Clear Flag interrupt Timer1*/
// 	LPIT->LPIT_MSR = 0x2;
// }
