#include "Head.h"
#include "ShapeDraw.h"

void drawHalfBottomCircle(GLenum primitive, float centreX, float centreY, float xRadius, float yRadius) {
	float PI = 3.1429;
	glBegin(primitive);
	for (float angle = PI; angle <= 2 * PI; angle += (2 * PI) / 360)
	{
		float x2 = centreX + xRadius * cos(angle);
		float y2 = centreY + yRadius * sin(angle);
		glVertex2f(x2, y2);
	}
	glEnd();
}

float hatTrans = 0.1;
bool hatPositive = true;

// 30

void Head::drawHead(float rotateHeadX, float rotateHeadY) {
	glLineWidth(2.0);

	glPushMatrix();		// Rotate Head
	glRotatef(rotateHeadY, 0.0, 1.0, 0.0);
	glRotatef(rotateHeadX, 1.0, 0.0, 0.0);

	//-----Main Head-----//
	glPushMatrix();
	glColor3f(1, 0.98, 0.898);
	glTranslatef(-1.5, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_QUADS, 3.0, 2.0, 2.0);
	glPopMatrix();

	//-----Main Head: Boder Line-----//
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.5, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 3.0, 2.0, 2.0);
	glPopMatrix();

	//-----Neck to top of the head: Cylinder-----//
	glPushMatrix();
	glColor3f(1, 0.98, 0.898);
	glTranslatef(0.0, -0.7, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.7, 0.5, 3.0, 30, 30);
	glPopMatrix();

	//-----Top of the head: Cylinder --> Line-----//
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.3, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_LINE, 0.7, 0.5, 2.0, 20, 10);
	glPopMatrix();

	//-----Top of the head: Sphere-----//
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.1, 1.0);
	ShapeDraw::drawSphere(GLU_FILL, 0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();		// translate the hat
	if (hatTrans > 0.5)
		hatPositive = false;
	else if (hatTrans < 0.0)
		hatPositive = true;
	if (hatPositive)
		hatTrans += 0.01;
	else
		hatTrans -= 0.01;
	glTranslatef(0.0, hatTrans, 0.0);

	//-----Top of the head: Disk 1-----//
	glPushMatrix();
	glColor3f(0.451, 0.761, 0.984);
	glTranslatef(0.0, 2.5, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawDisk(GLU_FILL, 0.5, 1.0);
	glPopMatrix();

	//-----Top of the head: Disk 2-----//
	glPushMatrix();
	glColor3f(0.451, 0.761, 0.984);
	glTranslatef(0.0, 3.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawDisk(GLU_FILL, 0.3, 0.8);
	glPopMatrix();

	//-----Hat-----// 
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 3.2, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawDisk(GLU_FILL, 0.6, 1.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 3.2, 1.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.6, 0.6, 0.55, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 3.7, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawDisk(GLU_FILL, 0.0, 0.6);
	glPopMatrix();

	glPopMatrix();		// translate the hat

	//-----Right Ear-----// 
	glPushMatrix();
	glColor3f(0.973, 0.863, 0.459);
	glTranslatef(1.51, 1.5, 0.5);
	glRotatef(-90, 0.0, 0.0, 1.0);
	ShapeDraw::drawPyramid(TRUE, 1.0);
	glPopMatrix();

	//-----Right Ear: Boder Line-----//
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.51, 1.5, 0.5);
	glRotatef(-90, 0.0, 0.0, 1.0);
	ShapeDraw::drawPyramid(FALSE, 1.0);
	glPopMatrix();

	//-----Left Ear-----//
	glPushMatrix();
	glColor3f(0.973, 0.863, 0.459);
	glTranslatef(-1.51, 0.5, 0.5);
	glRotatef(90, 0.0, 0.0, 1.0);
	ShapeDraw::drawPyramid(TRUE, 1.0);
	glPopMatrix();

	//-----Left Ear: Boder Line-----//
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.51, 0.5, 0.5);
	glRotatef(90, 0.0, 0.0, 1.0);
	ShapeDraw::drawPyramid(FALSE, 1.0);
	glPopMatrix();

	//-----Eye Mask-----//
	glPushMatrix();
	glBegin(GL_QUADS);
	glColor4f(0.51, 0.933, 0.992, 0.212);
	glVertex3f(-1.3, 1.5, 2.01);
	glVertex3f(1.3, 1.5, 2.01);
	glVertex3f(1.3, 0.5, 2.01);
	glVertex3f(-1.3, 0.5, 2.01);
	glEnd();
	glPopMatrix();

	//-----Eye Mask: Left Curve-----//
	glPushMatrix();
	glColor4f(0.51, 0.933, 0.992, 0.212);
	glTranslatef(-1.3, 1.0, 2.01);
	glRotatef(-90, 0.0, 0.0, 1.0);
	drawHalfBottomCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.5, 0.2);
	glPopMatrix();

	//-----Eye Mask: Right Curve-----//
	glPushMatrix();
	glColor4f(0.51, 0.933, 0.992, 0.212);
	glTranslatef(1.3, 1.0, 2.01);
	glRotatef(90, 0.0, 0.0, 1.0);
	drawHalfBottomCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.5, 0.2);
	glPopMatrix();

	//-----Right Eye-----//
	glPushMatrix();
	glColor3f(0.024, 0.231, 0);
	glTranslatef(1.0, 1.0, 2.02);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.3);
	glPopMatrix();

	//-----Right Eye: Inner 1-----//
	glPushMatrix();
	glColor3f(0.792, 1, 0.671);
	glTranslatef(1.0, 1.0, 2.03);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.1, 0.2);
	glPopMatrix();

	//-----Right Eye: Inner 2-----//
	glPushMatrix();
	glColor3f(0.812, 1, 0.016);
	glTranslatef(1.0, 1.0, 2.04);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.05, 0.15);
	glPopMatrix();

	//-----Right Eye: Highlight-----//
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.05, 1.2, 2.04);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.07, 0.07);
	glPopMatrix();

	//-----Left Eye-----//
	glPushMatrix();
	glColor3f(0.024, 0.231, 0);
	glTranslatef(-1.0, 1.0, 2.02);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.3);
	glPopMatrix();

	//-----Left Eye: Inner 1-----//
	glPushMatrix();
	glColor3f(0.792, 1, 0.671);
	glTranslatef(-1.0, 1.0, 2.03);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.1, 0.2);
	glPopMatrix();

	//-----Left Eye: Inner 2-----//
	glPushMatrix();
	glColor3f(0.812, 1, 0.016);
	glTranslatef(-1.0, 1.0, 2.04);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.05, 0.15);
	glPopMatrix();

	//-----Left Eye: Highlight-----//
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.05, 1.2, 2.04);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.07, 0.07);
	glPopMatrix();

	//-----Screw 1 (behind the head)-----// 
	glPushMatrix();
	glColor3f(0.663, 0.663, 0.663);
	glTranslatef(1.2, 1.7, -0.01);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.2);
	glPopMatrix();

	//Horizontal Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.0, 1.7, -0.011);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//Vertical Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.2, 1.5, -0.011);
	glRotatef(90, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//-----Screw 2 (behind the head)-----//
	glPushMatrix();
	glColor3f(0.663, 0.663, 0.663);
	glTranslatef(-1.2, 1.7, -0.01);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.2);
	glPopMatrix();

	//Horizontal Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.4, 1.7, -0.011);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//Vertical Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.2, 1.5, -0.011);
	glRotatef(90, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//-----Screw 3 (behind the head)-----// 
	glPushMatrix();
	glColor3f(0.663, 0.663, 0.663);
	glTranslatef(-1.2, 0.25, -0.01);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.2);
	glPopMatrix();

	//Horizontal Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.4, 0.23, -0.011);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//Vertical Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-1.2, 0.03, -0.011);
	glRotatef(90, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//-----Screw 4 (behind the head)-----// 
	glPushMatrix();
	glColor3f(0.663, 0.663, 0.663);
	glTranslatef(1.2, 0.25, -0.01);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.0, 0.0, 0.2, 0.2);
	glPopMatrix();

	//Horizontal Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.0, 0.23, -0.011);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	//Vertical Line
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(1.2, 0.03, -0.011);
	glRotatef(90, 0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glEnd();
	glPopMatrix();

	glPopMatrix();		// Rotate Head
}