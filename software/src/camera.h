/**
 * Camera class to handle image capture and processing
 * 
 * Author: Matthew Corfiatis
 * Date: 13/05/2019
 */

#ifndef CAMERA_H // Header guard
#define CAMERA_H 

#include "E101.h"
#include <iostream>

using namespace std;

class Camera {
public:
    Camera(); // Constructor

    double getLinePosition(); // Get position of line from camera. -1 to 1

    bool isLineVisible();

private:
    
};

#endif // End of header guard