#include "ClientX.h"
EthernetUDP udp;

void InitalizeClient()
{
  //Write ip address, mac address of client
  uint8_t mac[6] = {0x10, 0x21, 0x03, 0x05, 0x02, 0x01};
  Ethernet.begin(mac, IPAddress(192, 168, 1, 6));
}

void SendToServer(const uint8_t * message,size_t l)
{
  
   
  int success;
  do
  {
    //Write ip address of the server
    success = udp.beginPacket(IPAddress(192, 168, 1, 16), 5000);
  }
  while (!success);
  
  if (success)
  {
     success=udp.write(message,l);
     String go=message;
     Serial.println(go);
     Serial.println(success);
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
      char* msg = (char*)malloc(success+1);
        int len = udp.read(msg,success+1);
        msg[len]=0;
        Serial.print("received: '");
        Serial.print(msg);
        free(msg);
      
    }
    while ((success = udp.available()) > 0);
    udp.flush();
    /////////How to stop???///////////////////////
    udp.stop();
  }
  return message;
}
