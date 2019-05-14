// Was thinking we could use a class for each stage?
// Then in here just call the class when we detect that the next stage has begun.
#include "logger.h"
#include "camera.h"
#include "network.h"

Camera *camera;
Network *network;

/**
 * Main entry point for the program
 */
int main(void) {
    logMsg("Program starting up...", "Main", INFO);
    camera = new Camera();
    network = new Network((char *)"130.195.6.196", 1024);

    return 0;
}