/*
 * ftm.h
 *
 *  Created on: Oct 8, 2023
 *      Author: Admin
 */

#ifndef LIB_DIY_FTM_H_
#define LIB_DIY_FTM_H_
#include  "register.h"
#include  "gpio.h"
// void FTM0_Init(void);
void FTM0_CH1_PWM_init(void);
void PWM_2k(void);
void PWM_4k(void);

#endif /* LIB_DIY_FTM_H_ */
