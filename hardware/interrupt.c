#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "NUC1xx-LB_002/Ascii.h"
#include "NUC1xx-LB_002/LCD_Driver.h"

void EINT1_Callback(void) {
    int i;
    DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPA, 12);
    while(1) {
        i = 12;
        while(i < 14) {
            DrvGPIO_ClrBit(E_GPA, 12);
            DrvSYS_Delay(10000);
            DrvGPIO_SetBit(E_GPA, 12);
            DrvSYS_Delay(10000);
            i++;
        }
    }
}

void EINT0_Callback(void) {
    Initial_panel();
    clr_all_panel();
    print_lcd(0, "Hai!");
    print_lcd(1, "EINT0 - ON");
}

int main(void) {
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);

    DrvGPIO_EnableEINT1(E_GPB, 15, EINT1_Callback);
    DrvGPIO_EnableEINT0(E_GPB, 14, EINT0_Callback);

    while(1) {}

    return 0;
}
