/**
 * @file my_funcs.h
 * @ref <MechatronicsProjectOne>
 * @author Silvan Spiess <silvan.spiess@bfh-student.ch>
 * @copyright Bern University of Applied Sciences
 *            Silvan Spiess 
 * @version v1.0.0
 * @date 16. March. 2024
 * 
 * @brief This file handles functions which handles processes such as motor usage and and joystick inputs. 
 * General functions can be found in this file.
 */

#ifndef __MYFUNCS_H__
#define __MYFUNCS_H__

#include "main.h"
#include "lcd_menu.h"
#include "tim.h"
#include "usart.h"

/**
 * @brief This function prints a welcome screen on the lcd display. The use of HAL_delay() is rectified, 
 * as the function is called before any crucial code.
 * 
 * @param None
 * 
 * @return void function
 */
void screen_setup();

/**
 * @brief This function is called when the joystick has been triggered in certain menus.
 * Based on the menu and the direction, it performs operations on peripherals.
 * 
 * @param direction Current direction the joystick is pointing
 * @param current_event Current event, the program is in
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void check_joystick(menu_navigation direction, menu_event current_event, void *data);

/**
 * @brief This function controls the DC-motor and handles rotor speed and start / stop behaviour.
 * 
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void motor_menu(void *data);

/**
 * @brief This function controls the LED and based in its inputs, sets the state of the LED
 * 
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void buzz_regulator(void *data);

/**
 * @brief This function sends data to an external application using UART
 * 
 * @param curr_rot_speed Current rotation speed of the motor
 * 
 * @return void function
 */
void sendToUart(uint16_t curr_rot_speed);

#endif /* __DMA_H__ */