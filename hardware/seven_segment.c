#include <stdio.h>																											 
#include "NUC1xx.h"
#include "Seven_Segment.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"

void seg_display(int16_t val){
	int8_t digit;
	for (int i = 1; i<5; i++){
		digit = val % 10;
		val = val/10;
		close_seven_segment();
		show_seven_segment(4-i,digit);
		DrvSYS_Delay(10000);
	}
}

int32_t main(void){
	int16_t val;
	val = 0000;
	
	UNLOCKREG();
	DrvSYS_Open(180000);
	LOCKREG();
	
	while(1){
		DrvSYS_Delay(1800000);
		val++;
		seg_display(val);
	}
}
