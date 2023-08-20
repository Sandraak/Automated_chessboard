 #ifndef SERVER_H
 #define SERVER_H

// #include <SPI.h>
#include <Ethernet.h>

const byte mac[] = {0x2C, 0xF7, 0xF1, 0x08, 0x0D, 0x32};
const IPAddress ip(192, 168, 1, 22);
const EthernetServer server(80);
const EthernetClient httpClient;

void serverSetup();
void serverLoop();
int read_until_slash(EthernetClient client, int* buf);
void handleRequest(EthernetClient client);
// int clientAvailable();
// char clientRead();
// char clientPeek();

 #endif /* MOTOR_H */
