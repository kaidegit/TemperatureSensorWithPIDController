#include "oled.h"

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(
    /* clock=*/19, /* data=*/22, /* reset=*/U8X8_PIN_NONE);

void OLED_Init()
{
    pinMode(19, OUTPUT);
    pinMode(22, OUTPUT);
    digitalWrite(19, 0);
    digitalWrite(22, 0);
    u8x8.begin();
    u8x8.setPowerSave(0);
}

void OLED_ShowTemperature(float temp)
{
    char ch[30];
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.drawString(0, 0, "temperature:");
    sprintf(ch, "%.2f", temp);
    u8x8.drawString(0, 3, ch);
    u8x8.refreshDisplay();
}