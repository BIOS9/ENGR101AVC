#ifndef MOTORS_H // Header guard
#define MOTORS_H

#define REVERSE_DURATION 250
#define REVERSE_SPEED 30

enum Motor {
    LEFT,
    RIGHT
};

class Motors {
public:
    Motors();
    ~Motors();
    void SetMotorSpeed(Motor motor, int speed); // Sets speed of either motor -100 to 100, 0 is stop (Doesnt actually change speed, update must be called)
    void StepBack(int milliseconds); // Reverses both motors at same speed for milliseconds
    void StopAll(); // Stops all motors
    void Stop(Motor motor); // Stops a specific motor
    void UpdateMotors(); // Actually updates speed of motors after the values have been set

private:
    int leftMotorValue;
    int rightMotorValue;
    static float lerp(float a, float b, float fraction); // Linear interpolation function
    static int interpolateMotorSpeed(int speed); // Corrects weird motor speed values
};

#endif // End of header guard