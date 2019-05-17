#include <time.h>
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
    float val = getProportion(error) +
                getIntegral(error) +
                getDerivative(error);
    
    logMsg("PID output: %f", "PID", INFO, val);
    
    return val;
}

float PID::getProportion(float error) {
    return proportionalGain * error;
}

float PID::getIntegral(float error) {
    float value = integralGain * (totalIntegral += error);

    // Apply clamps to prevent wind-up
    if(totalIntegral > integralClampUpper)
        totalIntegral = integralClampUpper;
    
    if(totalIntegral < integralClampLower)
        totalIntegral = integralClampLower;

    return value;
}

float PID::getDerivative(float error) {    
    float currentClock = static_cast<float>(clock());
    
    // If this is the first run, the last clock will be null so skip
    if(lastDerivativeClock == NULL) {
        lastDerivativeClock = currentClock;
        return 0;
    }

    // Calculate differences in values since last measurement
    float timeDiff = currentClock - lastDerivativeClock;
    float errorDiff = error - lastDerivativeError;

    lastDerivativeError = error;

    // Ensures there is no divide by 0 error if measurements are too fast. 
    //Returns 0 so derivative has no effect
    if(timeDiff == 0)
        return 0;

    return errorDiff / timeDiff;
}