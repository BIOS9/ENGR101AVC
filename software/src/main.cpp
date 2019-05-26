// Was thinking we could use a class for each stage?
// Then in here just call the class when we detect that the next stage has begun.
#include <stdlib.h> 
#include <math.h>
#include "logger.h"
#include "camera.h"
#include "motors.h"
#include "network.h"
#include "pid.h"
#include "E101.h"

Camera *camera;
Motors *motors;
Network *network;
PID *pid;

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
    pid = new PID(STAGE2_KP, STAGE2_KI, STAGE2_KD); // Uses defined PID gains, can be tuned in PID header
    network = new Network((char*)"130.195.6.196", 1024);

    while(true) {
        int lineErr = camera->GetLineError();

        if(!camera->IsLineVisible())
            motors->StepBack(REVERSE_DURATION);

        float pidVal = pid->GetOutput(lineErr);

        int leftSpeed = 30;
        int rightSpeed = 30;

        if(pidVal < 0)
            rightSpeed -= abs(pidVal);
        if(pidVal > 0)
            leftSpeed -= abs(pidVal);

        motors->SetMotorSpeed(LEFT, -leftSpeed);
        motors->SetMotorSpeed(RIGHT, -rightSpeed);
        motors->UpdateMotors();
    }

    stoph();
    return 0;
}
