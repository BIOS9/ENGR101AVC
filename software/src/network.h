/**
 * Network class to connect to the network gate and open it.
 */

#ifndef NETWORK_H // Header guard
#define NETWORK_H

class Network {
public:
    Network(char *ip, int port); // Constructor
    ~Network(); // Destructor
    void OpenGate();

private:
    char * IPAddr;
    int portNumber;
};

#endif // End of header guard