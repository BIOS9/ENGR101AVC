#include "logger.h"
#include "motors.h"
#include "E101.h"

const int MAX_MOTOR_SPEED = 65;
const int STOP_MOTOR_SPEED = 48;
const int MIN_MOTOR_SPEED = 30;

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

// Got this function off of stackoverflow
float Motors::lerp(float a, float b, float fraction) {
    return (a * (1.0 - fraction)) + (b * fraction);
}

int Motors::interpolateMotorSpeed(int value) {
    if(value > 0)
        return (int)lerp(STOP_MOTOR_SPEED, MAX_MOTOR_SPEED, float(value) / 100.0);
    else if(value < 0)
        return (int)lerp(MIN_MOTOR_SPEED, STOP_MOTOR_SPEED, float(100 - value) / 100.0);
    else
        return STOP_MOTOR_SPEED;
}

void Motors::UpdateMotors() {
    logMsg("Updating motors...", "Motors", DEBUG);
    set_motors(1, leftMotorValue);
    set_motors(5, rightMotorValue);
    hardware_exchange();
}