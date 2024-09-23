/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.c
  * @brief   This file provides code for the configuration
  *          of the ADC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "music_player.h"
#include "tim.h"
/*
//StarWars melody
int melodia[] = {
  a, a, a, f,
  cH, a, f, cH,
  a,
  eH, eH, eH,
  fH, cH, gS, f,
  cH, a,

  aH, a, a, aH,
  gSH, gH, fSH, fH,
  fSH,
  aS, dSH, dH, cSH,
  cH, bb, cH,

  f, gS, f, a, cH , eH,
  aH, a, a, aH,
  gSH, gH, fSH, fH,
  fSH,
  aS, dSH, dH, cSH,
  cH, bb, cH,
  f, gS, f, cH, a, f, cH, a, cH, a, a
};
//StarWars tempo
int tempo[] = {
  500, 500, 500, 350,
  150, 500, 350, 150,
  650,
  500, 500, 500,
  350, 150, 500, 350,
  150, 1000,

  500, 300, 150, 500,
  325, 175, 125, 125,
  500,
  250, 500, 325, 175,
  125, 125, 500,
  250, 500, 350, 125, 500, 375, //125, 650,
  500, 300, 150, 500,
  325, 175, 125, 125,
  500,
  250, 500, 325, 175,
  125, 125, 500,
  250, 500, 375, 125, 500, 375, 125, 1000, 125, 1000, 1000
};*/
int melodia[] = {
  a, a, a, f, 
  cH, a, f, cH, 
  a,
  eH, eH, eH,
  fH, cH, gS, f,
  cH, a,

  aH, a, a, aH,
  gSH, gH, fSH, fH,
  fSH,
  aS, dSH, dH, cSH,
  cH, bb, cH,

  f, gS, f, a, cH, eH,
  aH, a, a, aH,
  gSH, gH, fSH, fH,
  fSH,
  aS, dSH, dH, cSH,
  cH, bb, cH
};

int tempo[] = {
  500, 500, 500, 350,
  150, 500, 350, 150,
  650,
  500, 500, 500,
  350, 150, 500, 350,
  150, 1000,

  500, 300, 150, 500,
  325, 175, 125, 125,
  500,
  250, 500, 325, 175,
  125, 125, 500,

  250, 500, 350, 125, 500, 375,
  500, 300, 150, 500,
  325, 175, 125, 125,
  500, 
  250, 500, 325, 175,
  125, 125, 500, 
  //250,  500, 375, 125, 1000, 125, 1000, 1000
};

#define delay_var 50

#if(0)
void MusicPlayer(int PresentStatusMusic, int Speed) { //Dice se la musica è finita

  int i = 0;
  int DimensionOfArrayMelody = sizeof(melodia);
  htim2.Instance->PSC = 800-1;
  while(i < DimensionOfArrayMelody) {
    HAL_TIM_OC_Start (&htim2, TIM_CHANNEL_3);//start timer
    htim2.Instance->ARR = melodia[i]; // vary the duty cycle
    HAL_Delay (tempo[i]); // wait for time
    HAL_Delay (delay_var); // wait for 50 ms
    HAL_TIM_OC_Stop(&htim2, TIM_CHANNEL_3);//stop timer 
    HAL_Delay (delay_var); // wait for 50 ms
    i++;
  }
  HAL_TIM_OC_Stop(&htim2, TIM_CHANNEL_3);//stop timer  
}
#endif

#if(1)
uint32_t ValTempo;


void MusicPlayer(int PresentStatusMusic, int Speed) {  

  static int i = 0;
  static int PastStatusMusic = 0;
  static int StartMusic = 0;

  int song_length = sizeof(melodia) / sizeof(melodia[0]);

  if((PastStatusMusic == 0) && (PresentStatusMusic == 1)) { 
    i = 0;
    ValTempo = HAL_GetTick();
    StartMusic = 1;
  }
  if((i < song_length) && (StartMusic == 1)) {
    htim2.Instance->ARR = melodia[i];
    HAL_TIM_OC_Start(&htim2, TIM_CHANNEL_3);
    
    if(HAL_GetTick() > (ValTempo + tempo[i] + delay_var + Speed)) { // Used to avoid HALDELAY()
      HAL_TIM_OC_Stop(&htim2, TIM_CHANNEL_3);
      if(HAL_GetTick() > (ValTempo + tempo[i] + delay_var + delay_var + Speed)) {
        i++;
        ValTempo = HAL_GetTick();
      }
    }
    PastStatusMusic = PresentStatusMusic;
  }  
}
#endif