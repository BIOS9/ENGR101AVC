// Was thinking we could use a class for each stage?
// Then in here just call the class when we detect that the next stage has begun.
#include "logger.h"
#include "camera.h"

Camera *camera;

/**
 * Main entry point for the program
 */
int main(void) {
    logMsg("Program starting up...", INFO);
    camera = new Camera();

    return 0;
}