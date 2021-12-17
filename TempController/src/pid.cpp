#include "pid.h"

float sum_err;
float last_err;
float tao;

void PID_Init()
{
    kp = 1;
    ki = 1;
    target = 0;
    sum_err = 0;
    last_err = 0;
    tao = 0.5;
}

void PID_Reset()
{
    sum_err = 0;
    last_err = 0;
}

float PID_Calculate(float present)
{
    auto err = target - present;
    sum_err += err;
    last_err = err;

    auto out = kp * (err + tao / ki * sum_err);
    return out;
}