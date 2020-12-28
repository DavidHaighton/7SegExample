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

	void setVal(volatile uint8_t *segment,char c);
	uint8_t hasDecimal(volatile uint8_t *segment);
	void setDecimal(volatile uint8_t *segment,uint8_t);
	void clear(volatile uint8_t *segment);



#endif
