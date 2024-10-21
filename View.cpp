#include "View.h"

void View::viewing(float cameraDistance, float cameraAngleY) {
    glTranslatef(0, 0, cameraDistance);
    glTranslatef(0, -2.0, 5.5);
    glRotatef(cameraAngleY, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
}

void View::projection(bool isOrtho, float tx, float ty)
{
    glMatrixMode(GL_PROJECTION);		//refer to the projection matrix
    glLoadIdentity();					//reset the projection matrix
    
    if (isOrtho) {
        //Orthographic view
        glOrtho(-8.0, 8.0, -10.0, 10.0, -8.0, 8.0);
        glTranslatef(tx, ty, 0);
    }
    else {
        //Perspective view
        gluPerspective(90.0, 1.0, 0.01, 17.0);
        glTranslatef(tx, ty, 0);
        glTranslatef(0.0, 2.0, -2.5);
    }
}
