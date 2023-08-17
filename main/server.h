 #ifndef SERVER_H
 #define SERVER_H

//  #include <Arduino.h>
 #include <SPI.h>
 #include <Ethernet.h>

const byte mac[] = {0x2C, 0xF7, 0xF1, 0x08, 0x0D, 0x32};
const IPAddress ip(192, 168, 1, 22);
const EthernetServer server(80);
const EthernetClient httpClient;

void serverSetup();
void serverLoop();
int clientAvailable();
void handleResponse();

char clientRead();
char clientPeek();

 #endif /* MOTOR_H */
