/**
 * @file my_display_handler.h
 * @ref <MechatronicsProjectOne>
 * @author Silvan Spiess <silvan.spiess@bfh-student.ch>
 * @copyright Bern University of Applied Sciences
 *            Silvan Spiess 
 * @version v1.0.0
 * @date 16. March. 2024
 * 
 * @brief This file handles the displays for each menu.
 */

#ifndef __MYDISPLAYHANDLER_H__
#define __MYDISPLAYHANDLER_H__

#include "lcd_menu.h"
#include "main.h"
#include "my_funcs.h"

/**
 * @brief This function is called when the lcd-display needs updating and prints the new font of the display.
 * 
 * @param event Current event, the program is in
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void print_display(menu_event currentEvent, void *data);

#endif