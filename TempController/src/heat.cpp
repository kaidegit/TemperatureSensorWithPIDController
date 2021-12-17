#include "heat.h"

void Heater_Init()
{
    ledcSetup(0, 180, 10);
    ledcAttachPin(HEAT_Pin, 0);
    ledcWrite(0, 0);
}

void Heater_SetDuty(float duty)
{
    ledcWrite(0, int(duty / 100 * 1024));
}