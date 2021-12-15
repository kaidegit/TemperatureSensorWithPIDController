#pragma once

#include "Arduino.h"
#include "esp_now.h"

void ESPNow_Init();

bool manageSlave();

void sendData(uint8_t data);

void SendTemperature(float temperature);

void ScanForSlave();

extern esp_now_peer_info_t slave;