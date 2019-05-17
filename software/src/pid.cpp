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
    
    logMsg("PID output: %f", "PID", DEBUG, val);
    lastDerivativeClock = 0;
    return val;
}

float PID::getProportion(float error) {
    return proportionalGain * error;
}

float PID::getIntegral(float error) {
    float value = integralGain * (totalIntegral += error);

    // Apply clamps to prevent wind-up
    if(totalIntegral > integralClampUpper) {
        logMsg("PID integral clamped to upper bound.", "PID", DEBUG);
        totalIntegral = integralClampUpper;
    }
    
    if(totalIntegral < integralClampLower) {
        logMsg("PID integral clamped to lower bound.", "PID", DEBUG);
        totalIntegral = integralClampLower;
    }

    return value;
}

float PID::getDerivative(float error) {    
    double currentClock = static_cast<double>(clock());
    
    // If this is the first run, the last clock will be null so skip
    if(lastDerivativeClock == 0) {
        logMsg("PID derivative has no pervious value, skipping...", "PID", DEBUG);
        lastDerivativeClock = currentClock;
        return 0;
    }

    // Calculate differences in values since last measurement
    double timeDiff = currentClock - lastDerivativeClock;
    double errorDiff = error - lastDerivativeError;

    lastDerivativeError = error;

    // Ensures there is no divide by 0 error if measurements are too fast and this the time difference is 0 (when represented by a float)
    // Returns 0 so derivative has no effect
    if(timeDiff == 0) {
        logMsg("PID derivative time difference is 0! Are the measurements too fast?", "PID", WARNING);
        return 0;
    }

    return static_cast<float>(errorDiff / timeDiff);
}