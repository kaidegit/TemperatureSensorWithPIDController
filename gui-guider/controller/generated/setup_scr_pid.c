/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t * kb;
static void kb_event_cb(lv_obj_t * event_kb, lv_event_t event)
{
	/* Just call the regular event handler */
	lv_keyboard_def_event_cb(event_kb, event);
	if(event == LV_EVENT_APPLY || event == LV_EVENT_CANCEL){
		if(NULL != kb){
			lv_obj_del(kb);
		}
	}
}
static void text_area_event_cb(lv_obj_t* ta, lv_event_t event)
{

	if(event == LV_EVENT_CLICKED){
		 if( !lv_debug_check_obj_valid(kb) ){
			/* Create a keyboard and make it fill the width of the above text areas */
			kb = lv_keyboard_create(lv_scr_act(), NULL);
			lv_obj_set_event_cb(kb, kb_event_cb);
			lv_obj_set_size(kb,  LV_HOR_RES, LV_VER_RES / 2);
		}
		lv_keyboard_set_textarea(kb, ta);
		lv_keyboard_set_cursor_manage(kb, true); 
	}
}

void setup_scr_pid(lv_ui *ui){

	//Write codes pid
	ui->pid = lv_obj_create(NULL, NULL);

	//Write codes pid_label_1
	ui->pid_label_1 = lv_label_create(ui->pid, NULL);
	lv_label_set_text(ui->pid_label_1, "P");
	lv_label_set_long_mode(ui->pid_label_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->pid_label_1, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for pid_label_1
	static lv_style_t style_pid_label_1_main;
	lv_style_reset(&style_pid_label_1_main);

	//Write style state: LV_STATE_DEFAULT for style_pid_label_1_main
	lv_style_set_radius(&style_pid_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_label_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_label_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_label_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_pid_label_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_label_1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_label_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pid_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pid_label_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pid_label_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pid_label_1, LV_LABEL_PART_MAIN, &style_pid_label_1_main);
	lv_obj_set_pos(ui->pid_label_1, 22, 55);
	lv_obj_set_size(ui->pid_label_1, 100, 0);

	//Write codes pid_label_2
	ui->pid_label_2 = lv_label_create(ui->pid, NULL);
	lv_label_set_text(ui->pid_label_2, "I");
	lv_label_set_long_mode(ui->pid_label_2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->pid_label_2, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for pid_label_2
	static lv_style_t style_pid_label_2_main;
	lv_style_reset(&style_pid_label_2_main);

	//Write style state: LV_STATE_DEFAULT for style_pid_label_2_main
	lv_style_set_radius(&style_pid_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_label_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_label_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_label_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_pid_label_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_label_2_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_label_2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pid_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pid_label_2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pid_label_2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pid_label_2, LV_LABEL_PART_MAIN, &style_pid_label_2_main);
	lv_obj_set_pos(ui->pid_label_2, 24, 105);
	lv_obj_set_size(ui->pid_label_2, 100, 0);

	//Write codes pid_label_3
	ui->pid_label_3 = lv_label_create(ui->pid, NULL);
	lv_label_set_text(ui->pid_label_3, "target");
	lv_label_set_long_mode(ui->pid_label_3, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->pid_label_3, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for pid_label_3
	static lv_style_t style_pid_label_3_main;
	lv_style_reset(&style_pid_label_3_main);

	//Write style state: LV_STATE_DEFAULT for style_pid_label_3_main
	lv_style_set_radius(&style_pid_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_label_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_label_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_label_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_pid_label_3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_label_3_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_label_3_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_pid_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_pid_label_3_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_pid_label_3_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->pid_label_3, LV_LABEL_PART_MAIN, &style_pid_label_3_main);
	lv_obj_set_pos(ui->pid_label_3, 26, 161);
	lv_obj_set_size(ui->pid_label_3, 100, 0);

	//Write codes pid_P_value
	ui->pid_P_value = lv_textarea_create(ui->pid, NULL);

	//Write style LV_PAGE_PART_BG for pid_P_value
	static lv_style_t style_pid_P_value_bg;
	lv_style_reset(&style_pid_P_value_bg);

	//Write style state: LV_STATE_DEFAULT for style_pid_P_value_bg
	lv_style_set_radius(&style_pid_P_value_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_pid_P_value_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_pid_P_value_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_P_value_bg, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_pid_P_value_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->pid_P_value, LV_PAGE_PART_BG, &style_pid_P_value_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for pid_P_value
	static lv_style_t style_pid_P_value_scrollable;
	lv_style_reset(&style_pid_P_value_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_pid_P_value_scrollable
	lv_style_set_radius(&style_pid_P_value_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_P_value_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_P_value_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_P_value_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_P_value_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_P_value, LV_PAGE_PART_SCROLLABLE, &style_pid_P_value_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for pid_P_value
	static lv_style_t style_pid_P_value_edge_flash;
	lv_style_reset(&style_pid_P_value_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_pid_P_value_edge_flash
	lv_style_set_radius(&style_pid_P_value_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_P_value_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_P_value_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_P_value_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_P_value_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_P_value, LV_PAGE_PART_EDGE_FLASH, &style_pid_P_value_edge_flash);
	lv_obj_set_pos(ui->pid_P_value, 175, 50);
	lv_obj_set_size(ui->pid_P_value, 120, 25);
	lv_textarea_set_text(ui->pid_P_value,"0");
	lv_obj_set_event_cb(ui->pid_P_value, text_area_event_cb);
	lv_textarea_set_text_align(ui->pid_P_value, LV_LABEL_ALIGN_LEFT);

	//Write codes pid_I_value
	ui->pid_I_value = lv_textarea_create(ui->pid, NULL);

	//Write style LV_PAGE_PART_BG for pid_I_value
	static lv_style_t style_pid_I_value_bg;
	lv_style_reset(&style_pid_I_value_bg);

	//Write style state: LV_STATE_DEFAULT for style_pid_I_value_bg
	lv_style_set_radius(&style_pid_I_value_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_pid_I_value_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_pid_I_value_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_I_value_bg, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_pid_I_value_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->pid_I_value, LV_PAGE_PART_BG, &style_pid_I_value_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for pid_I_value
	static lv_style_t style_pid_I_value_scrollable;
	lv_style_reset(&style_pid_I_value_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_pid_I_value_scrollable
	lv_style_set_radius(&style_pid_I_value_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_I_value_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_I_value_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_I_value_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_I_value_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_I_value, LV_PAGE_PART_SCROLLABLE, &style_pid_I_value_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for pid_I_value
	static lv_style_t style_pid_I_value_edge_flash;
	lv_style_reset(&style_pid_I_value_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_pid_I_value_edge_flash
	lv_style_set_radius(&style_pid_I_value_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_I_value_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_I_value_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_I_value_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_I_value_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_I_value, LV_PAGE_PART_EDGE_FLASH, &style_pid_I_value_edge_flash);
	lv_obj_set_pos(ui->pid_I_value, 174, 100);
	lv_obj_set_size(ui->pid_I_value, 123, 24);
	lv_textarea_set_text(ui->pid_I_value,"32767");
	lv_obj_set_event_cb(ui->pid_I_value, text_area_event_cb);
	lv_textarea_set_text_align(ui->pid_I_value, LV_LABEL_ALIGN_LEFT);

	//Write codes pid_target
	ui->pid_target = lv_textarea_create(ui->pid, NULL);

	//Write style LV_PAGE_PART_BG for pid_target
	static lv_style_t style_pid_target_bg;
	lv_style_reset(&style_pid_target_bg);

	//Write style state: LV_STATE_DEFAULT for style_pid_target_bg
	lv_style_set_radius(&style_pid_target_bg, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_pid_target_bg, LV_STATE_DEFAULT, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_text_color(&style_pid_target_bg, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_pid_target_bg, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_right(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_top(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_bottom(&style_pid_target_bg, LV_STATE_DEFAULT, 2);
	lv_obj_add_style(ui->pid_target, LV_PAGE_PART_BG, &style_pid_target_bg);

	//Write style LV_PAGE_PART_SCROLLABLE for pid_target
	static lv_style_t style_pid_target_scrollable;
	lv_style_reset(&style_pid_target_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_pid_target_scrollable
	lv_style_set_radius(&style_pid_target_scrollable, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_target_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_target_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_target_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_target_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_target, LV_PAGE_PART_SCROLLABLE, &style_pid_target_scrollable);

	//Write style LV_PAGE_PART_EDGE_FLASH for pid_target
	static lv_style_t style_pid_target_edge_flash;
	lv_style_reset(&style_pid_target_edge_flash);

	//Write style state: LV_STATE_DEFAULT for style_pid_target_edge_flash
	lv_style_set_radius(&style_pid_target_edge_flash, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_pid_target_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_pid_target_edge_flash, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_pid_target_edge_flash, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_pid_target_edge_flash, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->pid_target, LV_PAGE_PART_EDGE_FLASH, &style_pid_target_edge_flash);
	lv_obj_set_pos(ui->pid_target, 177, 152);
	lv_obj_set_size(ui->pid_target, 120, 27);
	lv_textarea_set_text(ui->pid_target,"0");
	lv_obj_set_event_cb(ui->pid_target, text_area_event_cb);
	lv_textarea_set_text_align(ui->pid_target, LV_LABEL_ALIGN_LEFT);
}