// Was thinking we could use a class for each stage?
// Then in here just call the class when we detect that the next stage has begun.
#include <stdlib.h> 
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
    
    int err = init(0); // Initialise the E101 library
    if(err != 0) {
        logMsg("Failed to initialise E101!", "Main", ERROR);
        exit(err); // An error occured, exit the program
    }

    camera = new Camera();
    motors = new Motors();

    for(int i = -100; i <= 100; ++i)
    {
        motors->SetMotorSpeed(LEFT, i);
        motors->SetMotorSpeed(RIGHT, -i);
        motors->UpdateMotors();
        sleep1(50);
    }
    motors->StopAll();
    sleep1(1000);
    motors->SetMotorSpeed(RIGHT, 100);
    motors->SetMotorSpeed(LEFT, 100);
    motors->UpdateMotors();
    sleep1(1000);
    motors->Stop(RIGHT);
    sleep1(1000);
    motors->Stop(LEFT);

    stoph();
    return 0;
}