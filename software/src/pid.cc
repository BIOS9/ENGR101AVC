#include "pid.h"
#include "logger.h"

PID::PID(float kp, float ki, float kd) {
    logMsg("PID controller starting up...", "PID", INFO);

    // Set gains
    proportionalGain = kp;
    integralGain = ki;
    derivativeGain = kd;
}

float PID::GetOutput(float error) {
    return getProportional(error) +
           getIntegral(error) +
           getDerivative(error);
}

float PID::getProportional(float error) {
    return proportionalGain * error;
}

float PID::getIntegral(float error) {
    return 0;
}

float PID::getDerivative(float error) {
    return 0;
}