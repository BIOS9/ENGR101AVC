#ifndef CAMERA_H // Header guard
#define CAMERA_H 

#define IMAGE_WIDTH 320
#define IMAGE_HEIGHT 240

class Camera {
public:
    Camera(); // Constructor
    ~Camera(); // Destructor
    int GetLineError(); // Get line error. Negative error means line is left of centre, positive means right of centre

    bool IsLineVisible();

private:
    
};

#endif // End of header guard