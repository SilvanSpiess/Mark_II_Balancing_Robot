/**
 * @file my_display_handler.c
 * @ref <MechatronicsProjectOne>
 * @author Silvan Spiess <silvan.spiess@bfh-student.ch>
 * @copyright Bern University of Applied Sciences
 *            Silvan Spiess 
 * @version v1.0.0
 * @date 16. March. 2024
 * 
 * @brief This file handles the displays for each menu.
 */
#include "my_display_handler.h"

void print_display(menu_event current_event, void *data) {
  
  char str1 [30];
  char str2 [30];
  char str_mode [10];
  AppData* display_data = data;

  switch (current_event) {
  case MENU_RLED_EVENT:
    sprintf(&str1[0]," %s","color n/a ");
		lcd_setString(20,10, (const char*) &str1, LCD_FONT_8, false);
		break;
  case MENU_MANUAL_SUB1_EVENT:
    sprintf(&str1[0]," %s", "Star Wars Episode 3");
    sprintf(&str2[0]," %s", "Revenge of the Sith");
		lcd_setString(2,10, (const char*) &str1, LCD_FONT_8, false);
		lcd_setString(2,20, (const char*) &str2 , LCD_FONT_8, false);
    break;
  case MENU_SPEAKER_NOR_EVENT:
    display_data->current.pot_power1 = (int)((double)display_data->current.pot1/maxPOTSpeed*100);
    sprintf(&str1[0],"%s"," Sound   Pitch");
	  lcd_setString(10,10, (const char*) &str1, LCD_FONT_8, false);
    if(display_data->current.pot2 < 1300)
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<H>>");
    else if(display_data->current.pot2 > 2800)
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<L>>");
    else
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<M>>");
    lcd_setString(10,20, (const char*) &str2, LCD_FONT_8, false);
    break;
  case MENU_SPEAKER_MEL_EVENT:
    display_data->current.pot_power1 = (int)((double)display_data->current.pot1/maxPOTSpeed*100);
    sprintf(&str1[0],"%s","John Williams 1980");
    if(display_data->current.pot1 < maxPOTSpeed/3)
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<H>>");
    else if(display_data->current.pot1 > 2*maxPOTSpeed/3)
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<L>>");
    else
      sprintf(&str2[0]," %3d %s",display_data->current.pot_power1, "%    <<M>>");    
    lcd_setString(10,10, (const char*) &str1, LCD_FONT_8, false);
    lcd_setString(10,20, (const char*) &str2, LCD_FONT_8, false);
    break;
  case MENU_POT_EVENT:
		sprintf(&str1[0]," %5d %5d",display_data->current. pot1, display_data->current.pot2);
		lcd_setString(10,10, (const char*) &str1, LCD_FONT_8, false);
		break;
  case MENU_DC_EVENT:   
    display_data->current.pot_power2 = (int)((double)display_data->current.pot2/maxPOTSpeed*100);
    if(display_data->current.PSC_on) {
      sprintf(&str1[0],"%5s %3d %s %4d","PSC:",display_data->averaged_over_5.pot1, "ROT:", display_data->current.rotation_speed);
      lcd_setString(1,10, (const char*) &str1, LCD_FONT_8, false);
    }
    else {
      sprintf(&str1[0]," %s %4d","rot speed", display_data->current.rotation_speed);
      lcd_setString(10,10, (const char*) &str1, LCD_FONT_8, false);
    }
    switch (display_data->current.mode) {
    case CLOCK_WISE:
      sprintf(&str_mode[0]," %5s","[CW]");
      break;
    case COUNTER_CLOCK_WISE:
      sprintf(&str_mode[0]," %5s","[CCW]");
      break;
    case FAST_STOP:
      sprintf(&str_mode[0]," %5s","[FS]");
      break;
    case SOFT_STOP:
      sprintf(&str_mode[0]," %5s","[SS]");
      break;    
    default:
      break;
    }
    if(display_data->current.pot_power2 < 30)
      sprintf(&str2[0],"%5s %3s %3d %s", str_mode, "<", display_data->current.pot_power2, "%>");
    else if(display_data->current.pot_power2 > 70)
      sprintf(&str2[0],"%5s %3s %3d %s", str_mode, "<<<", display_data->current.pot_power2, "%>>>");
    else
      sprintf(&str2[0],"%5s %3s %3d %s", str_mode, "<<", display_data->current.pot_power2, "%>>");
    lcd_setString(5,20, (const char*) &str2, LCD_FONT_8, false);  
    sendToUart(display_data->current.rotation_speed);  
		break;
  case MENU_SETTINGS_DC_EVENT:
 		sprintf(&str1[0],"%s %2d %s","Smooth value <", display_data->current.number_of_samples, ">");
    sprintf(&str2[0],"%s","To reset:         v");
		lcd_setString(1,10, (const char*) &str1, LCD_FONT_8, false);
		lcd_setString(1,20, (const char*) &str2, LCD_FONT_8, false);
    break;
  case MENU_SETTINGS_PSC_EVENT:
 		sprintf(&str1[0],"%s","Turn PSC on for motor");
		lcd_setString(1,10, (const char*) &str1, LCD_FONT_8, false);
    if(display_data->current.PSC_on)
      lcd_setString(56,20, (const char*) "< ON", LCD_FONT_8, false);
    else if(!display_data->current.PSC_on)
      lcd_setString(34,20, (const char*) "OFF >", LCD_FONT_8, false);
		break;
  default:
    break;
  }
}