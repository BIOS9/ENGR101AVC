#include "camera.h" 
#include "logger.h"

/**
 * Constructor for camera class
 */
Camera::Camera() {
    logMsg("Camera starting up...", "Camera", DEBUG);

    int err = init(); // Initialise the E101 library
    if(err != 0) {
        logMsg("Failed to initialise camera!", "Camera", ERROR);
        exit(err); // An error occured, exit the program
    }

    logMsg("Camera started.", "Camera", DEBUG);
}

/**
 * Gets the error value for the black line from the camera.
 * 
 * Returns an integer value that is:
 * negative when the line is left of the centre,
 * zero when the line is in the centre,
 * positive when the line is right of the centre. 
 */
int Camera::GetLineError() {
    logMsg("Getting line error.", "Camera", DEBUG);

    take_picture();

    int middleY = IMAGE_HEIGHT/2; // Get vertical centre of the image
    
    // Variables to hold the max and minimum brightness of the pixels in the centre of the image
    int maxBright = -1;
    int minBright = 256;

    // Find max and min brightness values in the vertical centre of the image
    for(int i = 0; i < IMAGE_WIDTH; ++i) {
        int pixel = get_pixel(middleY, i, 3);
        
        if(pixel > maxBright) 
            maxBright = pixel;

        if(pixel < minBright)
            minBright = pixel;
    }

    // Threshold value is halfway between the max and min brightness values.
    int brightThreshold = minBright + (maxBright - minBright) / 2;
    logMsg("Brightness threshold set at: %d", "Camera", DEBUG, brightThreshold);


}