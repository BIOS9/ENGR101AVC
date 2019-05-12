#include "network.h"
#include "E101.h"

Network::Network(char *ip, int port) {
    IPAddr = ip;
    portNumber = port;
}

void Network::OpenGate() {
    connect_to_server(IPAddr, portNumber);

    char password[24];
    send_to_server("Please");
    receive_from_server(password); 
    send_to_server(password);
}