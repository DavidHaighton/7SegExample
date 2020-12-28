#ifndef SEVSEG_H
#define SEVSEG_H
#include "stdint.h"
// 
//       - 0
//      | | 1 2
//       _ 3
//      | | 4 5
//       _ . 6 7
//
// https://components101.com/sites/default/files/component_pin/7-segment-display-pin-diagr_0.png

  //sets the lights of the seven seg given the pins and what to set them to
	void setVal(volatile uint8_t *segment,char c);
	////returns if the seven segment has its decimal lit up (1 for yes and 0 for no)
	uint8_t hasDecimal(volatile uint8_t *segment);
	//sets the decimal to be on or off
	void setDecimal(volatile uint8_t *segment,uint8_t);
	//clears the seven segment display
	void clear(volatile uint8_t *segment);



#endif
