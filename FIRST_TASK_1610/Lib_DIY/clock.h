/*
 * clock.h
 *
 *  Created on: Oct 1, 2023
 *      Author: Admin
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include  "register.h"

#define FIRC_CLK	(1u)
#define SPLL_CLK	(2u)
#define SOSC_CLK    (3u)

void SOSC_Init(void);
void SPLL_Init(void);
void FIRC_Init(void);
void DisplayCLKOUT(unsigned int ClockSource);

#endif /* CLOCK_H_ */
