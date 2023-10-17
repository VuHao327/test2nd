#include <stdint.h>
#include "gpio.h"
#include "register.h"
#include "clock.h"
#include "lpit.h"
#include "lpuart.h"
#include "ftm.h"

int main(void){
    FIRC_Init();
    LPIT0_Init();
    LPUART1_Init();
    //LPIT1_Init();    //send uart
    LED_Init();
    BUTTON_Init();
    Gpio_ClearAllLed();
    FTM0_CH1_PWM_init();
    while (1)
    {
        Send_DutyValue ();
        Limit_Duty();
        Switch_FrePWM();
    }
    
}
