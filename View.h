
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

class View
{
public:

    // cameraAngleY is the angle rotate on Y axis
    static void viewing(float cameraDistance, float cameraAngleY);

    // tx and ty is the camera moving in x and y axis
    // ry is the camera rotate in y axis
    static void projection(bool isOrtho, float tx, float ty);

};

