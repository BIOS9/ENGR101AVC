#ifndef MOTORS_H // Header guard
#define MOTORS_H

enum Motor {
    LEFT,
    RIGHT
};

class Motors {
public:
    Motors();
    ~Motors();
    void SetMotorSpeed(Motor motor, int speed); // Sets speed of either motor (Doesnt actually change speed, update must be called)
    void UpdateMotors(); // Actually updates speed of motors after the values have been set

private:
    int leftMotorValue;
    int rightMotorValue;

    static int interpolateMotorSpeed(int speed); // Corrects weird motor speed values
};

#endif // End of header guard