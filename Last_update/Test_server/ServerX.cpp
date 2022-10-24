#include "ServerX.h"
EthernetUDP udp;

void InitializeServer()
{
  //Set ip address,mac for the server
  uint8_t mac[6] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
  Ethernet.begin(mac, IPAddress(192, 168, 1, 16));
  int success = udp.begin(5000);
  Serial.print("Initialize: ");
  Serial.println(success ? "success" : "failed");
}
void LinkClient()
{ 
    Serial.print("remote ip: ");
    Serial.println(udp.remoteIP());
    Serial.print("remote port: ");
    Serial.println(udp.remotePort());
    //send new packet back to ip/port of client. This also
    //configures the current connection to ignore packets from
    //other clients!
}


String ReadMessage()
{
  int size;
   do{size = udp.parsePacket();}while(!size);
  String message = "";
  if (size > 0) {
    do
    {
      char* msg = (char*)malloc(size + 1);
      int len = udp.read(msg, size + 1);
      msg[len] = 0;

      //Serial.print("received: '");
      //Serial.print(msg);

      message += msg;
      free(msg);
    }
    while ((size = udp.available()) > 0);
    udp.flush();
    return message;
  }
  else
    return "No message";
}
void SendToClient(const uint8_t * message,size_t l)
{
  int success;
  do{success = udp.beginPacket(udp.remoteIP(),udp.remotePort());}while(!success);
  success = udp.write(message,l);
  Serial.print("bytes written: ");
  Serial.println(success);
  success = udp.endPacket();
  Serial.print("endPacket: ");
  Serial.println(success ? "success" : "failed");
}
void RestartConnection(int port)
{
  udp.stop();
  //restart with new connection to receive packets from other clients
  Serial.print("restart connection: ");
  Serial.println (udp.begin(port) ? "success" : "failed");
}
