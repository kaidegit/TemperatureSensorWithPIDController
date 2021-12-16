#include "btn.h"
#include "gui_guider.h"
#include "esp_task_wdt.h"

void Btn_Init()
{
    pinMode(BTN_1_Pin, INPUT);
    pinMode(BTN_2_Pin, INPUT);
    pinMode(BTN_3_Pin, INPUT);
}

void Btn_Scan(void *parm)
{
    int btn1, btn2, btn3;
    while (true)
    {
        btn1 = digitalRead(BTN_1_Pin);
        btn2 = digitalRead(BTN_2_Pin);
        btn3 = digitalRead(BTN_3_Pin);
        if ((btn1 == LOW) || (btn2 == LOW) || (btn3 == LOW))
        {
            delay(10);
            btn1 = digitalRead(BTN_1_Pin);
            btn2 = digitalRead(BTN_2_Pin);
            btn3 = digitalRead(BTN_3_Pin);
            if ((btn1 == LOW) || (btn2 == LOW) || (btn3 == LOW))
            {
                auto now_scr = lv_scr_act();
                if (now_scr == guider_ui.screen)
                {
                    // TODO: main screen
                }
                else if (now_scr == guider_ui.alarm)
                {
                    //TODO
                }
                else if (now_scr == guider_ui.pid)
                {
                    //TODO
                }
            }
            while ((btn1 == HIGH) && (btn2 == HIGH) && (btn3 == HIGH))
            {
                btn1 = digitalRead(BTN_1_Pin);
                btn2 = digitalRead(BTN_2_Pin);
                btn3 = digitalRead(BTN_3_Pin);
            }
        }
        esp_task_wdt_reset();
        delay(50);
    }
}