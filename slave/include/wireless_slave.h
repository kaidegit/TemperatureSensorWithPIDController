#pragma once

#include "Arduino.h"
#include "esp_now.h"

void InitESPNow();

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len);

void configDeviceAP();
