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

    for(int i = 0; i < 3; ++i) {
        motors->SetMotorSpeed(LEFT, 100);
        motors->SetMotorSpeed(RIGHT, 100);
        motors->UpdateMotors();
        sleep1(2000);

        motors->SetMotorSpeed(LEFT, 0);
        motors->SetMotorSpeed(RIGHT, 0);
        motors->UpdateMotors();
        sleep1(2000);

        motors->SetMotorSpeed(LEFT, -100);
        motors->SetMotorSpeed(RIGHT, -100);
        motors->UpdateMotors();
        sleep1(2000);
    }

    motors->SetMotorSpeed(LEFT, 0);
    motors->SetMotorSpeed(RIGHT, 0);
    motors->UpdateMotors();
    sleep1(2000);
    for(int i = -100; i <= 100; ++i)
    {
        motors->SetMotorSpeed(LEFT, 0);
        motors->UpdateMotors();
        sleep1(50);
    }
    motors->SetMotorSpeed(LEFT, 0);
    motors->SetMotorSpeed(RIGHT, 0);
    motors->UpdateMotors();

    stoph();
    return 0;
}