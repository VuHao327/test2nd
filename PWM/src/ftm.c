/*
 * ftm.c
 *
 *  Created on: Oct 8, 2023
 *      Author: Admin
 */
#include "register.h"
#include "gpio.h"
#include "clock.h"
#include "ftm.h"
#include <stdint.h>
unsigned int C1V_Value;
void FTM0_CH1_PWM_init(void){
    /**
	 * FTM0 Clocking:
	 * ==================================================
	 */
	PCC->PCC_FTM0 &=~ (0x1u<<30u);		/* Ensure clk disabled for config */
	PCC->PCC_FTM0 |= (0x3u<<24u);		/* Clock Src option 3: FIRCDIV1_CLK = 12MHz  */
    PCC->PCC_FTM0 |= (0x1u<<30u);		/* Enable clock for FTM registers */
	/**
	 * FTM0 Initialization:
	 * ===================================================
	 *///Register writes must be done using 32-bit operations.

	FTM0->MODE = (0x1u<<2u)|(FTM0->MODE);  			/* Write Protection Disable - WPDIS = 1  */
	FTM0->SC   = (0x1u<<17)|(FTM0->SC); 			/* Enable PWM channel 1 output - bit 17 */
	FTM0->SC   = (0x2u)|(FTM0->SC); 				/* TOIE (Timer Overflow Interrupt Enable) = 0 (default) */
													/* CPWMS = 0 (default, Up Counting Mode) */
													/* PS (Prescaler factor) Prescaler = 4 - bit 210: 010 */
    FTM0->COMBINE = 0x00000000;	/* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0  */
	//MOD1 = (Clock_FTM / (Frequency_PWM * Prescaler)) - 1 = 12MHz/(2000*4) - 1 = 1500 - 1
	//MOD2 = (Clock_FTM / (Frequency_PWM * Prescaler)) - 1 = 12MHz/(4000*4) - 1 = 750 - 1

	FTM0->MOD = (1500-1);
	/**
	 * FTM0, Channel 1 in PWM Mode: Select PTD16 is output
	 * ==================================================
	 */
	// /* Enable clock for PORTD */
	// PCC->PCC_PORTD |= (1u << 30u);
	/* Set PORTD pin 16 for FTM0 - channel 1 - PTD16 - ALT2 */
	PORTD->PCR[16] |= (2u<<8u);
	/* Enable high-true pulses (clear Output on match) of PWM signals */
	FTM0->C1SC = (0x28)|(FTM0->C1SC);   	/*MSB = 1; ELSB = 1*/
	C1V_Value = (Duty_Value*1500)/100;
	FTM0->C1V = (C1V_Value);					/* FTM0 ch1 compare value (~50% duty cycle) */
	// /* Reset FTM counter */
	// FTM0->CNT = 0;
	/* CLKS (Clock source) = External Clock (FIRCDIV1_CLK = 12Mhz) bit 3-4: 11 */
	FTM0->SC   = (0x18u)|(FTM0->SC);
	State_PWM = 2;
}
void PWM_4k(void){
	FTM0->SC   = (0x2u)|(FTM0->SC); 				/* TOIE (Timer Overflow Interrupt Enable) = 0 (default) */
													/* CPWMS = 0 (default, Up Counting Mode) */
													/* PS (Prescaler factor) Prescaler = 4 - bit 210: 010 */
	FTM0->MOD = (750-1);
	C1V_Value = (Duty_Value*750)/100;
	FTM0->C1V = (C1V_Value);					/* FTM0 ch1 compare value (~50% duty cycle) */
	State_PWM = 4;
}	
void PWM_2k(void){
	FTM0->SC   = (0x2u)|(FTM0->SC); 				/* TOIE (Timer Overflow Interrupt Enable) = 0 (default) */
													/* CPWMS = 0 (default, Up Counting Mode) */
													/* PS (Prescaler factor) Prescaler = 4 - bit 210: 010 */
	FTM0->MOD = (1500-1);
	C1V_Value = (Duty_Value*1500)/100;
	FTM0->C1V = (C1V_Value);					/* FTM0 ch1 compare value (~50% duty cycle) */
	State_PWM = 2;
}
