#pragma once

#include "OneWire.h"
#include "main.h"

void Sensor_Init();
void Sensor_Read(void *parm);

extern OneWire ds;
extern float temperature;
