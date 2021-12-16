#include <Arduino.h>
#include "main.h"
#include "freertos/FreeRTOS.h"
#include "sensor.h"
#include "gui.h"
#include "esp_now.h"
#include "gui_guider.h"
#include "wireless.h"
#include "WiFi.h"

lv_ui guider_ui;
lv_chart_series_t *screen_chart_1_0;

void setup()
{
    pinMode(26, OUTPUT);
    digitalWrite(26, HIGH);
    // static lv_chart_series_t *ser1 = lv_chart_add_series(guider_ui.screen_chart_1, lv_color_make(0x00, 0x00, 0x00));
    Serial.begin(115200);

    // Serial.println("HelloWorld");
    GUI_Init();
    setup_ui(&guider_ui);
    xTaskCreate(GUI_Run, "GUI_Task", 4096 * 4, NULL, 3, NULL);


    ESPNow_Init();

    // Sensor_Init();

    // xTaskCreate(Sensor_Read, "Sensor_Read_Task", 4096, NULL, 3, NULL);

    // tft.begin(); // 初始化TFT
    // tft.setRotation(3);
    // tft.invertDisplay(0);

    screen_chart_1_0 = lv_chart_add_series(guider_ui.screen_chart_1, lv_color_make(0x00, 0x00, 0x00));
    lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, 12);
    lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, 32);
    lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, 90);
    lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, 23);
    lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, 32);
}

void loop()
{
    // tft.fillScreen(TFT_RED);
    // delay(1000);
    // tft.fillScreen(TFT_GREEN);
    // delay(1000);
    // tft.fillScreen(TFT_BLUE);
    // delay(1000);
    // tft.fillScreen(TFT_BLACK);
    // delay(1000);

    // lv_task_handler();
    // delay(5);
    delay(100);
    SendTemperature(12.34);
}
