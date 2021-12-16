#include "beeper.h"

void Beeper_Init()
{
    pinMode(BEEPER_Pin, OUTPUT);
    digitalWrite(BEEPER_Pin, HIGH);
}

void Beeper_On()
{
    digitalWrite(BEEPER_Pin, LOW);
}

void Beeper_Off()
{
    digitalWrite(BEEPER_Pin, HIGH);
}