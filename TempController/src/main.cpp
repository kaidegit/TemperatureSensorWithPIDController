#include <Arduino.h>
#include "onewire.h"
#include "main.h"
#include "freertos/FreeRTOS.h"
#include "sensor.h"
#include "gui.h"

void setup()
{
    Serial.begin(115200);

    GUI_Init();
    Sensor_Init();

    xTaskCreate(Sensor_Read, "Sensor_Read_Task", 4096, NULL, 3, NULL);
    xTaskCreate(GUI_Run, "GUI_Task", 4096, NULL, 3, NULL);
}

void loop()
{
    
}