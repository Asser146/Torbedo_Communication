#include "ClientX.h"
void setup() {
  Serial.begin(9600);
InitalizeClient();
}

void loop() {
  uint8_t *msg="Hello server";
  SendToServer(msg,16);
  String mesg =  ReadMessage();
  Serial.println(mesg);
  delay(10);
}
