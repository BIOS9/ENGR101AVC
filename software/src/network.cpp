#include "network.h"
#include "logger.h"
#include "E101.h"

Network::Network(char *ip, int port) {
    logMsg("Network starting up...", "Network", DEBUG);
    IPAddr = ip;
    portNumber = port;
}

void Network::OpenGate() {
    logMsg("Opening gate...", "Network", INFO);
    logMsg("Connecting to server...", "Network", DEBUG);
    connect_to_server(IPAddr, portNumber);

    char password[24];

    logMsg("Sending please...", "Network", DEBUG);
    send_to_server("Please");

    logMsg("Receiving password...", "Network", DEBUG);
    receive_from_server(password); 

    logMsg("Sending password...", "Network", DEBUG);
    send_to_server(password);

    logMsg("Finished opening gate.", "Network", DEBUG);
}