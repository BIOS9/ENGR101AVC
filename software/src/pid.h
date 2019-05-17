#ifndef PID_H // Header guard
#define PID_H 

// PID gain constants for stage 2 (curvy line)
#define STAGE2_KP 1 // Proportional gain
#define STAGE2_KI 1 // Integral gain
#define STAGE2_KD 1 // Derivative gain

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

    // Clamps to prevent integral wind-up
    const float integralClampUpper = 90;
    const float integralClampLower = -90;

    float getProportional(float error);
    float getIntegral(float error);
    float getDerivative(float error);
};

#endif // End of header guard