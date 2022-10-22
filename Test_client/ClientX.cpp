#include "ClientX.h"
EthernetUDP udp;

void InitalizeClient()
{
  //Write ip address, mac address of client
  uint8_t mac[6] = {0x10, 0x21, 0x03, 0x05, 0x02, 0x01};
  Ethernet.begin(mac, IPAddress(192, 168, 1, 6));
}

void SendToServer(String message)
{
  int success;
  do
  {
    //Write ip address of the server
    success = udp.beginPacket(IPAddress(192, 168, 1, 16), 5000);
    //Serial.println(success);
  }
  while (!success);
  if (success)
  {
    udp.println(message);
    //success = udp.endPacket();
    udp.endPacket();
  }
}

String ReadMessage()
{
  int success;
  String message = "";
  do
  {
    success = udp.parsePacket();
  }
  while (!success);
  if (success)
  {
    do
    {
      char msg = udp.read();
      message += msg;
    }
    while ((success = udp.available()) > 0);
    udp.flush();
    /////////How to stop???///////////////////////
    udp.stop();
  }
  return message;
}
