 #ifndef SERVER_H
 #define SERVER_H

#include <Ethernet.h>
#include "controller.h"

const byte mac[] = {0x2C, 0xF7, 0xF1, 0x08, 0x0D, 0x32};
const IPAddress ip(192, 168, 1, 22);
const EthernetServer server(80);
const EthernetClient httpClient;

void serverSetup();
void serverLoop();
ServerInput handleRequest(EthernetClient client);
int read_until_slash(EthernetClient client, char* buf);
int castChartoInt(char* buf, char length);
 #endif /* SERVER_H */
