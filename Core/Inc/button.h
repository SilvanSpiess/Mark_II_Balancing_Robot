/**
  * @file   button.h
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.0
  * @date 23.04.2018
  * @brief  Driver for a push button.
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#ifndef BUTTON_H
#define BUTTON_H

#include "stdint.h"
#include "stdlib.h"
#include "stm32f4xx_hal.h"

#ifdef MAKE_OPAQUE
typedef struct InputFilter_ InputFilter;
#else
#include "button_driver.h"
#endif // MAKE_OPAQUE

#ifndef EDGE
#define EDGE
typedef enum{FALLING_EDGE, NO_EDGE, RISING_EDGE}edge;
#endif // EDGE

/**
  * Structure to represent a abstract button.
  */
typedef struct Button_{
    InputFilter * filter;
    void (*sample)(struct Button_ *const);
    edge (*getEdge)(struct Button_ *const);
}Button;

/**
 * @brief Function to initialize a new Button instance.
 * @param _this     Pointer to the instance itself.
 * @param port      Pointer to a GPIO_TypeDef instance.
 * @param pin       Number of a pin.
 * @return          Exit Status Makro from GNU library.
 */
uint8_t Button_init(Button *const _this, GPIO_TypeDef * const port, uint16_t pin);

#endif // BUTTON_H
