#include <Arduino.h>
#include "main.h"
#include "freertos/FreeRTOS.h"
#include "sensor.h"
#include "gui.h"
#include "esp_now.h"



void setup()
{
    Serial.begin(115200);

    // GUI_Init();
    Sensor_Init();

    xTaskCreate(Sensor_Read, "Sensor_Read_Task", 4096, NULL, 3, NULL);

    tft.begin(); // 初始化TFT
    tft.setRotation(3);
    tft.invertDisplay(0);

    // xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 3, NULL);
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

    delay(1000);
}

