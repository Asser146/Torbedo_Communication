#include "ServerX.h"
void setup() {
  Serial.begin(9600);
InitializeServer();
}

void loop() {
 uint8_t *mesg="hello";
 String s=mesg;
 String msg=ReadMessage();
 Serial.println("recived");
 Serial.println(msg);
 
 SendToClient(mesg,s.length());
 
 RestartConnection(5000);
 
delay(10);
}
