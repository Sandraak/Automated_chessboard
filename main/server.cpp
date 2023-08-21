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
    // Serial.println(F("new client"));
    handleServerInput(handleRequest(httpClient));
    delay(1);
    httpClient.stop();  // close connection
    // Serial.println("client disconnected");
  }
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

ServerInput handleRequest(EthernetClient client) {
  ServerInput message{ false, 0, 0, 0 };
  char buf[80];
  // Ignore part before first slash (GET /)
  char length = read_until_slash(client, buf);
  // delay(1);
  length = read_until_slash(client, buf);
  if (buf[0] == 'p') {
    message.poll = true;
    // delay(1);
    // //poll
    return message;
  } else {
    // int x_from = castChartoInt(buf, length);
    message.from.x = castChartoInt(buf, length);
    length = read_until_slash(client, buf);
    // int y_from = castChartoInt(buf, length);
    message.from.y = castChartoInt(buf, length);
    length = read_until_slash(client, buf);
    // int x_to = castChartoInt(buf, length);
    message.to.x = castChartoInt(buf, length);
    length = read_until_slash(client, buf);
    // int y_to = castChartoInt(buf, length);
    message.to.y = castChartoInt(buf, length);
    // magnet on/off
    length = read_until_slash(client, buf);
    bool magnet = buf[0] - 48;
    message.magnetStatus = magnet;
  }
  return message;
}

int castChartoInt(char* buf, char length) {
  int result;
  if (length == 1) {
    result = buf[0] - 48;
  } else {
    if (buf[0] == '-') {
      result = (buf[1] - 48) * -1;
    } else {
      result = ((buf[0] - 48) * 10) + (buf[1] - 48);
    }
  }
  return result;
}