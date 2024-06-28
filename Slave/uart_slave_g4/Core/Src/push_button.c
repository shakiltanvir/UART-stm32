/*
 * push_button.c
 *
 *  Created on: Jun 29, 2024
 *      Author: USER
 */

#include "push_button.h"


uint32_t pushButtocounter;
uint32_t rcvDatacounter;


// Variables for debouncing
ButtonState pushButtonstate = BUTTON_RELEASED;
uint32_t lastDebounceTime = 0;
const uint32_t debounceDelay = 50; // 50 ms debounce delay



void buttonScan(void){
    // Read the state of the GPIO pin
    GPIO_PinState pinState = HAL_GPIO_ReadPin(PUSH_BUTTON_1_GPIO_Port, PUSH_BUTTON_1_Pin);

    switch (pushButtonstate)
    {
      case BUTTON_RELEASED:
        if (pinState == GPIO_PIN_RESET)
        {
          // Start debounce timer
          lastDebounceTime = HAL_GetTick();
          pushButtonstate = BUTTON_DEBOUNCE;
        }
        break;

      case BUTTON_DEBOUNCE:
        if ((HAL_GetTick() - lastDebounceTime) >= debounceDelay)
        {
          if (pinState == GPIO_PIN_RESET)
          {
            // Confirm the button press
            pushButtocounter++;
            pushButtonstate = BUTTON_PRESSED;
          }
          else
          {
            // False positive, go back to released state
        	  pushButtonstate = BUTTON_RELEASED;
          }
        }
        break;

      case BUTTON_PRESSED:
        if (pinState == GPIO_PIN_RESET)
        {
          // Button released, go back to released state
        	pushButtonstate = BUTTON_RELEASED;
        }
        break;
    }
}
