/**
  * @file   lcd_menu.h
  * @author BFH-TI / Matthias WAELTI <waltm5@bfh.ch>
  * @author BFH-TI / Daniel DEBRUNNER <dnd1@bfh.ch>
  * @version 1.0.0
  * @date 23.04.2018
  * @brief  Simple generic lcd menu.
  * @hardware NucleoF446RE, mbed-016.1-application-shield
  */

#ifndef LCD_MENU_H
#define LCD_MENU_H

#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "lcd_driver.h"

#define MENU_MAX_ENTRIES 16
#define MENU_CHARACTERS_PER_LINE 22
#define MENU_OPTIONS_PER_PAGE 3

/**
  * Enumeration to represent menu navigations.
  */
typedef enum{MENU_NOP, MENU_UP, MENU_DOWN, MENU_BACKWARD, MENU_FORWARD, MENU_SELECT}menu_navigation;

/**
  * Enumeration to represent menu events, free to expand.
  */
typedef enum{MENU_NO_EVENT, MENU_STOP_EVENT, MENU_RLED_EVENT, MENU_GLED_EVENT, MENU_BLED_EVENT,
						 MENU_MANUAL_SUB1_EVENT, MENU_MANUAL_SUB2_EVENT, MENU_POT_EVENT,
             MENU_FUNC_MENU_LN1, MENU_FUNC_MENU_LN2, MENU_FUNC_MENU_LN3, MENU_FUNC_MENU_LN4,
             MENU_FUNC_MENU_LN5, MENU_FUNC_MENU_LN6, MENU_FUNC_MENU_LN7, MENU_FUNC_MENU_LN8,
             MENU_SETTINGS_DC_EVENT, MENU_SETTINGS_PSC_EVENT, 
             MENU_SPEAKER_NOR_EVENT, MENU_SPEAKER_MEL_EVENT, 
             MENU_DC_EVENT}menu_event; 

/**
  * Enumeration to specify the type of a menu entry.
  */
typedef enum{MENU_EVENT, MENU_SUBMENU}menu_entryType;

/**
 * Forward declaration
 */
typedef struct Menu_ Menu;

/**
  * Structure to represent a menu entry.
  */
typedef struct MenuEntry_{
    char const *description;
    menu_entryType type;
    union{
        Menu *submenu;
        menu_event event;
		//$DND
		char const *liveData;
    };
}MenuEntry;

/**
  * Structure to represent a menu.
  */
typedef struct Menu_{
    /* public: */
    char const *description;
    uint8_t numberOfEntries;
    MenuEntry **list;
    /* private: */
    Menu *parentMenu;
    uint8_t cursorPosition;
    uint8_t pageAnchor;
}Menu;

/**
 * @brief Function to set the main menu or super menu
 * @param menu  Pointer to a menu instance.
 */
void menu_setMainMenu(Menu *const menu);

/**
 * @brief Function to write the current menu to the lcd display.
 */
void menu_show(void);

/**
 * @brief Function to feed the menu a new navigation.
 * @param   Enum from type menu_navigation.
 * @return  Enum from type menu_event.
 */
menu_event menu_update(menu_navigation navigation);

typedef void (*menuUserDrawItem)(int);
// a function that passes the menu event id as parameter
typedef void (*menuUserDrawItem2)(int,void*);
void menu_registerDrawMenuItem(menuUserDrawItem func);
void menu_registerDrawMenuItem2(menuUserDrawItem2 func, void* data);

#endif // LCD_MENU_H