#include "msp.h"
#include "SevSeg.h"
#include "stdint.h"
void setup(void);
void TA1_N_IRQHandler(void);

int main(void)
{
	setup();
	
	while(1){
		__ASM("WFI");
	}
	
	return 0;
}


void setup(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; //disable watchdog timer
	
	//SET UP THE DISPLAY
	//set GPIO
	P4SEL0 &= (uint8_t)(0x00);
	P4SEL1 &= (uint8_t)(0x00);
	//set outputs
	P4DIR |= (uint8_t)(0xFF);
	clear(&(P4->OUT));
	
	//SET UP THE TIMER
	TA1CTL&=(uint16_t)~((1<<9)|(1<<8));//clear tassel
	TA1CTL|=(uint16_t)(1<<8);//set to 32.768 kHz
	TA1CTL&=(uint16_t)~((1<<5)|(1<<4));//set MC to stop
	TA1CTL|=(uint16_t)((1<<1));//enables interrupt
	TA1CCR0=0x2222;//set to 1 second delay
	TA1CTL|=(uint16_t)((1<<4));//sets to up mode
	
	//set NVIC interrupt
	NVIC_EnableIRQ(TA1_N_IRQn);
	
	//Set priority
	NVIC_SetPriority(TA1_N_IRQn,2);
	
	//set global interrupt
	__ASM("CPSIE I");
}

//when timer =0;
void TA1_N_IRQHandler(void){
	static const char message[]="David Haighton";
	static int index=0;
	setVal(&(P4->OUT),message[index]);
	
	index+=1;
	if((sizeof(message)/sizeof(message[0]))==index){
		index=0;
	}
	TA1CTL&=(uint16_t)~((1<<0));//clears flag
}
