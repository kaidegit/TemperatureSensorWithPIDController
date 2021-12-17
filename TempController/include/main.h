#pragma once

#include "gui_guider.h"

#define SENSOR_Pin 14

#define BTN_1_Pin 4
#define BTN_2_Pin 16
#define BTN_3_Pin 17

#define BEEPER_Pin 26

#define HEAT_Pin 27

extern lv_ui guider_ui;
extern lv_chart_series_t *screen_chart_1_0;
extern int32_t alarm_value;
extern bool alarm_flag;
extern int16_t kp, ki, target;
extern bool pid_flag;
extern bool i_enabled_flag;
