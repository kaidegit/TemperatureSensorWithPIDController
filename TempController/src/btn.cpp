#include "btn.h"
#include "gui_guider.h"
#include "esp_task_wdt.h"
#include "sensor.h"
#include "pid.h"

void Btn_Init()
{
    pinMode(BTN_1_Pin, INPUT_PULLUP);
    pinMode(BTN_2_Pin, INPUT_PULLUP);
    pinMode(BTN_3_Pin, INPUT_PULLUP);
}

void Btn_Scan(void *parm)
{
    int btn1, btn2, btn3;
    int pid_set_state = 0;
    int pid_kp, pid_ki, pid_target;
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
            Serial.printf("btns' states : %d %d %d\n", btn1, btn2, btn3);
            if ((btn1 == LOW) || (btn2 == LOW) || (btn3 == LOW))
            {
                auto now_scr = lv_scr_act();
                if (now_scr == guider_ui.screen)
                {
                    if (btn1 == LOW) // 跳转到alarm
                    {
                        lv_scr_load(guider_ui.alarm);
                        alarm_value = int(temperature);
                        lv_linemeter_set_value(guider_ui.alarm_lmeter_1, alarm_value);
                        char ch[30];
                        sprintf(ch, "%d", alarm_value);
                        lv_label_set_text(guider_ui.alarm_set_temperature, ch);
                        alarm_flag = false;
                        pid_flag = false;
                    }
                    else if (btn2 == LOW) // 跳转到pid
                    {
                        // Serial.printf("goto pid\n");
                        lv_scr_load(guider_ui.pid);
                        pid_set_state = 0;
                        pid_kp = 1;
                        pid_ki = 1;
                        pid_target = int(temperature);
                        char ch[30];
                        sprintf(ch, "%d", pid_kp);
                        lv_textarea_set_text(guider_ui.pid_P_value, ch);
                        sprintf(ch, "%d", pid_ki);
                        lv_textarea_set_text(guider_ui.pid_I_value, ch);
                        sprintf(ch, "%d", pid_target);
                        lv_textarea_set_text(guider_ui.pid_target, ch);
                        lv_textarea_set_cursor_hidden(guider_ui.pid_P_value, false);
                        lv_textarea_set_cursor_hidden(guider_ui.pid_I_value, true);
                        lv_textarea_set_cursor_hidden(guider_ui.pid_target, true);
                        alarm_flag = false;
                        pid_flag = false;
                    }
                }
                else if (now_scr == guider_ui.alarm)
                {
                    // not tested yet
                    if (btn1 == LOW) // 减小报警数值
                    {
                        alarm_value--;
                        lv_linemeter_set_value(guider_ui.alarm_lmeter_1, alarm_value);
                        char ch[30];
                        sprintf(ch, "%d", alarm_value);
                        lv_label_set_text(guider_ui.alarm_set_temperature, ch);
                    }
                    else if (btn2 == LOW) // 增加报警数值
                    {
                        alarm_value++;
                        lv_linemeter_set_value(guider_ui.alarm_lmeter_1, alarm_value);
                        char ch[30];
                        sprintf(ch, "%d", alarm_value);
                        lv_label_set_text(guider_ui.alarm_set_temperature, ch);
                    }
                    else if (btn3 == LOW) // 保存返回
                    {
                        alarm_flag = true;
                        lv_scr_load(guider_ui.screen);
                    }
                }
                else if (now_scr == guider_ui.pid)
                {
                    if (btn1 == LOW) // 减小数值
                    {
                        switch (pid_set_state)
                        {
                        case 0:
                            pid_kp >= 1 ? pid_kp-- : pid_kp;
                            break;
                        case 1:
                            pid_ki >= 1 ? pid_ki-- : pid_ki;
                            break;
                        case 2:
                            pid_target >= 1 ? pid_target-- : pid_target;
                            break;
                        default:
                            break;
                        }
                        char ch[30];
                        sprintf(ch, "%d", pid_kp);
                        lv_textarea_set_text(guider_ui.pid_P_value, ch);
                        sprintf(ch, "%d", pid_ki);
                        lv_textarea_set_text(guider_ui.pid_I_value, ch);
                        sprintf(ch, "%d", pid_target);
                        lv_textarea_set_text(guider_ui.pid_target, ch);
                    }
                    else if (btn2 == LOW) // 增加数值
                    {
                        switch (pid_set_state)
                        {
                        case 0:
                            pid_kp <= 100 ? pid_kp++ : pid_kp;
                            break;
                        case 1:
                            pid_ki <= 100 ? pid_ki++ : pid_ki;
                            break;
                        case 2:
                            pid_target <= 100 ? pid_target++ : pid_target;
                            break;
                        default:
                            break;
                        }
                        char ch[30];
                        sprintf(ch, "%d", pid_kp);
                        lv_textarea_set_text(guider_ui.pid_P_value, ch);
                        sprintf(ch, "%d", pid_ki);
                        lv_textarea_set_text(guider_ui.pid_I_value, ch);
                        sprintf(ch, "%d", pid_target);
                        lv_textarea_set_text(guider_ui.pid_target, ch);
                    }
                    else if (btn3 == LOW) // 下一项/保存返回
                    {
                        switch (pid_set_state)
                        {
                        case 0:
                            pid_set_state++;
                            lv_textarea_set_cursor_hidden(guider_ui.pid_P_value, true);
                            lv_textarea_set_cursor_hidden(guider_ui.pid_I_value, false);
                            lv_textarea_set_cursor_hidden(guider_ui.pid_target, true);
                            break;
                        case 1:
                            pid_set_state++;
                            lv_textarea_set_cursor_hidden(guider_ui.pid_P_value, true);
                            lv_textarea_set_cursor_hidden(guider_ui.pid_I_value, true);
                            lv_textarea_set_cursor_hidden(guider_ui.pid_target, false);
                            break;
                        case 2:
                            pid_set_state = 0;
                            pid_flag = true;
                            kp = pid_kp;
                            ki = pid_ki;
                            target = pid_target;
                            PID_Reset();
                            // TODO go back to main and cal pid
                            lv_scr_load(guider_ui.screen);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            while ((btn1 == LOW) || (btn2 == LOW) || (btn3 == LOW))
            {
                btn1 = digitalRead(BTN_1_Pin);
                btn2 = digitalRead(BTN_2_Pin);
                btn3 = digitalRead(BTN_3_Pin);
                esp_task_wdt_reset();
                delay(50);
            }
        }
        esp_task_wdt_reset();
        delay(50);
    }
}