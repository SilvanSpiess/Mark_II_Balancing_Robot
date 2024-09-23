/**
  * @file   joystick.h
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.0
  * @date 23.04.2018
  * @brief  Driver for the joystick on a mbed-016.1-application-shield.
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "button.h"
#include "main.h"

/**
  * Enumeration to represent the possiple position of a joystick.
  */
typedef enum{JOYSTICK_NEUTRAL, JOYSTICK_UP, JOYSTICK_DOWN, JOYSTICK_LEFT, JOYSTICK_RIGHT, JOYSTICK_CENTER}joystickDirection;

/**
  * Structure to represent a abstract joystick.
  */
typedef struct Joystick_{
    Button *up;
    Button *down;
    Button *left;
    Button *right;
    Button *center;
    void (*sample)(struct Joystick_ *const);
    joystickDirection(*getDirection)(struct Joystick_ *const);
}Joystick;

/**
 * @brief Function to initialize a new InputFilter instance.
 * @param _this     Pointer to the instance itself.
 * @return          Exit Status Makro from GNU library.
 */
uint8_t Joystick_init(Joystick *const _this);

#endif // JOYSTICK_H
