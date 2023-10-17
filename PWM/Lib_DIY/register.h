/*
 * register.h
 *
 *  Created on: Oct 1, 2023
 *      Author: Admin
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <stdint.h>

//************************************PORT_PCR*********************************************************
#define PORT_PCR_COUNT				32u        //32 pin control register
/* PORT module */
typedef struct {
	volatile unsigned int PCR[PORT_PCR_COUNT];
}	PORT_Type;
/* Peripheral PORTA base address */
#define PORTA_base            			(0x40049000)
/* Peripheral PORTA base pointer */
#define PORTA							((PORT_Type*)PORTA_base)

/* Peripheral PORTB base address */
#define PORTB_base            			(0x4004A000)
/* Peripheral PORTB base pointer */
#define PORTB                 			((PORT_Type*)PORTB_base)

/* Peripheral PORTC base address */
#define PORTC_base						(0x4004B000u)
/* Peripheral PORTC base pointer */
#define PORTC							((PORT_Type*)PORTC_base)

/* Peripheral PORTD base address */
#define PORTD_base						(0x4004C000u)
/* Peripheral PORTD base pointer */
#define PORTD							((PORT_Type*)PORTD_base)

/* Peripheral PORTE base address */
#define PORTE_base            			(0x4004D000)
/* Peripheral PORTE base pointer */
#define PORTE                 			((PORT_Type*)PORTE_base)

//************************************PORT_PCR*********************************************************

//************************************GPIO*************************************************************
typedef struct{
	volatile unsigned int PDOR;	/* Port Data Output Register, offset: 0x0 */
	volatile unsigned int PSOR;	/* Port Set Output Register, offset: 0x4 */
	volatile unsigned int PCOR;	/* Port Clear Output Register, offset: 0x8 */
	volatile unsigned int PTOR;	/* Port Toggle Output Register, offset: 0xC */
	volatile unsigned int PDIR;	/* Port Data Input Register, offset: 0x10 */
	volatile unsigned int PDDR;	/* Port Data Direction Register, offset: 0x14 */
	volatile unsigned int PIDR;	/* Port Input Disable Register, offset: 0x18 */
}GPIO_Type;

#define GPIOA_base       (0x400FF000u)
#define GPIOA            ((GPIO_Type*)GPIOA_base)

#define GPIOB_base       (0x400FF040u)
#define GPIOB            ((GPIO_Type*)GPIOB_base)

#define GPIOC_base       (0x400FF080u)
#define GPIOC            ((GPIO_Type*)GPIOC_base)

#define GPIOD_base       (0x400FF0C0u)
#define GPIOD            ((GPIO_Type*)GPIOD_base)

#define GPIOE_base       (0x400FF100u)
#define GPIOE            ((GPIO_Type*)GPIOE_base)
//************************************GPIO*************************************************************


//****************************Peripheral Clock Controller (PCC)****************************************
typedef struct {
  char PCC_dummy0[128];
  volatile unsigned int PCC_FTFC;
  volatile unsigned int PCC_DMAMUX;
  char PCC_dummy1[8];
  volatile unsigned int PCC_FlexCAN0;
  volatile unsigned int PCC_FlexCAN1;
  volatile unsigned int PCC_FTM3;
  volatile unsigned int PCC_ADC1;
  char PCC_dummy2[12];
  volatile unsigned int PCC_FlexCAN2;
  volatile unsigned int PCC_LPSPI0;
  volatile unsigned int PCC_LPSPI1;
  volatile unsigned int PCC_LPSPI2;
  char PCC_dummy3[8];
  volatile unsigned int PCC_PDB1;
  volatile unsigned int PCC_CRC;
  char PCC_dummy4[12];
  volatile unsigned int PCC_PDB0;
  volatile unsigned int PCC_LPIT;
  volatile unsigned int PCC_FTM0;
  volatile unsigned int PCC_FTM1;
  volatile unsigned int PCC_FTM2;
  volatile unsigned int PCC_ADC0;
  char PCC_dummy5[4];
  volatile unsigned int PCC_RTC;
  char PCC_dummy6[8];
  volatile unsigned int PCC_LPTMR0;
  char PCC_dummy7[32];
  volatile unsigned int PCC_PORTA;
  volatile unsigned int PCC_PORTB;
  volatile unsigned int PCC_PORTC;
  volatile unsigned int PCC_PORTD;
  volatile unsigned int PCC_PORTE;
  char PCC_dummy8[24];
  volatile unsigned int PCC_SAI0;
  volatile unsigned int PCC_SAI1;
  char PCC_dummy9[16];
  volatile unsigned int PCC_FlexIO;
  char PCC_dummy10[24];
  volatile unsigned int PCC_EWM;
  char PCC_dummy11[16];
  volatile unsigned int PCC_LPI2C0;
  volatile unsigned int PCC_LPI2C1;
  char PCC_dummy12[8];
  volatile unsigned int PCC_LPUART0;
  volatile unsigned int PCC_LPUART1;
  volatile unsigned int PCC_LPUART2;
  char PCC_dummy13[4];
  volatile unsigned int PCC_FTM4;
  volatile unsigned int PCC_FTM5;
  volatile unsigned int PCC_FTM6;
  volatile unsigned int PCC_FTM7;
  char PCC_dummy14[4];
  volatile unsigned int PCC_CMP0;
  char PCC_dummy15[8];
  volatile unsigned int PCC_QSPI;
  char PCC_dummy16[8];
  volatile unsigned int PCC_ENET;
} PCC_Type;

