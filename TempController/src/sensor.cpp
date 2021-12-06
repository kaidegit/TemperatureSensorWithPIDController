#include "main.h"
#include "sensor.h"
#include "Arduino.h"

OneWire ds(SENSOR_Pin);
float temperature;
uint8_t addr[8];

// 初始化读取18b20地址并保存
void Sensor_Init()
{

    if (!ds.search(addr))
    {
        Serial.println("No more addresses.");
        Serial.println();
        ds.reset_search();
        delay(250);
        return;
    }

    Serial.print("ROM =");
    for (uint8_t i = 0; i < 8; i++)
    {
        Serial.write(' ');
        Serial.print(addr[i], HEX);
    }
    if (OneWire::crc8(addr, 7) != addr[7])
    {
        Serial.println("CRC is not valid!");
        return;
    }
}

void Sensor_Read(void *parm)
{
    uint8_t data[12];

    while (true)
    {
        ds.reset();
        ds.select(addr);
        ds.write(0x44, 1);

        delay(1000);

        ds.reset();
        ds.select(addr);
        ds.write(0xBE);
        int16_t raw = (data[1] << 8) | data[0];
        uint8_t cfg = (data[4] & 0x60);
        // at lower res, the low bits are undefined, so let's zero them
        if (cfg == 0x00)
            raw = raw & ~7; // 9 bit resolution, 93.75 ms
        else if (cfg == 0x20)
            raw = raw & ~3; // 10 bit res, 187.5 ms
        else if (cfg == 0x40)
            raw = raw & ~1; // 11 bit res, 375 ms
                            //// default is 12 bit resolution, 750 ms conversion time
        temperature = (float)raw / 16.0;

        delay(500);
    }
}