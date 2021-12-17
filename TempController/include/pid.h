#pragma once

#include "main.h"
#include "Arduino.h"

void PID_Init();

void PID_Reset();

float PID_Calculate(float present);