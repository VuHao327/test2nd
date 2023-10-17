#include <stdint.h>
#include "gpio.h"
#include "register.h"
#include "clock.h"
#include "lpit.h"
#include "lpuart.h"

int main(void){
    FIRC_Init();
    LPIT0_Init();
    LPUART1_Init();
    //LPIT1_Init();
    LED_Init();
    BUTTON_Init();
    Gpio_ClearAllLed();
    while(1)
	{
        Send_CounterVariable();
        Check_Duration_LED();
		Cycle_LED_RGB();
    }
}
