/**
 * @file my_funcs.c
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
#include "my_funcs.h"

volatile int32_t message_counter = 0;

void screen_setup() {
  lcd_setFrame(0, 0, 127, 31);
  lcd_setString(43, 5, "WELCOME!", LCD_FONT_8, 0);
  lcd_setString(38, 20, "loading.", LCD_FONT_8, 0);
  lcd_show();
  HAL_Delay(700);
  lcd_setString(85, 20, ".", LCD_FONT_8, 0);
  lcd_show();
  HAL_Delay(700);
  lcd_setString(90, 20, ".", LCD_FONT_8, 0);
  lcd_show();
  lcd_clear(); 
  lcd_setFrame(0, 0, 127, 31);
  HAL_Delay(700);
}

void check_joystick(menu_navigation direction, menu_event current_event, void *data) {

  AppData* joystick_data = data;
  if(current_event == MENU_DC_EVENT) {
    switch (direction) {
    case MENU_UP:
      joystick_data->current.mode = SOFT_STOP;
      break;
    case MENU_DOWN:
      joystick_data->current.mode = FAST_STOP;
      break;
    case MENU_BACKWARD:
      joystick_data->current.mode = COUNTER_CLOCK_WISE;
      break;
    case MENU_FORWARD:
      joystick_data->current.mode = CLOCK_WISE;
      break;        
    default:
      break;
    }
  }
  else if(current_event == MENU_SETTINGS_DC_EVENT) {
    switch (direction) {        
    case MENU_DOWN:
      joystick_data->current.number_of_samples = 5;
      break;
    case MENU_BACKWARD:
      if(joystick_data->current.number_of_samples > 1)
        joystick_data->current.number_of_samples--;
      break;
    case MENU_FORWARD:
      if(joystick_data->current.number_of_samples < 20)
        joystick_data->current.number_of_samples++;
      break;        
    default:
      break;
    }    
  }
  else if(current_event == MENU_SETTINGS_PSC_EVENT) {
    switch (direction) {        
    case MENU_BACKWARD:      
        joystick_data->current.PSC_on = 0;
      break;
    case MENU_FORWARD:
        joystick_data->current.PSC_on = 1;
      break;        
    default:
      break;
    }
  }
}

void motor_menu(void *data) {
	AppData* motor_data = data;
  
  switch (motor_data->current.mode) {
  case CLOCK_WISE:
    HAL_GPIO_WritePin(DC_EN_GPIO_Port, DC_EN_Pin, GPIO_PIN_SET);
    if(motor_data->current.PSC_on)
      htim3.Instance->PSC = motor_data->averaged_over_5.pot1/100;
    else
      htim3.Instance->PSC = Example_PSC-1;
    htim3.Instance->CCR1 = (ADCresolution + motor_data->averaged_over_5.pot2)/2;
    htim3.Instance->CCR2 = htim3.Instance->CCR1;
    break;
  case COUNTER_CLOCK_WISE:
    HAL_GPIO_WritePin(DC_EN_GPIO_Port, DC_EN_Pin, GPIO_PIN_SET);
    if(motor_data->current.PSC_on)
      htim3.Instance->PSC = motor_data->averaged_over_5.pot1/100;
    else
      htim3.Instance->PSC = Example_PSC-1;
    htim3.Instance->CCR1 = (ADCresolution - motor_data->averaged_over_5.pot2)/2;
    htim3.Instance->CCR2 = htim3.Instance->CCR1;
    break;
  case SOFT_STOP:
    HAL_GPIO_WritePin(DC_EN_GPIO_Port, DC_EN_Pin, GPIO_PIN_RESET);
    break;
  case FAST_STOP:
    HAL_GPIO_WritePin(DC_EN_GPIO_Port, DC_EN_Pin, GPIO_PIN_SET);
    htim3.Instance->CCR1 = ADCresolution;
    htim3.Instance->CCR2 = 0;
    break;
  default:
    break;
  }
}

void sendToUart(uint16_t curr_rot_speed) {

  uint16_t PWM_frequncy;
  char txBuffer[100];
  // Systick; counter; PWM frequency in [Hz]; speed of rotation in [rpm]
  ++message_counter;
  PWM_frequncy = HAL_RCC_GetPCLK1Freq()*2/((htim3.Instance->PSC+1)*(htim3.Instance->ARR+1));
	sprintf(&txBuffer[0],"counter = %6ld,Systick = %6ld,PWM_frequency = %d, rotation_speed = %d\n", message_counter, HAL_GetTick(), PWM_frequncy, curr_rot_speed);
	HAL_UART_Transmit(&huart2, (uint8_t *) &txBuffer[0], strlen(txBuffer),10);
}

void buzz_regulator(void *data) {
	AppData* buzz_data = data;

  HAL_GPIO_WritePin(SPEAKER_GPIO_Port, SPEAKER_Pin, GPIO_PIN_SET);
  htim2.Instance->PSC = buzz_data->current.pot2*2;
  htim2.Instance->CCR3 = buzz_data->current.pot1/410;
}