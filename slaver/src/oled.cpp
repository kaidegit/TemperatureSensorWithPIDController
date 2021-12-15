#include "oled.h"

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(
    /* reset=*/U8X8_PIN_NONE);

void OLED_Init()
{
    u8x8.begin();
    u8x8.setPowerSave(0);
}

void OLED_ShowTemperature(float temp)
{
    char ch[30];
    sprintf(ch, "temperature:%.2f", temp);
    u8x8.drawString(0, 0, ch);
    u8x8.refreshDisplay();
}