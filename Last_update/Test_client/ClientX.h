#ifndef CLIENTX_H_
#define CLIENTX_H_
#include <Arduino.h>
#include <UIPEthernet.h>
#include <SPI.h>

void InitalizeClient();
void SendToServer(const uint8_t* message,size_t l);
String ReadMessage();








#endif
