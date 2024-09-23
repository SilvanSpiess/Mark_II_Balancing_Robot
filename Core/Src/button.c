/**
  * @file   button.c
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.0
  * @date 23.04.2018
  * @brief  Driver for a push button.
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#include "button.h"
#include "button_driver.h"

#define MAX_NUMBER_OF_FILTERS 10

static InputFilter filterSet[MAX_NUMBER_OF_FILTERS] = {};
static uint8_t initializedFilters = 0;

static void Button_sample(Button *const _this)
{
    _this->filter->sample(_this->filter);
}

static edge Button_getEdge(Button *const _this)
{
    return _this->filter->getEdge(_this->filter);
}

uint8_t Button_init(Button *const _this, GPIO_TypeDef *const port, uint16_t pin)
{
    if (initializedFilters == MAX_NUMBER_OF_FILTERS)
        return EXIT_FAILURE;

    _this->filter =  &filterSet[initializedFilters++];
    InputFilter_init(_this->filter, port, pin);

    _this->sample = Button_sample;
    _this->getEdge = Button_getEdge;
    return EXIT_SUCCESS;
}

