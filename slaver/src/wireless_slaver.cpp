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
    esp_now_register_recv_cb(OnDataRecv);
}

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len)
{
    if (data_len == 4)
    {
        uint8_t magic_start = *data;
        uint8_t temp_unit = *(data + 1);
        uint8_t temp_deci = *(data + 2);
        uint8_t temp_crc = *(data + 3);
        if ((magic_start == 0x80) && (((temp_unit + temp_deci) & 0xff) == temp_crc))
        {
            float temperature = temp_unit + temp_deci / 100.0;
            OLED_ShowTemperature(temperature);
        }
    }
}