/**
  * @file   button_driver.c
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.1
  * @date 23.03.2021
  * @date 23.04.2018
  * @brief  Driver for a push button. IDE 1.6.0 hal_gpio changes on EDGE
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#include "button_driver.h"

static void InputFilter_sample(InputFilter *const _this)
{
    GPIO_PinState currentInputState = GPIO_PIN_RESET;
    currentInputState = HAL_GPIO_ReadPin(_this->port, _this->pin);

    _this->rawInputSet = _this->rawInputSet << 1;
    _this->rawInputSet |= currentInputState;

    if (_this->inputState == true) {
        if (_this->rawInputSet == INPUT_LOW) {
            _this->pendingEdge = myFALLING_EDGE;
            _this->inputState = false;
        }
    }
    else {
        if (_this->rawInputSet == INPUT_HIGH) {
            _this->pendingEdge = myRISING_EDGE;
            _this->inputState = true;
        }
    }
}

static edge InputFilter_getEdge(InputFilter *const _this)
{
    edge pendingEdge = _this->pendingEdge;
    _this->pendingEdge = myNO_EDGE;
    return pendingEdge;
}

uint8_t InputFilter_init(InputFilter *const _this, GPIO_TypeDef *const port, uint16_t pin)
{
    _this->rawInputSet = 0;
    _this->inputState = false;
    _this->pendingEdge = myNO_EDGE;
    _this->port = port;
    _this->pin = pin;
    _this->sample = InputFilter_sample;
    _this->getEdge = InputFilter_getEdge;
    return EXIT_SUCCESS;
}
