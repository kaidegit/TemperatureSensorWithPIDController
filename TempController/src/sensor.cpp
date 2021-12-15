#include "main.h"
#include "OneWire.h"
#include <DallasTemperature.h>
#include "Arduino.h"

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

    while (true)
    {
        sensors.requestTemperatures(); // Send the command to get temperatures
        delay(1000);
        auto temp = sensors.getTempCByIndex(0);
        if (temp != DEVICE_DISCONNECTED_C)
        {
            Serial.print("Temperature for the device 1 (index 0) is: ");
            Serial.printf("%f\n", temp);
            temperature = temp;
        }
        else
        {
            Serial.println("Error: Could not read temperature data");
        }
        delay(500);
    }
}