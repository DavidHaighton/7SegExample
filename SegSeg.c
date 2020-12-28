#include "SevSeg.h"
//does not work with k,
	uint8_t char2pin[]={
	0x3F,//A
	0x7A,//B 
	0x53,//C
	0x7C,//D
	0x5B,//E
	0x1B,//F
	0x6F,//G
	0x3E,//H
	0x20,//i
	0x74,//J
	0x00,//k IMPOSSIBLE
	0x52,//L
	0x00,//M IMPOSSIBLE
	0x38,//n
	0x78,//o
	0x1F,//P
	0x2F,//q
	0x18,//r
	0x6B,//S
	0x5A,//t
	0x70,//u
	0x70,//v
	0x00,//w IMPOSSIBLE
	0x00,//x
	0x6E,//y
	0x5D//z
	};
	uint8_t num2pin[]={0x77 ,0x24,0x5D,0x6D,0x2E,0x6B,0x7B,0x25,0x7F,0x6F};                                                                                                                                            
	
	void setVal(volatile uint8_t *segment,char c){
		(*segment)&=(uint8_t)(1<<7);//clear all but decimal
		if(c>='0'&&c<'9'){
			(*segment)=num2pin[c-'0'];
		}
		else if((c>='A' && c<='Z')){
			(*segment)=char2pin[c-'A'];
		}
		else if(c>='a'&&c<='z'){
			(*segment)=char2pin[c-'a'];
		}
		else{
			clear(segment);
		}
	
	}
	uint8_t hasDecimal(volatile uint8_t *segment){
		return (*segment)|(uint8_t)(1<<7);
	}
	void setDecimal(volatile uint8_t *segment,uint8_t on){
		if(on){
			(*segment) |= (uint8_t)(1<<7);
		}
		else{
			(*segment) &=~(uint8_t)(1<<7);
		}
	}
	void clear(volatile uint8_t *segment){
		(*segment)=(uint8_t)0x00;
	}