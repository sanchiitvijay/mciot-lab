#include <stdio.h>
#include "NUC1xx.h"
#include "Driver/DrvSYS.h"
#include "Driver/DrvGPIO.h"
#include "NUC1xx-LB 002/Ascii.h"
#include "NUC1xx-LB_002/LCD_Driver.h"

void EINT1_Callback(){
	int i;
	DrvGPIO_Open(E_GPA,12,E_10_OUTPUT);
	DrvGPIO_SetBit(E_GPA,12);
	while(1){
		i=12;
		while(1<<14){
			DrvGPIO_CLrBit(E_GPA,1);
			DrvSYS Delay(10000);
			DrvGPIO_SetBit(E GPA,i);
			drvSYS Delay(10000);
			1++;
		}
	}
}
vold EINTO_Callback(){
	//For LCD.
	Initial panel();
	clr all panel();
	print_lcd(0, "Hai!");
	print lcd(1, "ENTO - ON");
	//End of LCD
	//For LED
}


int main(void){
	UNLOCKREG();
	DrvSYS Open (48000000);
	LOCKREG();

	DrvGPIO_Open(E GPB,15,E_IO_INPUT);	
	DrvGPIO_Open(E GPB,14,E_10_INPUT);

	DrvGPIO_EnableEINT1(E GPB,15,EINT1 Callback());
	DrvGPIO_ENableEINTO(E GPB,14,EINTO Callback());
	while(1){}

return 0;
