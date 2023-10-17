#include <stdint.h>
#include <register.h>
#include <clock.h>
#include <lpuart.h>
#include <gpio.h>

int main(void){
    char string1[] = "SOSC\n";
	char string2[] = "SPLL\n";
    FIRC_Init();
    SOSC_Init();
    SPLL_Init();
    CLKOUT_Init();
    BUTTON_Init();
    LPUART1_Init();
    while(1)
    {
        if (GPIOC->PDIR & (0x1u<<12)){           //BTN0 = PTC12 -> SOSC
            DisplayCLKOUT(SOSC_CLK);
            LPUART1_transmit_string(string1);
        }
        if (GPIOC->PDIR & (0x1u<<13)){           //BTN1 = PTC13 -> SPLL
            DisplayCLKOUT(SPLL_CLK);
            LPUART1_transmit_string(string2);
        }
    }
    return 0; 
}