#include "sensor.h"
#include "main.h"
#include "OneWire.h"
#include <DallasTemperature.h>
#include "Arduino.h"
#include "wireless.h"
#include "esp_task_wdt.h"
#include "gui_guider.h"

OneWire oneWire(SENSOR_Pin);
DallasTemperature sensors(&oneWire);

float temperature;
uint8_t addr[8];

void Sensor_Init()
{
    sensors.begin();
    sensors.setWaitForConversion(false);
}

void Sensor_Read(void *parm)
{
    uint8_t retry = 0;
    while (true)
    {
        sensors.requestTemperatures(); // Send the command to get temperatures
        esp_task_wdt_reset();
        delay(500);
        esp_task_wdt_reset();
        delay(500);
        while (retry < 10)
        {
            auto temp = sensors.getTempCByIndex(0);
            if ((temp != DEVICE_DISCONNECTED_C) && (temp != 85))
            {
                char ch[30];
                sprintf(ch, "%.2f", temp);
                Serial.print("Temperature for the device 1 (index 0) is: ");
                Serial.printf("%f\n", temp);
                temperature = temp;
                sprintf(ch, "%.2f", temperature);
                SendTemperature(temperature);
                lv_chart_set_next(guider_ui.screen_chart_1, screen_chart_1_0, int16_t(temperature));
                lv_label_set_text(guider_ui.screen_temp_label, ch);
                break;
            }
            else
            {
                retry++;
                esp_task_wdt_reset();
                delay(100);
                Serial.println("Error: Could not read temperature data");
            }
        }
        retry = 0;
        esp_task_wdt_reset();
        delay(500);
    }
}