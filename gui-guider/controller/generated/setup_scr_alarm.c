/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_alarm(lv_ui *ui){

	//Write codes alarm
	ui->alarm = lv_obj_create(NULL, NULL);

	//Write codes alarm_lmeter_1
	ui->alarm_lmeter_1 = lv_linemeter_create(ui->alarm, NULL);

	//Write style LV_LINEMETER_PART_MAIN for alarm_lmeter_1
	static lv_style_t style_alarm_lmeter_1_main;
	lv_style_reset(&style_alarm_lmeter_1_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_lmeter_1_main
	lv_style_set_radius(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 1);
	lv_style_set_bg_color(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 5);
	lv_style_set_line_color(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_line_width(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_style_set_line_opa(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_scale_grad_color(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_scale_end_color(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, lv_color_make(0x8b, 0x89, 0x8b));
	lv_style_set_scale_width(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 10);
	lv_style_set_scale_end_line_width(&style_alarm_lmeter_1_main, LV_STATE_DEFAULT, 4);
	lv_obj_add_style(ui->alarm_lmeter_1, LV_LINEMETER_PART_MAIN, &style_alarm_lmeter_1_main);
	lv_obj_set_pos(ui->alarm_lmeter_1, 60, 19);
	lv_obj_set_size(ui->alarm_lmeter_1, 200, 200);
	lv_linemeter_set_scale(ui->alarm_lmeter_1, 300, 50);
	lv_linemeter_set_range(ui->alarm_lmeter_1, 0, 100);
	lv_linemeter_set_value(ui->alarm_lmeter_1, 50);
	lv_linemeter_set_angle_offset(ui->alarm_lmeter_1, 0);

	//Write codes alarm_label_1
	ui->alarm_label_1 = lv_label_create(ui->alarm, NULL);
	lv_label_set_text(ui->alarm_label_1, "设定温度");
	lv_label_set_long_mode(ui->alarm_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->alarm_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for alarm_label_1
	static lv_style_t style_alarm_label_1_main;
	lv_style_reset(&style_alarm_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_label_1_main
	lv_style_set_radius(&style_alarm_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_alarm_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_alarm_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_alarm_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alarm_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_alarm_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_alarm_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_alarm_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_alarm_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_alarm_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_alarm_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_alarm_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->alarm_label_1, LV_LABEL_PART_MAIN, &style_alarm_label_1_main);
	lv_obj_set_pos(ui->alarm_label_1, 108, 84);
	lv_obj_set_size(ui->alarm_label_1, 100, 0);

	//Write codes alarm_set_temperature
	ui->alarm_set_temperature = lv_label_create(ui->alarm, NULL);
	lv_label_set_text(ui->alarm_set_temperature, "0");
	lv_label_set_long_mode(ui->alarm_set_temperature, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->alarm_set_temperature, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for alarm_set_temperature
	static lv_style_t style_alarm_set_temperature_main;
	lv_style_reset(&style_alarm_set_temperature_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_set_temperature_main
	lv_style_set_radius(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_alarm_set_temperature_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->alarm_set_temperature, LV_LABEL_PART_MAIN, &style_alarm_set_temperature_main);
	lv_obj_set_pos(ui->alarm_set_temperature, 108, 128);
	lv_obj_set_size(ui->alarm_set_temperature, 100, 0);
}