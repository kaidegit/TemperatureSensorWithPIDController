#include <Arduino.h>
#include "onewire.h"
#include "main.h"
#include "freertos/FreeRTOS.h"
#include "sensor.h"

void setup()
{
    Serial.begin(115200);
    Sensor_Init();

    xTaskCreate(Sensor_Read, "Sensor_Read", 4096, NULL, 3, NULL);
}

void loop()
{
    
}