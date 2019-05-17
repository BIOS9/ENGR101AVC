#include "logger.h"
#include "motors.h"
#include "E101.h"

Motors::Motors() {
    logMsg("Motors starting up...", "Motors", INFO);
}

Motors::~Motors() {
    //stop(0); // Stop motors
}

void Motors::SetMotorSpeed(Motor motor, int speed) {
    if(speed > 100 || speed < -100) // Check for invalid speed. Speed must be between -100 and 100
    {
        logMsg("Invalid motor speed given: \"%d\" speed must be between -100 and 100.", "Motors", WARNING, speed);
        return;
    }

    if(motor == RIGHT){
        rightMotorValue = interpolateMotorSpeed(speed);
        logMsg("Left motor speed set to: %d (Actual value: %d)", "Motors", DEBUG, speed, rightMotorValue);
    }
    else if(motor == LEFT) {
        leftMotorValue = interpolateMotorSpeed(-speed);
        logMsg("Left motor speed set to: %d (Actual value: %d)", "Motors", DEBUG, speed, leftMotorValue);
    }
}

int Motors::interpolateMotorSpeed(int value) {
    if(value > 0)
        return 65;
    else if(value < 0)
        return 30;
    else
        return 48;
}

void Motors::UpdateMotors() {
    logMsg("Updating motors...", "Motors", DEBUG);
    set_motors(1, leftMotorValue);
    set_motors(5, rightMotorValue);
    hardware_exchange();
}