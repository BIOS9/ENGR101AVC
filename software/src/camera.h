#ifndef CAMERA_H // Header guard
#define CAMERA_H 

#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 240
#define MIN_BLACK_COLOR = 150; // Maximum value for black before pixel is counted as missing/white
#define LINE_MISSING_THRESHOLD = 30; // Requires 20 black pixels below MIN_BLACK_COLOR otherwise line is considered missing

//#define DISPLAY_IMAGE // Uncomment this value to display the camera feed on screen

class Camera {
public:
    Camera(); // Constructor
    ~Camera(); // Destructor
    int GetLineError(); // Get line error. Negative error means line is left of centre, positive means right of centre

    bool IsLineVisible(); // Checks if the line is visible after calling GetLineError

private:
    bool lineVisible = false;
};

#endif // End of header guard