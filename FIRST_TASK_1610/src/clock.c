/*
 * clock.c
 *
 *  Created on: Oct 1, 2023
 *      Author: Admin
 */
#include  "clock.h"

void SOSC_Init(void)	/*	8Mhz*/
{
	/*only write in SCG register when write in all 32-bits*/
    /*1. Check Unlock SCG_SOSCCSR register*/
	while(SCG->SOSCCSR & (1u<<23u));
    /*2. Disable SOSC to set SOSC with internal crystal oscillator = 8Mhz*/
	SCG->SOSCCSR = (0x00000000);

	/*Set SOSCCFG with internal crystal - bit 2
	SOSC Range Select - High frequency range - bit 4,5
	Power mode of crystal oscillator - High gain operation - bit 3*/
	SCG->SOSCCFG = (0xFU<<2);
    // SCG->SOSCCFG = (1U<<2)|(SCG->SOSCCFG);
    // SCG->SOSCCFG = (3U<<4)|(SCG->SOSCCFG);
    // SCG->SOSCCFG = (1U<<3)|(SCG->SOSCCFG);

    /*3. Enable SOSC*/
	SCG->SOSCCSR = (0x1u<<0)|(SCG->SOSCCSR);
    /*4. Set SCG_SOSCDIV2 - choose divide by 2 - set bit 10-8: 010*/
    SCG->SOSCDIV = (2U<<8)|(SCG->SOSCDIV);

    //***************************************************************************
    /*Divide 2 times: both divide by 2 => CLK_OUT = 2Mhz*/
    //***************************************************************************
}

void SPLL_Init(void)	/*	48Mhz	*/
{
    /*	For any writeable SCG registers, only 32-bits writes are allowed */
    /*1. SPLL Config Status Register - UNLOCK*/
	while (SCG->SPLLCSR &(1u<<23u)) {}

    /*2. Disable SPLL to can change in SPLLCFG register*/
	SCG->SPLLCSR  = (0x00000000);

	/*3. Choose SPLLDIV2 - in SPLL disable state - divide by 2*/
	SCG->SPLLDIV = (0x201);

	/*4. Set PLL configuration
	Choose MULT is 24 - bit 20-16: 01000 
	Choose PREDIV is 8 - bit 10-8:  111
	Input clock source for SPLL is FIRC:  SPLL_SOURCE = FIRC = 48 MHz - bit 0: 1*/
	SCG->SPLLCFG = (0x80701);

	/*5. Enable SPLL*/
	SCG->SPLLCSR = (0x00000001);

}

void DisplayCLKOUT(unsigned int ClockSource)
{
	/*Disable CLK_OUT: bit 11  = 0*/
	SIM->CHIPCTL &= ~(1u<<11u);

	/* Wait clockOutEn == 0	*/
	while ((SIM->CHIPCTL & (0x800))>>11u == 1){}

	/*Choose clock sourse for SCG*/
	if (ClockSource == FIRC_CLK)
	{
		SCG->CLKOUTCNFG = (0x03000000); //FIRC_CLK
	}
	else if (ClockSource == SPLL_CLK)
	{
		SCG->CLKOUTCNFG = (0x06000000); //SPLL_CLK
	}
	else if (ClockSource == SOSC_CLK)
	{
		SCG->CLKOUTCNFG = (0x1000000);  //SOSC_CLK
	}

	/*Clear CLKOUTSEL: bit 4-7 = 0000	*/
	SIM->CHIPCTL &= ~(0xF<<4u);

	/*Config CLKOUTSEL bit 4-7 = 
	0010b - SOSC DIV2 CLK 
	0110b - FIRC DIV2 CLK 
	1000b - SPLL DIV2 CLK */
	if (ClockSource == FIRC_CLK)
	{
		SIM->CHIPCTL	|= (6u<<4u);	//FIRCDIV2
	}
	else if (ClockSource == SPLL_CLK)
	{
		SIM->CHIPCTL	|= (8u<<4u);	//SPLDIV2
	}
	else if (ClockSource == SOSC_CLK)
	{
		SIM->CHIPCTL	|= (2u<<4u);	//SOSCDIV2
	}
	
    /*Set CLKOUTDIV - choose divide by 2 - set bit 10-8: 001b*/
	SIM->CHIPCTL |= (0x1U<<8);
    /*CLKOUT enable*/
    SIM->CHIPCTL |= (0x1U<<11);
}
void FIRC_Init(void){
	while(SCG->FIRCCSR & (1u<<23u));
    SCG->FIRCCSR = (0x00000000); //disable
    SCG->FIRCDIV = (0x1u<<8)|(SCG->FIRCDIV); //select DIV2 by 1
    SCG->FIRCCSR = (0x1u<<0)|(SCG->FIRCCSR); //enable
}

