#include <Arduino.h>
#include "main.h"
#include "freertos/FreeRTOS.h"
#include "sensor.h"
#include "gui.h"
#include "gui_guider.h"
#include "wireless.h"
#include "beeper.h"
#include "btn.h"
#include "pid.h"
#include "heat.h"
#include "esp_task_wdt.h"

lv_ui guider_ui;
lv_chart_series_t *screen_chart_1_0;
int32_t alarm_value;
bool alarm_flag;
int16_t kp, ki, target;
bool pid_flag;
bool i_enabled_flag;

void setup()
{
    alarm_value = 50;
    alarm_flag = false;
    kp = 1;
    ki = 1;
    target = 0;
    pid_flag = false;
    i_enabled_flag = true;

    Beeper_Init();
    Heater_Init();
    PID_Init();

    Serial.begin(115200);
    // Serial.println("HelloWorld");

    GUI_Init();
    setup_ui(&guider_ui);
    screen_chart_1_0 = lv_chart_add_series(guider_ui.screen_chart_1, lv_color_make(0x00, 0x00, 0x00));
    xTaskCreatePinnedToCore(GUI_Run, "GUI_Task", 4096 * 4, NULL, 2, NULL, 1);

    Btn_Init();
    xTaskCreate(Btn_Scan, "Btn_Scan_Task", 4096, NULL, 3, NULL);

    Sensor_Init();
    xTaskCreate(Sensor_Read, "Sensor_Read_Task", 4096, NULL, 1, NULL);

    ESPNow_Init();
}

void loop()
{
    // lv_task_handler();
    // delay(5);

    // SendTemperature(12.34);

    if (alarm_flag && (temperature > alarm_value))
    {
        Beeper_On();
    }
    else
    {
        Beeper_Off();
    }

    if (pid_flag)
    {
        auto heat = PID_Calculate(temperature);
        if (heat < 0)
        {
            heat = 0;
        }
        else if (heat > 100)
        {
            heat = 100;
        }
        Heater_SetDuty(heat);
        char ch[30];
        sprintf(ch, "pidout:%d", int(heat));
        lv_label_set_text(guider_ui.screen_state, ch);
    }
    else
    {
        Heater_SetDuty(0);
    }

    esp_task_wdt_reset();
    delay(200);
}
