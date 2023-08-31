#include "HardwareSerial.h"
#include "server.h"

void serverSetup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  controllerSetup();
}

void serverLoop() {
  httpClient = server.available();
  if (httpClient) {
    ServerInput message = handleRequest(httpClient);
    delay(1);
    httpClient.stop();  // close connection
    handleServerInput(message); //move motors
  }
}

ServerInput handleRequest(EthernetClient client) {
  ServerInput message{ false, {0,0}, 0 };
  char buf[80];
  // Ignore part before first slash (GET /)
  char length = read_until_slash(client, buf);
  length = read_until_slash(client, buf);
  if (buf[0] == 'p') {
    message.poll = true;
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println("Connection: close");
    client.println(getPosreached());
    return message;
  } else {
    message.to.x = castChartoInt(buf, length);
    length = read_until_slash(client, buf);
    message.to.y = castChartoInt(buf, length);
    length = read_until_slash(client, buf);
    bool magnet = buf[0] - 48;
    message.magnetStatus = magnet;
  }
  return message;
}

int read_until_slash(EthernetClient client, char* buf) {
  char index = 0;
  int current = client.read();
  while (current != '/' && current != '\n' && current != '\r') {
    buf[index] = current;
    index++;
    current = client.read();
  }
  return index;
}

int castChartoInt(char* buf, char length) {
  int result;
  if (length == 1) {
    result = buf[0] - 48; //ASCII TABLE
  } else {
    if (buf[0] == '-') {
      result = (buf[1] - 48) * -1;
    } else {
      result = ((buf[0] - 48) * 10) + (buf[1] - 48);
    }
  }
  return result;
}