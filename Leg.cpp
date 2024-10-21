#include "Leg.h"
#include "ShapeDraw.h"

// 93

void upperLeg()
{
	glColor3f(0.231, 0.267, 0.294);
	glPushMatrix();
	ShapeDraw::drawSphere(GLU_FILL, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.2, 0.2, 1.5, 30, 30);
	glPopMatrix();

	//Joint
	glColor3f(0.231, 0.267, 0.294);
	glPushMatrix();
	glTranslatef(0.0, -1.5, 0.0);
	ShapeDraw::drawSphere(GLU_FILL, 0.2, 10, 10);
	glPopMatrix();
}

void lowerLeg()
{
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(-0.15, -3.2, -0.15);
	ShapeDraw::drawCuboid(GL_QUADS, 0.3, 1.5, 0.3);
	glPopMatrix();

	//Lines
	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-0.15, -3.2, -0.15);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.3, 1.5, 0.3);
	glPopMatrix();

}

void feet() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.15, -3.1, -0.15);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_QUADS, 0.3, 0.65, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(-0.15, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_QUADS, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(-0.05, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_QUADS, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(0.05, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_QUADS, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(0.05, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(-0.05, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(-0.15, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.1);
	glPopMatrix();

	// Lines
	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-0.15, -3.1, -0.15);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.3, 0.65, 0.1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.15, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.05, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.05, -3.1, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.1, 0.2, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.05, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.05, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.15, -3.1, 0.71);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(FALSE, 0.1);
	glPopMatrix();
}

void Leg::drawleg(float walkLegRotate, float rotateUpperLeg, float rotateLowerLeg, float rotateFeet)
{
	glPushMatrix(); 
	glRotatef(walkLegRotate, 1.0, 0.0, 0.0); //walk upper leg rotate
	glRotatef(rotateUpperLeg, 1.0, 0.0, 0.0);

	upperLeg();

	glPushMatrix();
	glTranslatef(0, -1.7, 0);
	glRotatef(rotateLowerLeg, 1.0, 0.0, 0.0);
	glTranslatef(0, 1.7, 0);

	lowerLeg();

	glPushMatrix();
	glTranslatef(-0.15, -3.2, -0.15);
	glRotatef(rotateFeet, 1.0, 0.0, 0.0);
	glTranslatef(0.15, 3.2, 0.15);

	feet();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}


