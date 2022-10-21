
#include <SPI.h>
#include <UIPEthernet.h>
 
 
EthernetUDP udp;
unsigned long next;
 
 
void setup() {
 
  uint8_t mac[6] = {0x10, 0x21, 0x03, 0x05, 0x02, 0x01};
  Serial.begin(9600);
  Ethernet.begin(mac, IPAddress(192, 168, 1, 6));
 
  next = millis() + 5000;
 
}
 
void loop() {
 
 
 
  while (true) {
 
    int success;
    int len = 0;
 
    if (millis() > next)
    {
      do
      {
        success = udp.beginPacket(IPAddress(192, 168, 1, 16), 5000);
        //Serial.println(success);
      }
      while (!success && (millis() < next));
      if (success)
      {
        success = udp.write("hello world from menna", 24); //worked after adding size (,24)  /string vs char
        Serial.println(success);
        success = udp.endPacket();
        do
        {
          //check for new udp-packet:
          success = udp.parsePacket();
        }
        while (!success && (millis() < next));
        if (success)
        {
          do
          {
            char c = udp.read();
            len++;
          }
          while ((success = udp.available()) > 0);
 
          //finish reading this packet:
          udp.flush();
        }
      }
      udp.stop();
      next = millis() + 5000;
    }
  }

}
