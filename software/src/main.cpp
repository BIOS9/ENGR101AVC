// Was thinking we could use a class for each stage?
// Then in here just call the class when we detect that the next stage has begun.
#include "logger.h"
#include "camera.h"
#include "motors.h"
#include "E101.h"

Camera *camera;
Motors *motors;
/**
 * Main entry point for the program
 */
int main(void) {
    logMsg("Program starting up...", "Main", INFO);
    int init(0);

    camera = new Camera();
    motors = new Motors();
    motors->UpdateMotors();

    int sleep1(2000);

    stoph();
    return 0;
}