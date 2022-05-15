#include "wireless_slave.h"
#include "oled.h"
#include "WiFi.h"

#define CHANNEL 0

void InitESPNow()
{
    WiFi.mode(WIFI_AP);
    configDeviceAP();
    WiFi.disconnect();
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
            Serial.println(temperature);
            OLED_ShowTemperature(temperature);
        }
    }
}
void configDeviceAP()
{
    const char *SSID = "Slave_1";
    bool result = WiFi.softAP(SSID, "Slave_1_Password", CHANNEL, 0);
    if (!result)
    {
        Serial.println("AP Config failed.");
    }
    else
    {
        Serial.println("AP Config Success. Broadcasting with AP: " + String(SSID));
    }
}
