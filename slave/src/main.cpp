#include "Arduino.h"
#include "main.h"
#include "wireless_slave.h"
#include "oled.h"

void setup()
{
    Serial.begin(115200);
    OLED_Init();
    InitESPNow();
}

void loop()
{
    delay(10);
}