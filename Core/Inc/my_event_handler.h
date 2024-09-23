/**
 * @file my_event_handler.h
 * @ref <MechatronicsProjectOne>
 * @author Silvan Spiess <silvan.spiess@bfh-student.ch>
 * @copyright Bern University of Applied Sciences
 *            Silvan Spiess 
 * @version v1.0.0
 * @date 16. March. 2024
 * 
 * @brief This file handles functions process events, such as menu entry, menu exit and menu call back (every 20ms)
 */

#ifndef __MYEVENTHANDLER_H__
#define __MYEVENTHANDLER_H__

#include "main.h"
#include "my_funcs.h"
#include "joyStick.h"
#include "music_player.h"
#include "my_display_handler.h"

/**
 * @brief This function gets periodically called in an menu and covers the structural behaviour of the program inside a menu (event)
 * 
 * @param event Current event, the program is in
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void drawMenuItem_Callback2(int event, void* data);

/**
 * @brief This function is called when entering a menu (event) and mainly sets up LED colors
 * 
 * @param event Current event, the program is in
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void handleMenuEntryEvent(int event, AppData *data);

/**
 * @brief This function is called when exiting a menu (event) and mainly sets up LED colors.
 * It furthermore disables not anymore used PWMs or other pins.
 * 
 * @param event Current event, the program is in
 * @param data Data struct of global variables
 * 
 * @return void function
 */
void handleMenuExitEvent(int event, AppData *data);




#endif /* __MYEVENTHANDLER_H__ */