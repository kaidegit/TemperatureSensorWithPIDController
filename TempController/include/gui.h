#pragma once

#include "main.h"
#include "TFT_eSPI.h"
#include "lvgl.h"

void GUI_Init();

void GUI_Run(void *parm);

extern TFT_eSPI tft;