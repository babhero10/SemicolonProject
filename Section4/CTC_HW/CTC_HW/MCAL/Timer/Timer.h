/*
 * Timer.h
 *
 * Created: 8/1/2022 4:15:43 PM
 *  Author: CARNIVAL
 */ 

#include <stdint.h>

#ifndef TIMER_H_
#define TIMER_H_

void init_CTC_timer();
void set_CTC(uint8_t OC);
void CTC_end();

#endif /* TIMER_H_ */