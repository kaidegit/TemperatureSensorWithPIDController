#include "gui.h"

TFT_eSPI tft;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[TFT_WIDTH * 10];

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);
void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *fn_name, const char *dsc);

void GUI_Init()
{
    lv_init(); // 初始化LVGL

    lv_log_register_print_cb((lv_log_print_g_cb_t)my_print); // 注册log输出组件

    tft.begin(); // 初始化TFT
    tft.setRotation(3);

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 10); // 注册buffer

    // 注册屏幕组件
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // 注册输入组件
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_ENCODER;
    indev_drv.read_cb = my_button_read;
    lv_indev_drv_register(&indev_drv);
}

void GUI_Run(void *parm)
{
    for (;;)
    {
        lv_task_handler();
        delay(5);
    }
}

void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *fn_name, const char *dsc)
{
    Serial.printf("%s(%s)@%d->%s", file, fn_name, line, dsc);
    Serial.println("");
    Serial.flush();
}

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void my_button_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    // TODO
    // if (digitalRead(WIO_KEY_B) == LOW)
    // {
    //     data->enc_diff = 1;
    // }
    // else if (digitalRead(WIO_KEY_C) == LOW)
    // {
    //     data->enc_diff = -1;
    // }
    // else
    // {
    //     data->enc_diff = 0;
    // }
    // data->state = (digitalRead(WIO_KEY_A) == LOW ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL);
}
