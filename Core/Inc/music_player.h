/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.h
  * @brief   This file contains all the function prototypes for
  *          the adc.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __MUSICPLAYER_H__
#define __MUSICPLAYER_H__

#include "main.h"

#define DO 367 //c4
#define RE 326 //d4
#define MI 292 //e4
#define FA 275 //f4
#define SOL 245 //g4
#define LA 218 //a4
#define SI 194 //b4

#define c 367 //c4
#define d 326 //d4
#define e 292 //e4
#define f 275 //f4
#define g 245 //g4
#define gS 231 //g4
#define a 218 //a4
#define aS 211 //g4
#define bb 194 //b4

#define cH 184 //c4
#define cSH 173 //d4
#define dH 164 //e4
#define dSH 154 //f4
#define eH 146 //g4
#define fH 138 //g4
#define fSH 129 //a4
#define gH 122 //g4
#define gSH 116 //b4
#define aH 109 //b4

void MusicPlayer(int PresentStatusMusic, int Speed);

#endif /* MUSICPLAYER_H_ */
