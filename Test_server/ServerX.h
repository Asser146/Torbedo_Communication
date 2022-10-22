#ifndef SERVERX_H_
#define SERVERX_H_
#include <Arduino.h>
#include <UIPEthernet.h>

void InitializeServer();
void LinkClient();
String ReadMessage();
void SendToClient(String message);
void RestartConnection(int port);

#endif
