#ifndef PID_H // Header guard
#define PID_H 

#define STAGE2_KP 1
#define STAGE2_KD 1
#define STAGE2_KI 1

class PID {
public:
    PID(float kp, float ki, float kd); // Constructor
    ~PID(); // Destructor
    
    float GetOutput(float error); // Gets PID control output based on error signal

private:
    float proportionalGain;
    float integralGain;
    float derivativeGain;

    float getProportional(float error);
    float getIntegral(float error);
    float getDerivative(float error);
};

#endif // End of header guard