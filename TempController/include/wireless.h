#pragma once

#include "Arduino.h"
#include "esp_now.h"

void InitESPNow();

bool manageSlave();

void sendData(uint8_t data);

void SendTemperature(float temperature);

extern esp_now_peer_info_t slave;