#define PCC_base			(0x40065000u)
#define PCC 				((PCC_Type*)PCC_base)

//****************************Peripheral Clock Controller (PCC)****************************************


//***********************Nested Vectored Interrupt Controller (NVIC)***********************************
/***	4. S32_NVIC - Size of Registers Arrays */
#define S32_NVIC_ISER_COUNT                      8u
#define S32_NVIC_ICER_COUNT                      8u
#define S32_NVIC_ISPR_COUNT                      8u
#define S32_NVIC_ICPR_COUNT                      8u
#define S32_NVIC_IABR_COUNT                      8u
#define S32_NVIC_IP_COUNT                        240u

/** S32_NVIC - Register Layout Typedef */
typedef struct {
  volatile unsigned int ISER[S32_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
	unsigned int RESERVED_0[24];
  volatile unsigned int ICER[S32_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
     unsigned int RESERVED_1[24];
  volatile unsigned int ISPR[S32_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
     unsigned int RESERVED_2[24];
  volatile unsigned int ICPR[S32_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
     unsigned int RESERVED_3[24];
  volatile unsigned int IABR[S32_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
     unsigned char RESERVED_4[224];
  volatile unsigned char IP[S32_NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
     unsigned char RESERVED_5[2576];
  volatile  unsigned int STIR;                              /**< Software Trigger Interrupt Register, offset: 0xE00 */
} NVIC_Type;

/* S32_NVIC - Peripheral instance base addresses */
/** Peripheral S32_NVIC base address */
#define NVIC_BASE                            (0xE000E100u)
/** Peripheral S32_NVIC base pointer */
#define NVIC                                 ((NVIC_Type *)NVIC_BASE)
//***********************Nested Vectored Interrupt Controller (NVIC)***********************************


/** 5.  SOFTTIMER - Define Register System stick timer	*/

typedef struct {
	volatile unsigned int CSR;				/*	Systick Control and Status Register	*/
	volatile unsigned int RVR;				/*	Systick Reload Value Register	*/
	volatile unsigned int CVR;				/*	Systick Current Value Register	*/
	volatile unsigned int CALIB;			/*	Systick Calibration Value register	*/
}SysTick_Type;
#define SYSTICK_BASE		(0xE000E010)
#define	SYSTICK				((SysTick_Type*) SYSTICK_BASE)


//****************************Low Power Interrupt Timer (LPIT)*****************************************************
typedef struct LPIT
{
volatile unsigned int LPIT_VERID;
volatile unsigned int LPIT_PARAM;
volatile unsigned int LPIT_MCR;
volatile unsigned int LPIT_MSR;
volatile unsigned int LPIT_MIER;
volatile unsigned int LPIT_SETTEN;
volatile unsigned int LPIT_CLRTEN;
volatile unsigned int LPIT_dummy0;
volatile unsigned int LPIT_TVAL0;
volatile unsigned int LPIT_CVAL0;
volatile unsigned int LPIT_TCTRL0;
volatile unsigned int LPIT_dummy1;
volatile unsigned int LPIT_TVAL1;
volatile unsigned int LPIT_CVAL1;
volatile unsigned int LPIT_TCTRL1;
volatile unsigned int LPIT_dummy2;
volatile unsigned int LPIT_TVAL2;
volatile unsigned int LPIT_CVAL2;
volatile unsigned int LPIT_TCTRL2;
volatile unsigned int LPIT_dummy3;
volatile unsigned int LPIT_TVAL3;
volatile unsigned int LPIT_CVAL3;
volatile unsigned int LPIT_TCTRL3;
}LPIT_type;

#define BASE_ADDRESS_TIMER    (0x40037000)
#define LPIT                  ((LPIT_type*)BASE_ADDRESS_TIMER)

//****************************Low Power Interrupt Timer (LPIT)*****************************************************


//*******************Low Power Universal Asynchronous Receiver/Transmitter (LPUART)********************************
typedef struct LPUART
{
volatile unsigned int const VERID;
volatile unsigned int const PARAM;
volatile unsigned int GLOBAL;
volatile unsigned int PINCFG;
volatile unsigned int BAUD;
volatile unsigned int STAT;
volatile unsigned int CTRL;
volatile unsigned int DATA;
volatile unsigned int MATCH;
volatile unsigned int MODIR;
volatile unsigned int FIFO;
volatile unsigned int WATER;
}LPUART_type;

#define LPUART0_base    (0x4006A000)
#define LPUART1_base    (0x4006B000)
#define LPUART2_base    (0x4006C000)

#define LPUART0         ((LPUART_type*) LPUART0_base)
#define LPUART1         ((LPUART_type*) LPUART1_base)
#define LPUART2         ((LPUART_type*) LPUART2_base)

//*******************Low Power Universal Asynchronous Receiver/Transmitter (LPUART)********************************


//***********************************System Clock Generator (SCG)**************************************************
typedef struct {
  volatile const unsigned int VERID;                        /**< Version ID Register, offset: 0x0 */
  volatile const unsigned int PARAM;                        /**< Parameter Register, offset: 0x4 */
  unsigned int RESERVED_0[2];
  volatile const unsigned int CSR;                          /**< Clock Status Register, offset: 0x10 */
  volatile unsigned int RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  volatile unsigned int VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  volatile unsigned int HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  volatile unsigned int CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
  unsigned int RESERVED_1[55];
  volatile unsigned int SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  volatile unsigned int SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  volatile unsigned int SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
  unsigned int RESERVED_2[61];
  volatile unsigned int SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  volatile unsigned int SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  volatile unsigned int SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
  unsigned int RESERVED_3[61];
  volatile unsigned int FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  volatile unsigned int FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  volatile unsigned int FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  unsigned int RESERVED_4[189];
  volatile unsigned int SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  volatile unsigned int SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  volatile unsigned int SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type;

  /** Peripheral SCG base address */
#define SCG_BASE                                 (0x40064000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)

//***********************************System Clock Generator (SCG)**************************************************


/** 9.  LPSPI - Register Layout Typedef */
typedef struct {
  volatile const  unsigned int VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile const  unsigned int PARAM;                             /**< Parameter Register, offset: 0x4 */
       unsigned char RESERVED_0[8];
  volatile unsigned int CR;                                /**< Control Register, offset: 0x10 */
  volatile unsigned int SR;                                /**< Status Register, offset: 0x14 */
  volatile unsigned int IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  volatile unsigned int DER;                               /**< DMA Enable Register, offset: 0x1C */
  volatile unsigned int CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  volatile unsigned int CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       unsigned char RESERVED_1[8];
  volatile unsigned int DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  volatile unsigned int DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       unsigned char RESERVED_2[8];
  volatile unsigned int CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       unsigned char RESERVED_3[20];
  volatile unsigned int FCR;                               /**< FIFO Control Register, offset: 0x58 */
  volatile const  unsigned int FSR;                               /**< FIFO Status Register, offset: 0x5C */
  volatile unsigned int TCR;                               /**< Transmit Command Register, offset: 0x60 */
  volatile  unsigned int TDR;                               /**< Transmit Data Register, offset: 0x64 */
       unsigned char RESERVED_4[8];
  volatile const  unsigned int RSR;                               /**< Receive Status Register, offset: 0x70 */
  volatile const  unsigned int RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type;
/** Peripheral LPSPI base address */
#define LPSPI0_base           (0x4002C000u)
#define LPSPI1_base           (0x4002D000u)
#define LPSPI2_base           (0x4002E000u)

#define LPSPI0                ((LPSPI_Type *)LPSPI0_base)
#define LPSPI1                ((LPSPI_Type *)LPSPI1_base)
#define LPSPI2                ((LPSPI_Type *)LPSPI2_base)



//***********************************System Integration Module (SIM)************************************************
typedef struct {
  char SIM_dummy1[4];
  volatile unsigned int CHIPCTL;
  char SIM_dummy2[4];
  volatile unsigned int FTMOPT0;
  volatile unsigned int LPOCLKS;
  char SIM_dummy3[4];
  volatile unsigned int ADCOPT;
  volatile unsigned int FTMOPT1;
  volatile unsigned int MISCTRL0;
  volatile const unsigned int SDID;
  char SIM_dummy4[24];
  volatile unsigned int PLATCGC;
  char SIM_dummy5[8];
  volatile unsigned int FCFG1;
  char SIM_dummy6[4];
  volatile const unsigned int UIDH;
  volatile const unsigned int UIDMH;
  volatile const unsigned int UIDML;
  volatile const unsigned int UIDL;
  char SIM_dummy7[4];
  volatile unsigned int CLKDIV4;
  volatile unsigned int MISCTRL1;
} SIM_Type;

#define SIM_base              (0x40048000)
#define SIM                   ((SIM_Type*)SIM_base)

//***********************************System Integration Module (SIM)************************************************

//****************************************FlexTimer Module (FTM)****************************************************
typedef struct FTM
{
  volatile unsigned int SC;
volatile unsigned int CNT;
volatile unsigned int MOD;
volatile unsigned int C0SC;
volatile unsigned int C0V;
volatile unsigned int C1SC;
volatile unsigned int C1V;
volatile unsigned int C2SC;
volatile unsigned int C2V;
volatile unsigned int C3SC;
volatile unsigned int C3V;
volatile unsigned int C4SC;
volatile unsigned int C4V;
volatile unsigned int C5SC;
volatile unsigned int C5V;
volatile unsigned int C6SC;
volatile unsigned int C6V;
volatile unsigned int C7SC;
volatile unsigned int C7V;
volatile unsigned int CNTIN;
volatile unsigned int STATUS;
volatile unsigned int MODE;
volatile unsigned int SYNC;
volatile unsigned int OUTINIT;
volatile unsigned int OUTMASK;
volatile unsigned int COMBINE;
volatile unsigned int DEADTIME;
volatile unsigned int EXTTRIG;
volatile unsigned int POL;
volatile unsigned int FMS;
volatile unsigned int FILTER;
volatile unsigned int FLTCTRL;
volatile unsigned int QDCTRL;
volatile unsigned int CONF;
volatile unsigned int FLTPOL;
volatile unsigned int SYNCONF;
volatile unsigned int INVCTRL;
volatile unsigned int SWOCTRL;
volatile unsigned int PWMLOAD;
volatile unsigned int HCR;
volatile unsigned int PAIR0DEADTIME;
volatile unsigned int PAIR1DEADTIME;
char FTM_dummy1[8];
volatile unsigned int PAIR2DEADTIME;
char FTM_dummy2[4];
volatile unsigned int PAIR3DEADTIME;
//Mirror of Modulo Value (MOD_MIRROR) & Mirror of Channel (n) Match Value (C0V_MIRROR - C7V_MIRROR) aren't listed in this struct
} FTM_type;

#define FTM0_base     (0x40038000)
#define FTM1_base     (0x40039000)
#define FTM2_base     (0x4003A000)
#define FTM3_base     (0x40026000)
#define FTM4_base     (0x4006E000)
#define FTM5_base     (0x4006F000)
#define FTM6_base     (0x40070000)
#define FTM7_base     (0x40071000)

#define FTM0          ((FTM_type*)FTM0_base)
#define FTM1          ((FTM_type*)FTM1_base)
#define FTM2          ((FTM_type*)FTM2_base)
#define FTM3          ((FTM_type*)FTM3_base)
#define FTM4          ((FTM_type*)FTM4_base)
#define FTM5          ((FTM_type*)FTM5_base)
#define FTM6          ((FTM_type*)FTM6_base)
#define FTM7          ((FTM_type*)FTM7_base)

//****************************************FlexTimer Module (FTM)****************************************************

#endif /* REGISTER_H_ */
