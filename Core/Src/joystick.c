/**
  * @file   joystick.c
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
	* @version 1.0.0
	* @date 09.12.2018
  * @date 23.04.2018
  * @brief  Driver for the joystick on a mbed-016.1-application-shield.
  * @hardware NucleoF446RE (RISING_EDGE), mbed-016.1-application-shield, STM32F407 printer FALLING EDGE in joystick.c
  */

#include "joystick.h"

static Button up, down, left, right, center;

static void Joystick_sample(Joystick *const _this){
        _this->up->sample(_this->up);
        _this->down->sample(_this->down);
        _this->left->sample(_this->left);
        _this->right->sample(_this->right);
#ifdef SWITCH_CENTER_Pin
        _this->center->sample(_this->center);
#endif
}


joystickDirection Joystick_getDirection(Joystick *const  _this)
{

// STM32F407 Polar Plotter
//    if (_this->up->getEdge(_this->up) == FALLING_EDGE)           return JOYSTICK_UP;
//    if (_this->down->getEdge(_this->down) == FALLING_EDGE)       return JOYSTICK_DOWN;
//    if (_this->left->getEdge(_this->left) == FALLING_EDGE)       return JOYSTICK_LEFT;
//    if (_this->right->getEdge(_this->right) == FALLING_EDGE)     return JOYSTICK_RIGHT;
//#ifdef SWITCH_CENTER_Pin
//	//$DND Bypass solution with User Button PC13. Use FALLING_EDGE
//    if (_this->center->getEdge(_this->center) == FALLING_EDGE)   return JOYSTICK_CENTER;
	

// STM32F446 rising edge on MBED016!	
  	if (_this->up->getEdge(_this->up) == myRISING_EDGE)           return JOYSTICK_UP;
    if (_this->down->getEdge(_this->down) == myRISING_EDGE)       return JOYSTICK_DOWN;
    if (_this->left->getEdge(_this->left) == myRISING_EDGE)       return JOYSTICK_LEFT;
    if (_this->right->getEdge(_this->right) == myRISING_EDGE)     return JOYSTICK_RIGHT;
#ifdef SWITCH_CENTER_Pin
	//$DND Bypass solution with User Button PC13. Use FALLING_EDGE
    if (_this->center->getEdge(_this->center) == myRISING_EDGE)   return JOYSTICK_CENTER;
#endif
    else                                                        return JOYSTICK_NEUTRAL;
}

uint8_t Joystick_init(Joystick *const _this){
    Button_init(&up, SWITCH_UP_GPIO_Port, SWITCH_UP_Pin);
    _this->up = &up;
    Button_init(&down, SWITCH_DOWN_GPIO_Port, SWITCH_DOWN_Pin);
    _this->down = &down;
    Button_init(&left, SWITCH_LEFT_GPIO_Port, SWITCH_LEFT_Pin);
    _this->left = &left;
    Button_init(&right, SWITCH_RIGHT_GPIO_Port, SWITCH_RIGHT_Pin);
    _this->right = &right;
#ifdef SWITCH_CENTER_Pin
  	Button_init(&center, SWITCH_CENTER_GPIO_Port, SWITCH_CENTER_Pin);
    _this->center = &center;
#endif
    _this->getDirection = Joystick_getDirection;
    _this->sample = Joystick_sample;
    return EXIT_SUCCESS;
}
