 #ifndef SERVER_H
 #define SERVER_H
 #include <Arduino.h>
 #include "motor.h"
 #include <SPI.h>
 #include <Ethernet.h>

 
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
const byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
const IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
const EthernetServer server(80);


void server_setup();
void server_loop();
 #endif /* MOTOR_H */
