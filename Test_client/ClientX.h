#ifndef CLIENTX_H_
#define CLIENTX_H_
#include <Arduino.h>
#include <UIPEthernet.h>
#include <SPI.h>

void InitalizeClient();
void SendToServer(String message);
String ReadMessage();








#endif
