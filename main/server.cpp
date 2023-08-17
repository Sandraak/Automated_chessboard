#include "server.h"

void serverSetup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void serverLoop() {
  httpClient = server.available();
  if (httpClient) {
    Serial.print("in dah loop");
    Serial.println(F("new client"));
    // handleResponse();
    delay(1);
    httpClient.stop();  // close connection
    Serial.println("client disconnected");
  }
}


// make httpClient methods available as ordinary functions
int clientAvailable() {
  return httpClient.connected() && httpClient.available();
}

char clientRead() {
  return httpClient.read();
}
char clientPeek() {
  return httpClient.peek();
}