 #ifndef SERVER_H
 #define SERVER_H

#include <Ethernet.h>
#include "controller.h"

const byte mac[] = {0x2C, 0xF7, 0xF1, 0x08, 0x0D, 0x32};
const IPAddress ip(192, 168, 1, 22);
const EthernetServer server(80);
const EthernetClient httpClient;
/**
* \brief Starts an EthernetServer at the IPAdress, also setups the controller.  
*/
void serverSetup();

/**
* \brief Constantly checks for new requests. When a new request is received the controller is instructed to handle this. 
*/
void serverLoop();

/**
* \brief Translates a request send by the client to the corresponding values in the ServerInput struct. 
* @param client Ethernetclient
* @return The messagedata in a ServerInput struct.
*/
ServerInput handleRequest(EthernetClient client);

/**
* \brief Reads the message send by the client. It counts the number of elements and puts them in the given array until a '/' is encountered.
* @param client Ethernetclient
* @param buf Char array in which the read elements will be stored.
* @return The number of elements read before a '/' was encountered.
*/
int read_until_slash(EthernetClient client, char* buf);

/**
* \brief Casts the the elements in the char array to a single int using the ASCII table. 
* @param buf Array with the chars
* @param length Number of elements in the char array.
* @return The read char as an int.
*/
int castChartoInt(char* buf, char length);
 #endif /* SERVER_H */
