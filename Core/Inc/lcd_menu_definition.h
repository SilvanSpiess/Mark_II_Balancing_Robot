/*
 * lcd_menu_definition.h
 *
 *  Created on: 07 Mar, 2023
 *      Author: Yanick
 *       Brief: This file is used to define the menu structure, that the user wants to show on the LCD display.
 *              The integers for the menu evants should be replaced by an enumeration variable, see lcd_menu.h. 
 *              Adapt the enumeration variable name to the application in a meaningful way.
 */

#include "lcd_menu.h"

#ifndef INC_LCD_MENU_DEFINITION_H_
#define INC_LCD_MENU_DEFINITION_H_

/* Submenu LED */
MenuEntry redLed = {.description="Red LED", .type=MENU_EVENT, .event = MENU_RLED_EVENT}; 
MenuEntry greenLed = {.description="Green LED", .type=MENU_EVENT, .event = MENU_GLED_EVENT};
MenuEntry blueLed = {.description = "Blue LED", .type=MENU_EVENT, .event = MENU_BLED_EVENT};
MenuEntry *ledList[] = {&redLed, &greenLed, &blueLed};
Menu ledMenu = {"Led Menu", 3, ledList};

/* Subsubmenu Functionalities (19 chars per title)*/
MenuEntry subsubMenu1 = {.description = "This MCU controls", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN1};
MenuEntry subsubMenu2 = {.description = "a DC-motor. Data", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN2};
MenuEntry subsubMenu3 = {.description = "export with UART.", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN3};
MenuEntry subsubMenu4 = {.description = "Add. FEATURES:", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN4};
MenuEntry subsubMenu5 = {.description = " - POT control", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN5};
MenuEntry subsubMenu6 = {.description = " - Speaker", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN6};
MenuEntry subsubMenu7 = {.description = " - LED visual", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN7};
MenuEntry subsubMenu8 = {.description = " - Jedi mindtrick", .type=MENU_EVENT, .event = MENU_FUNC_MENU_LN8};
MenuEntry *funcList[] = {&subsubMenu1, &subsubMenu2, &subsubMenu3, &subsubMenu4, &subsubMenu5, &subsubMenu6, &subsubMenu7, &subsubMenu8};
Menu funcMenu = {"Func Menu", 8, funcList};

/* Submenu Manual */
MenuEntry subManual1 = {.description = "MANIFEST", .type=MENU_EVENT, .event = MENU_MANUAL_SUB1_EVENT};
MenuEntry subManual2 = {.description = "Functionality", .type=MENU_SUBMENU, .submenu = &funcMenu};
MenuEntry *manList[] = {&subManual1, &subManual2};
Menu manMenu = {"Man Menu", 2, manList};

/* Submenu Settings */
MenuEntry settingsSample = {.description = "DC sample settings", .type=MENU_EVENT, .event = MENU_SETTINGS_DC_EVENT};
MenuEntry settingsPSC = {.description = "DC PSC settings", .type=MENU_EVENT, .event = MENU_SETTINGS_PSC_EVENT};
MenuEntry *settingsList[] = {&settingsSample, &settingsPSC};
Menu settingsMenu = {"Settings Menu", 2, settingsList};

/* Submenu Speaker */
MenuEntry normal_speaker = {.description = "Speaker", .type=MENU_EVENT, .event = MENU_SPEAKER_NOR_EVENT};
MenuEntry melody = {.description = "Imperial March", .type=MENU_EVENT, .event = MENU_SPEAKER_MEL_EVENT};
MenuEntry *speakerList[] = {&normal_speaker, &melody};
Menu speakerMenu = {"Speaker Menu", 2, speakerList};

/* Main Menu */
MenuEntry first = {.description = "Manual", .type = MENU_SUBMENU, .submenu = &manMenu};
MenuEntry second = {.description = "Pot1 | Pot2", .type = MENU_EVENT, .event = MENU_POT_EVENT};
MenuEntry third = {.description = "DC motor", .type = MENU_EVENT, .event = MENU_DC_EVENT};
MenuEntry fourth = {.description = "Speaker", .type =MENU_SUBMENU, .submenu = &speakerMenu};
MenuEntry led = {.description = "Led", .type = MENU_SUBMENU, .submenu = &ledMenu};
MenuEntry settings = {.description = "Settings", .type = MENU_SUBMENU, .submenu = &settingsMenu};
MenuEntry *mainList[] = {&first, &second, &third, &fourth, &led, &settings};
Menu mainMenu = {"Main Menu", 6, mainList};


#endif /* INC_LCD_MENU_DEFINITION_H_ */
