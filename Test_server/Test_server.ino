#include "ServerX.h"
void setup() {
  

}

void loop() {
 InitializeServer();
 String msg=ReadMessage();
 SendToClient("Hello");

}
