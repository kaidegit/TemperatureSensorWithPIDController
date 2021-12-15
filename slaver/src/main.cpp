#include "Arduino.h"
#include "main.h"
#include "wireless_slaver.h"

void setup(){
  // Init ESPNow with a fallback logic
  InitESPNow();
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info.
  esp_now_register_recv_cb(OnDataRecv);
}

void loop(){

}