#include "HardwareSerial.h"
#include "server.h"

void serverSetup() {
  // Serial.begin(9600);
  // Ethernet.begin(mac, ip);
  // server.begin();
  // Serial.print("server is at ");
  // Serial.println(Ethernet.localIP());
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void serverLoop() {
  httpClient = server.available();
  if (httpClient) {
    Serial.println(F("new client"));
    handleRequest(httpClient);
    delay(1);
    httpClient.stop();  // close connection
    Serial.println("client disconnected");
  }
  // // Serial.println("hoi");
  // httpClient = server.available();
  // Serial.println(F("new client"));
  // // handleRequest(httpClient);
  // // delay(10);
  // httpClient.stop();  // close connection
  // Serial.println("client disconnected");
}

int read_until_slash(EthernetClient client, int* buf) {
  int index = 0;
  int current = client.read();
  while (current != '/' && current != '\n' && current != '\r') {
    buf[index] = current;
    index++;
    current = client.read();
  }
  return index;
}

void handleRequest(EthernetClient client) {
  int buf[80];
  // Ignore part before first slash (GET /)
  int length = read_until_slash(client, buf);
  delay(1);
  length = read_until_slash(client, buf);
  if ((char)buf[0] == 'p') {
    Serial.println("poll");
    // delay(1);
    // //poll
    // client.println("HTTP/1.1 200 OK");
    // client.println("Content-Type: text/html");
    // client.println("Connection: close");  // the connection will be closed after completion of the response
    // client.println("Refresh: 5");         // refresh the page automatically every 5 sec
    // client.println();
    // client.println("<!DOCTYPE HTML>");
    // client.println("<html>");
    return;
  } else {
    // x coordinate
    length = read_until_slash(client, buf);
    int x;
    if (length == 1) {
      x = buf[0];
    } else {
      x = ((int)buf[0] * 10) + (int)buf[1];
    }
    // y coordinate
    length = read_until_slash(client, buf);
    int y;
    if (length == 1) {
      y = (int)buf[0];
    } else {
      y = ((int)buf[0] * 10) + (int)buf[1];
    }
    // magnet on/off
    length = read_until_slash(client, buf);
    bool magnet = (bool)buf[0];
    Serial.println(x);
    Serial.println(y);
    Serial.println(magnet);
  }
}

// // make httpClient methods available as ordinary functions
// int clientAvailable() {
//   return httpClient.connected() && httpClient.available();
// }

// char clientRead() {
//   return httpClient.read();
// }
// char clientPeek() {
//   return httpClient.peek();
// }