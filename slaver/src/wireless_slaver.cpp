#include "wireless_slaver.h"
#include "oled.h"

void InitESPNow()
{
    if (esp_now_init() == ESP_OK)
    {
        Serial.println("ESPNow Init Success");
    }
    else
    {
        Serial.println("ESPNow Init Failed");
        ESP.restart();
    }
}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
    if (data_len == 4)
    {
        if ((*(data) == 0x80) &&
            ((*(data + 3)) == (((*(data + 1)) + (*(data + 2))) & 0xff)))
        {
            float temperature = (*(data + 1)) + (*(data + 2)) / 100.0;
            OLED_ShowTemperature(temperature);
        }
    }
}