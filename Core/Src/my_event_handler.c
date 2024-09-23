/**
 * @file my_event_handler.c
 * @ref <MechatronicsProjectOne>
 * @author Silvan Spiess <silvan.spiess@bfh-student.ch>
 * @copyright Bern University of Applied Sciences
 *            Silvan Spiess 
 * @version v1.0.0
 * @date 16. March. 2024
 * 
 * @brief This file handles functions process events, such as menu entry, menu exit and menu call back (every 20ms)
 */

#include "my_event_handler.h"

void drawMenuItem_Callback2(int event, void* data) {
  AppData* data_callback = data;

	switch (event) {
  case MENU_RLED_EVENT:
    print_display(event, data_callback);
		break;
  case MENU_GLED_EVENT:
		break;
  case MENU_BLED_EVENT:
		break;
	case MENU_MANUAL_SUB1_EVENT:
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
    print_display(event, data_callback);
		break;
  case MENU_MANUAL_SUB2_EVENT:
		break;
  case MENU_SPEAKER_NOR_EVENT:
    buzz_regulator(data_callback);
    print_display(event, data_callback);
    break;
  case MENU_SPEAKER_MEL_EVENT:
    htim2.Instance->PSC = data_callback->current.pot1;
    MusicPlayer(0, -50);
    print_display(event, data_callback);
    break;
	case MENU_POT_EVENT:
		print_display(event, data_callback);
		break; 
  case MENU_DC_EVENT:
    motor_menu(data_callback);    
    print_display(event, data_callback); 
    sendToUart(data_callback->current.rotation_speed);  
		break;
  case MENU_SETTINGS_DC_EVENT:
 		print_display(event, data_callback);
    break;
  case MENU_SETTINGS_PSC_EVENT:
 		print_display(event, data_callback);
		break;
	default: 
    break;
	}
}

void handleMenuEntryEvent(int event, AppData *data) {
  switch (event) {
  case MENU_RLED_EVENT:
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_GLED_EVENT: 
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
		break;
  case MENU_BLED_EVENT: 
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_MANUAL_SUB1_EVENT:
		break;
  case MENU_MANUAL_SUB2_EVENT:
		break;
  case MENU_SPEAKER_NOR_EVENT:
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
    break;
  case MENU_SPEAKER_MEL_EVENT:
    MusicPlayer(1, -50);
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
    break;
  case MENU_POT_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
		break;
  case MENU_DC_EVENT:
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);    
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
    break;
  case MENU_SETTINGS_DC_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
    break;
  case MENU_SETTINGS_PSC_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 1);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
    break;
  default:
    break;
  }
}

void handleMenuExitEvent(int event, AppData *data) {
  switch (event) {
  case MENU_RLED_EVENT:
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_GLED_EVENT: 
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_BLED_EVENT: 
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_SPEAKER_NOR_EVENT:
    HAL_GPIO_WritePin(SPEAKER_GPIO_Port, SPEAKER_Pin, GPIO_PIN_RESET);
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
    break;
   case MENU_SPEAKER_MEL_EVENT:
    HAL_GPIO_WritePin(SPEAKER_GPIO_Port, SPEAKER_Pin, GPIO_PIN_RESET);
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
    break;
  case MENU_MANUAL_SUB1_EVENT:
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_MANUAL_SUB2_EVENT:
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_POT_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		break;
  case MENU_DC_EVENT:
    HAL_GPIO_WritePin(DC_EN_GPIO_Port, DC_EN_Pin, GPIO_PIN_RESET);    
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);    
    HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
    HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
    break;
  case MENU_SETTINGS_DC_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
    break;
  case MENU_SETTINGS_PSC_EVENT:
 		HAL_GPIO_WritePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin, 0);
 		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
  default:
    break;
  }
}