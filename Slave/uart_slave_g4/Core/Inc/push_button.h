/*
 * push_button.h
 *
 *  Created on: Jun 29, 2024
 *      Author: USER
 */

#ifndef INC_PUSH_BUTTON_H_
#define INC_PUSH_BUTTON_H_

#include "main.h"


// Button debounce state
typedef enum {
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_DEBOUNCE
} ButtonState;


extern uint32_t pushButtocounter;
extern uint32_t rcvDatacounter;


// Variables for debouncing
extern ButtonState pushButtonstate;
extern uint32_t lastDebounceTime;



void buttonScan(void);

#endif /* INC_PUSH_BUTTON_H_ */
