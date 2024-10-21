#include "Body.h"
#include "ShapeDraw.h"

float boxAngle = 0.0;
bool boxPos = true;

// 347
void batteryBox() {
	//Battery box (behind)
	glPushMatrix();
	glTranslatef(0.1, 0.1, -0.12);
	glColor3f(0.149, 0.38, 0.612);
	ShapeDraw::drawCuboid(GL_QUADS, 0.8, 0.8, 0.1);
	glPopMatrix();

	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	//Line for battery box (behind)
	glPushMatrix();
	glTranslatef(0.1, 0.1, -0.12);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.8, 0.8, 0.1);
	glPopMatrix();

	//Line for battery circles (4)
	glPushMatrix();
	glTranslatef(0.15, 0.15, -0.13);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.1, 0.1, 0.05, 0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.65, 0.15, -0.13);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.1, 0.1, 0.05, 0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15, 0.65, -0.13);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.1, 0.1, 0.05, 0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.65, 0.65, -0.13);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.1, 0.1, 0.05, 0.05);
	glPopMatrix();
}

void battery() {
	
	glPushMatrix();
	glTranslatef(0.5, 0.2, 0.1);
	glRotatef(90, 0.0, 1.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glColor3f(0.941, 0.557, 0.035);
	ShapeDraw::drawCylinder(GLU_FILL, 0.2, 0.2, 0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.45, 0.7, -0.05);
	glColor3f(0.98, 0.722, 0.365);
	ShapeDraw::drawCuboid(GL_QUADS, 0.1, 0.1, 0.1);
	glPopMatrix();
}

void Body::upperBody(bool boxOpen)
{
	//Main upper body
	glColor3f(0.565, 0.565, 0.753);
	ShapeDraw::drawCuboid(GL_QUADS, 1.0, 1.0, 1.0);

	//Waist
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	glColor3f(0.565, 0.565, 0.753);
	ShapeDraw::drawPyramid(TRUE, 1.0);
	glPopMatrix();

	// Left shoulder
	glPushMatrix();
	glTranslatef(1.0, 0.5, 0.2);
	glColor3f(0.565, 0.565, 0.753);
	ShapeDraw::drawCuboid(GL_QUADS, 0.4, 0.5, 0.5);
	glPopMatrix();

	//Right shoulder
	glPushMatrix();
	glTranslatef(-0.4, 0.5, 0.2);
	glColor3f(0.565, 0.565, 0.753);
	ShapeDraw::drawCuboid(GL_QUADS, 0.4, 0.5, 0.5);
	glPopMatrix();

	//Front box 1
	glPushMatrix();
	glTranslatef(0.1, 0.0, 1.0);
	glColor3f(0.333, 0.333, 0.333);
	ShapeDraw::drawCuboid(GL_QUADS, 0.8, 0.8, 0.1);
	glPopMatrix();

	//Front box 2
	glPushMatrix();
	glTranslatef(0.15, 0.0, 1.1);
	glColor3f(0.384, 0.365, 0.365);
	ShapeDraw::drawCuboid(GL_QUADS, 0.7, 0.7, 0.1);
	glPopMatrix();

	//Front box 3
	glPushMatrix();
	glTranslatef(0.2, 0.0, 1.2);
	glColor3f(0.596, 0.506, 0.482);
	ShapeDraw::drawCuboid(GL_QUADS, 0.6, 0.6, 0.1);
	glPopMatrix();

	//Front circle on body (Left & Right)
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 1.01);
	glColor3f(0.792, 1, 0.671);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.9, 0.9, 0.1, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 0.0, 1.01);
	glColor3f(0.792, 1, 0.671);
	ShapeDraw::drawCircle(GL_TRIANGLE_FAN, 0.9, 0.9, 0.1, 0.1);
	glPopMatrix();

	//Pyramid on front box 3
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.2, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.3, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.4, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.5, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.6, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.7, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.2, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.3, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.4, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.5, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.6, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.7, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.2, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();


	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.3, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.4, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.5, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.6, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.7, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.2, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.3, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.4, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.5, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.6, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.7, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);

	//Line for main upper body
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 1.0, 1.0, 1.0);

	//Line for waist
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 1.0);
	glPopMatrix();


	//Line for Left shoulder
	glPushMatrix();
	glTranslatef(1.0, 0.5, 0.2);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.4, 0.5, 0.5);
	glPopMatrix();

	//Line for Right shoulder
	glPushMatrix();
	glTranslatef(-0.4, 0.5, 0.2);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.4, 0.5, 0.5);
	glPopMatrix();

	//Line for Front Box 1
	glPushMatrix();
	glTranslatef(0.1, 0.0, 1.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.8, 0.8, 0.1);
	glPopMatrix();

	//Line for Front Box 2
	glPushMatrix();
	glTranslatef(0.15, 0.0, 1.1);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.7, 0.7, 0.1);
	glPopMatrix();

	//Line for Front Box 3
	glPushMatrix();
	glTranslatef(0.2, 0.0, 1.2);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.6, 0.6, 0.1);
	glPopMatrix();

	//Line for front circle
	glPushMatrix();
	glTranslatef(-0.2, 0.0, 1.01);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.9, 0.9, 0.1, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.6, 0.0, 1.01);
	ShapeDraw::drawCircle(GL_LINE_LOOP, 0.9, 0.9, 0.1, 0.1);
	glPopMatrix();

	//Line for front box 3 pyramid
	glPushMatrix();
	glTranslatef(0.2, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.1, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.2, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.3, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.7, 0.4, 1.31);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	if (boxAngle > 90)
		boxPos = false;
	else if (boxAngle < 0.0)
		boxPos = true;
	if (boxOpen && boxPos) {
		boxAngle += 1.0;
	}
	else if (!boxOpen && !boxPos) {
		boxAngle -= 1.0;
	}

	glPushMatrix();
	glTranslatef(0.1, 0.1, -0.01);
	glRotatef(boxAngle, 0.0, 1.0, 0.0);
	glTranslatef(-0.1, -0.1, 0.01);
	batteryBox();
	glPopMatrix();

	glPushMatrix();
	battery();
	glPopMatrix();
	
}

void Body::lowerBody()
{
	//Dress
	glColor3f(0.227, 0.486, 0.647);
	glPushMatrix();
	glTranslatef(0.5, -0.3, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCone(GLU_FILL, 1.0, 1.0, 10, 30);
	glPopMatrix();

	//Deco on dress
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.2, -1.0, 1.0);
	ShapeDraw::drawSphere(GL_FILL, 0.1, 30, 30);
	glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.8, -1.0, 1.0);
	ShapeDraw::drawSphere(GL_FILL, 0.1, 30, 30);
	glPopMatrix();

	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.8, -1.0, 0.0);
	ShapeDraw::drawSphere(GL_FILL, 0.1, 30, 30);
	glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.2, -1.0, 0.0);
	ShapeDraw::drawSphere(GL_FILL, 0.1, 30, 30);
	glPopMatrix();
}
