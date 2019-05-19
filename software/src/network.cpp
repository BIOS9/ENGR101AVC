#include "E101.h"
#include "logger.h"
#include "network.h" //class

Network::Network(char *ip, int port){
  logMsg("Network loading", "Network", DEBUG);
  IPAdd = ip; //IP address
  portNumber = port; //Port Number
}

void Network::OpenGate(){
  logMsg("Opening gate...", "Network", INFO); //Message to announce begining of opening gate
  logMsg("Connecting to server...", "Network", DEBUG);

  connect_to_server(IPAdd, portNumber); // Connect by sending IP adress and port number that we want to connect to

  char= message[24];//To save message

  send_to_server((char)"Please");//Send message to request password/message

  receive_from_server(message);//Receive message/password from server

  send_to_server(message);//Send message/password back to send_to_server

  //gate should open
}
