#include "ClientX.h"
void setup() {

}

void loop() {
  InitalizeClient();
  SendToServer("Hello server");
  String msg =  ReadMessage();
  Serial.println(msg);
}
