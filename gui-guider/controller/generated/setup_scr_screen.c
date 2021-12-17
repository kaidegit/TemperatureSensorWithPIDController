/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_chart_1
	ui->screen_chart_1 = lv_chart_create(ui->screen, NULL);

	//Write style LV_CHART_PART_BG for screen_chart_1
	static lv_style_t style_screen_chart_1_bg;
	lv_style_reset(&style_screen_chart_1_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_chart_1_bg
	lv_style_set_bg_color(&style_screen_chart_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_chart_1_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_chart_1_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_chart_1_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_screen_chart_1_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen_chart_1, LV_CHART_PART_BG, &style_screen_chart_1_bg);

	//Write style LV_CHART_PART_SERIES_BG for screen_chart_1
	static lv_style_t style_screen_chart_1_series_bg;
	lv_style_reset(&style_screen_chart_1_series_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen_chart_1_series_bg
	lv_style_set_line_color(&style_screen_chart_1_series_bg, LV_STATE_DEFAULT, lv_color_make(0xe8, 0xe8, 0xe8));
	lv_style_set_line_width(&style_screen_chart_1_series_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_line_opa(&style_screen_chart_1_series_bg, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_chart_1, LV_CHART_PART_SERIES_BG, &style_screen_chart_1_series_bg);
	lv_obj_set_pos(ui->screen_chart_1, 16, 45);
	lv_obj_set_size(ui->screen_chart_1, 205, 155);
	lv_chart_set_type(ui->screen_chart_1,LV_CHART_TYPE_LINE);
	lv_chart_set_range(ui->screen_chart_1,0,100);
	lv_chart_set_div_line_count(ui->screen_chart_1, 3, 5);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_1, "温度曲线");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_1
	static lv_style_t style_screen_label_1_main;
	lv_style_reset(&style_screen_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_1_main
	lv_style_set_radius(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
	lv_style_set_text_letter_space(&style_screen_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_1, LV_LABEL_PART_MAIN, &style_screen_label_1_main);
	lv_obj_set_pos(ui->screen_label_1, 55, 16);
	lv_obj_set_size(ui->screen_label_1, 100, 0);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_label_2, "实时温度");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_label_2
	static lv_style_t style_screen_label_2_main;
	lv_style_reset(&style_screen_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_2_main
	lv_style_set_radius(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_label_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
	lv_style_set_text_letter_space(&style_screen_label_2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_label_2, LV_LABEL_PART_MAIN, &style_screen_label_2_main);
	lv_obj_set_pos(ui->screen_label_2, 227, 15);
	lv_obj_set_size(ui->screen_label_2, 87, 0);

	//Write codes screen_temp_label
	ui->screen_temp_label = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_temp_label, "0");
	lv_label_set_long_mode(ui->screen_temp_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_temp_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_temp_label
	static lv_style_t style_screen_temp_label_main;
	lv_style_reset(&style_screen_temp_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_temp_label_main
	lv_style_set_radius(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_temp_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_temp_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_temp_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_temp_label_main, LV_STATE_DEFAULT, &lv_font_simsun_18);
	lv_style_set_text_letter_space(&style_screen_temp_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_temp_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_temp_label, LV_LABEL_PART_MAIN, &style_screen_temp_label_main);
	lv_obj_set_pos(ui->screen_temp_label, 220, 49);
	lv_obj_set_size(ui->screen_temp_label, 100, 0);

	//Write codes screen_btn_alarm
	ui->screen_btn_alarm = lv_btn_create(ui->screen, NULL);

	//Write style LV_BTN_PART_MAIN for screen_btn_alarm
	static lv_style_t style_screen_btn_alarm_main;
	lv_style_reset(&style_screen_btn_alarm_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_alarm_main
	lv_style_set_radius(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_btn_alarm_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_btn_alarm, LV_BTN_PART_MAIN, &style_screen_btn_alarm_main);
	lv_obj_set_pos(ui->screen_btn_alarm, 230, 99);
	lv_obj_set_size(ui->screen_btn_alarm, 80, 40);
	ui->screen_btn_alarm_label = lv_label_create(ui->screen_btn_alarm, NULL);
	lv_label_set_text(ui->screen_btn_alarm_label, "设定报警");
	lv_obj_set_style_local_text_color(ui->screen_btn_alarm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_btn_alarm_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_16);

	//Write codes screen_btn_pid
	ui->screen_btn_pid = lv_btn_create(ui->screen, NULL);

	//Write style LV_BTN_PART_MAIN for screen_btn_pid
	static lv_style_t style_screen_btn_pid_main;
	lv_style_reset(&style_screen_btn_pid_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_btn_pid_main
	lv_style_set_radius(&style_screen_btn_pid_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen_btn_pid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_btn_pid_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_btn_pid_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_btn_pid_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen_btn_pid_main, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen_btn_pid_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_btn_pid_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen_btn_pid_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen_btn_pid_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_btn_pid, LV_BTN_PART_MAIN, &style_screen_btn_pid_main);
	lv_obj_set_pos(ui->screen_btn_pid, 230, 160);
	lv_obj_set_size(ui->screen_btn_pid, 80, 40);
	ui->screen_btn_pid_label = lv_label_create(ui->screen_btn_pid, NULL);
	lv_label_set_text(ui->screen_btn_pid_label, "设定PI");
	lv_obj_set_style_local_text_color(ui->screen_btn_pid_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen_btn_pid_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_16);

	//Write codes screen_state
	ui->screen_state = lv_label_create(ui->screen, NULL);
	lv_label_set_text(ui->screen_state, "");
	lv_label_set_long_mode(ui->screen_state, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen_state, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen_state
	static lv_style_t style_screen_state_main;
	lv_style_reset(&style_screen_state_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_state_main
	lv_style_set_radius(&style_screen_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen_state_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen_state_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen_state_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen_state_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_letter_space(&style_screen_state_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen_state_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen_state_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen_state, LV_LABEL_PART_MAIN, &style_screen_state_main);
	lv_obj_set_pos(ui->screen_state, 27, 211);
	lv_obj_set_size(ui->screen_state, 100, 0);
}