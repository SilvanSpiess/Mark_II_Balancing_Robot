/**
  * @file   button_driver.h
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.1
  * @date 23.03.2021
  * @date 23.04.2018
  * @brief  Driver for a push button.
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "stm32f4xx_hal.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdint.h"

#define INPUT_LOW   ((uint16_t)  0)
#define INPUT_HIGH  ((uint16_t)  65535)


#ifndef EDGE
#define EDGE
typedef enum{myFALLING_EDGE, myNO_EDGE, myRISING_EDGE}edge;
#endif // EDGE

/**
  * Structure to represent a input filter.
  */
typedef struct InputFilter_{
    uint16_t rawInputSet;
    bool inputState;
    edge pendingEdge;
    GPIO_TypeDef * port;
    uint16_t pin;
    void (*sample)(struct InputFilter_ *const);
    edge (*getEdge)(struct InputFilter_ *const);
}InputFilter;

/**
 * @brief Function to initialize a new InputFilter instance.
 * @param _this     Pointer to the instance itself.
 * @param port      Pointer to a GPIO_TypeDef instance.
 * @param pin       Number of a pin.
 * @return          Exit Status Makro from GNU library.
 */
uint8_t InputFilter_init(InputFilter *const _this, GPIO_TypeDef *const port, uint16_t pin);

#endif // BUTTON_DRIVER_H
