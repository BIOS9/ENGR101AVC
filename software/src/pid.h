#ifndef PID_H // Header guard
#define PID_H 


// PID gain constants for stage 2 (curvy line)
#define STAGE2_KP 0.003 // Proportional gain
#define STAGE2_KI 0.01 // Integral gain
#define STAGE2_KD 100 // Derivative gain

class PID {
public:
    PID(float kp, float ki, float kd); // Constructor
    ~PID(); // Destructor
    
    float GetOutput(float error); // Gets PID control output based on error signal

private:
    float proportionalGain;
    float integralGain;
    float derivativeGain;

    float totalIntegral;

    float lastDerivativeError;
    clock_t lastDerivativeClock;

    // Clamps to prevent integral wind-up
    const float integralClampUpper = 90;
    const float integralClampLower = -90;

    float getProportion(float error);
    float getIntegral(float error);
    float getDerivative(float error);
};

#endif // End of header guard