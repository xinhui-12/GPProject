#include "Bridge.h"
#include "ShapeDraw.h"
#include "Texture.h"

float openAngle = 0;
Texture textureBridge;

//55
static void tower() {
	GLuint texT;

	glColor3f(0.8, 0.8, 0.8);
	texT = textureBridge.loadTexture("stone.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 1.0, 0.5, 1.0);
	glDeleteTextures(1, &texT);

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.2, 0.5, 0.2);
	texT = textureBridge.loadTexture("towerWindow.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.55, 0.3, 0.1);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.5, 0.65);
	texT = textureBridge.loadTexture("towerWindow.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.55, 0.3, 0.1);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.2, 0.8, 0.2);
	texT = textureBridge.loadTexture("tower.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.55, 0.8, 0.55);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.18, 0.8, 0.18);
	texT = textureBridge.loadTexture("towerBrick.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.6, 0.1, 0.6);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.18, 1.2, 0.18);
	texT = textureBridge.loadTexture("towerBrick.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.6, 0.1, 0.6);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.18, 1.6, 0.18);
	glColor3f(1.0, 1.0, 1.0);
	texT = textureBridge.loadTexture("clock.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 0.6, 0.4, 0.6);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.21, 2.0, 0.21);
	glColor3f(0.7, 0.7, 0.6);
	texT = textureBridge.loadTexture("oldBrick.bmp");
	ShapeDraw::drawPyramid(true, 0.55);
	glDeleteTextures(1, &texT);
	glPopMatrix();

	float duplX = 0.23, duplZ = 0.28;
	for (int i = 1; i <= 2; i++) {
		duplZ = 0.23;
		for (int j = 1; j <= 2; j++) {
			glPushMatrix();
			glTranslatef(duplX, 2.15, duplZ);
			glRotatef(90, 1.0, 0.0, 0.0);
			glColor3f(0.6, 0.6, 0.5);
			texT = textureBridge.loadTexture("oldBrick.bmp");
			ShapeDraw::drawCylinder(GLU_FILL, 0.05, 0.05, 0.2, 30, 30);
			glDeleteTextures(1, &texT);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(duplX, 2.55, duplZ);
			glRotatef(90, 1.0, 0.0, 0.0);
			glColor3f(0.8, 0.8, 0.7);
			texT = textureBridge.loadTexture("oldBrick.bmp");
			ShapeDraw::drawCone(GLU_FILL, 0.05, 0.4, 30, 30);
			glDeleteTextures(1, &texT);
			glPopMatrix();
			duplZ += 0.5;
		}
		duplX += 0.5;
	}
}

//6
static void middlePart() {
	GLuint texB;
	glPushMatrix();
	glColor3f(0.9, 0.9, 0.9);
	texB = textureBridge.loadTexture("stone.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 1.5, 0.1, 1.0);
	glDeleteTextures(1, &texB);
	glPopMatrix();

}

//10
static void string() {
	glLineWidth(5.0f);
	glColor3f(0.55, 0.55, 0.5);
	glBegin(GL_LINES);
	glVertex3f(-1.6, 1.7, 0.3);
	glVertex3f(-4.0, 0.5, 0.0);
	glEnd();

	glLineWidth(2.0f);
	glColor3f(0.55, 0.55, 0.5);
	glBegin(GL_LINES);
	glVertex3f(-2.0, 1.51, 0.25);
	glVertex3f(-2.0, 0.5, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.4, 1.31, 0.2);
	glVertex3f(-2.4, 0.5, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.8, 1.11, 0.15);
	glVertex3f(-2.8, 0.5, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-3.2, 0.92, 0.1);
	glVertex3f(-3.2, 0.5, 0.0);
	glEnd();

	glLineWidth(5.0f);
	glColor3f(0.55, 0.55, 0.5);
	glBegin(GL_LINES);
	glVertex3f(-1.6, 1.7, 0.7);
	glVertex3f(-4.0, 0.5, 1.0);
	glEnd();

	glLineWidth(2.0f);
	glColor3f(0.55, 0.55, 0.5);
	glBegin(GL_LINES);
	glVertex3f(-2.0, 1.51, 0.75);
	glVertex3f(-2.0, 0.5, 1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.4, 1.31, 0.8);
	glVertex3f(-2.4, 0.5, 1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-2.8, 1.11, 0.85);
	glVertex3f(-2.8, 0.5, 1.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-3.2, 0.92, 0.9);
	glVertex3f(-3.2, 0.5, 1.0);
	glEnd();
}

//154
void Bridge::drawBridge(bool isOpen) {
	GLuint texA;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glScalef(1.5, 1.5, 1.5);

	glPushMatrix();
	glTranslatef(-2.0, 0.0, 0.0);
	tower();
	glPopMatrix();
	
	glPushMatrix();
	string();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0, 0.4, 0.0);
	glColor3f(0.9, 0.9, 0.9);
	texA = textureBridge.loadTexture("stone.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 2.0, 0.1, 1.0);
	glDeleteTextures(1, &texA);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.0, 0.0);
	tower();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, 1.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	string();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0, 0.4, 0.0);
	glColor3f(0.9, 0.9, 0.9);
	texA = textureBridge.loadTexture("stone.bmp");
	ShapeDraw::drawCuboid(GL_QUADS, 2.0, 0.1, 1.0);
	glDeleteTextures(1, &texA);
	glPopMatrix();

	if (isOpen) {
		if (openAngle < 70) {
			openAngle += 0.5;
		}
		else {
			openAngle = 70;
		}
	}
	else {
		if (openAngle > 0) {
			openAngle -= 0.5;
		}
		else {
			openAngle = 0;
		}
	}
	glPushMatrix();
	glTranslatef(-1.0, 0.4, 0.0);
	glRotatef(openAngle, 0, 0, 1);
	middlePart();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.5, 0.0);
	glRotatef(-openAngle, 0, 0, 1);
	glRotatef(180, 0, 0, 1);
	middlePart();
	glPopMatrix();

	glPopMatrix();
}