/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_chart_1;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_temp_label;
	lv_obj_t *screen_btn_alarm;
	lv_obj_t *screen_btn_alarm_label;
	lv_obj_t *screen_btn_pid;
	lv_obj_t *screen_btn_pid_label;
	lv_obj_t *pid;
	lv_obj_t *pid_label_1;
	lv_obj_t *pid_label_2;
	lv_obj_t *pid_label_3;
	lv_obj_t *pid_P_value;
	lv_obj_t *pid_I_value;
	lv_obj_t *pid_target;
	lv_obj_t *pid_btn_back_p;
	lv_obj_t *pid_btn_back_p_label;
	lv_obj_t *alarm;
	lv_obj_t *alarm_lmeter_1;
	lv_obj_t *alarm_label_1;
	lv_obj_t *alarm_set_temperature;
	lv_obj_t *alarm_btn_back_a;
	lv_obj_t *alarm_btn_back_a_label;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_pid(lv_ui *ui);
void setup_scr_alarm(lv_ui *ui);

#ifdef __cplusplus
}
#endif
#endif