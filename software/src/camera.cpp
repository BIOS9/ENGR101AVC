#include "camera.hpp" 
#include "logger.h"

/**
 * Constructor for camera class
 */
Camera::Camera() {
    logMsg("Camera starting up...", DEBUG);

    int err = init(); // Initialise the E101 camera lib
    if(err != 0) {
        logMsg("Failed to initialise camera!", ERROR);
        exit(err); // An error occured, exit the program
    }

    logMsg("Camera started.", DEBUG);
}