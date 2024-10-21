#include "Hand.h"
#include "ShapeDraw.h"

// 66

void upperArm() {
	//Upper arm
	glPushMatrix();
	glTranslatef(-0.4, 2.2, -0.45);
	glColor3f(0.565, 0.565, 0.753);
	ShapeDraw::drawCuboid(GL_QUADS, 0.8, 0.9, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 2.2, -0.45);
	glColor3f(0.0, 0.0, 0.0);
	ShapeDraw::drawCuboid(GL_LINE_STRIP, 0.8, 0.9, 1.0);
	glPopMatrix();

	glPushMatrix();			//Push: Upper arm
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.31, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.3, 0.4, 2.0, 30, 30);
	glPopMatrix();			//Pop: Upper arm
}

void lowerArm() {
	//Lower arm
	glPushMatrix();															//Push: Lower arm
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.2, 0.3, 2.0, 30, 30);
	glPopMatrix();															//Pop: Lower arm
}

void weapon() {

	glPushMatrix();
	glColor3f(0.596, 0.686, 0.78);
	ShapeDraw::drawCuboid(GL_QUADS, 0.5, 4.0, 0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.596, 0.686, 0.78);
	glTranslatef(0.0, 0.0, 0.5);
	glRotatef(180, 1.0, 0.0, 0.0);
	ShapeDraw::drawPyramid(TRUE, 0.5);
	glPopMatrix();

}

void finger(float rotate) {
	glPushMatrix();		// first
	glRotatef(rotate, 1.0, 0.0, 0.0);

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.5, 0.5, 0.54, 30, 30);
	glPopMatrix();

	

	glPushMatrix();		// second
	glRotatef(rotate, 1.0, 0.0, 0.0);

	//Joint 1 --> Finger
	glPushMatrix();
	glColor3f(0.231, 0.267, 0.294);
	glTranslatef(0.0, 0.006, 0.0);
	ShapeDraw::drawSphere(GLU_FILL, 0.48, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(0.0, 0.7, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.5, 0.5, 0.54, 30, 30);
	glPopMatrix();

	

	glPushMatrix();		// third
	glRotatef(rotate, 1.0, 0.0, 0.0);

	//Joint 2 --> Finger
	glPushMatrix();
	glColor3f(0.231, 0.267, 0.294);
	glTranslatef(0.0, 0.8, 0.0);
	ShapeDraw::drawSphere(GLU_FILL, 0.48, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(0.0, 1.4, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.5, 0.5, 0.52, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.804, 0.498, 0.196);
	glTranslatef(0.0, 1.9, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCone(GLU_FILL, 0.5, 0.52, 30, 30);
	glPopMatrix();

	glPopMatrix();		// third
	glPopMatrix();		// second
	glPopMatrix();		// first
}

void palm() {
	//palm
	glPushMatrix();
	glColor3f(0.231, 0.267, 0.294);
	ShapeDraw::drawSphere(GLU_FILL, 0.5, 30, 30);
	glPopMatrix();

	//Deco
	glPushMatrix();
	glColor3f(0.698, 0.745, 0.71);
	glTranslatef(0.0, 0.0, -0.3);
	ShapeDraw::drawSphere(GLU_FILL, 0.3, 30, 30);
	glPopMatrix();

}

void wrist(float rotateFinger, float firstTranslate, float secondTranslate, float thirdTranslate) {

	//-----Palm----//
	glPushMatrix();
	palm();
	glPopMatrix();

	//glPushMatrix();			// rotate finger
	//glRotatef(rotateFinger, 1.0, 0.0, 0.0);

	glPushMatrix();			// shoot out first
	glTranslatef(0.0, firstTranslate, 0.0);

	//-----Middle Finger----//
	glPushMatrix();
	glTranslatef(0.0, 0.6, 0.0);
	glScalef(0.2, 0.3, 0.2);
	finger(rotateFinger);
	glPopMatrix();

	glPopMatrix();			// shoot out first

	glPushMatrix();			// shoot out second
	glTranslatef(0.0, secondTranslate, 0.0);
	if (firstTranslate == 50) {
		glTranslatef(-0.3, 0.2, 0.0);
	}

	//-----Index Finger----//
	glPushMatrix();
	glTranslatef(0.3, 0.4, 0.0);
	glScalef(0.2, 0.3, 0.2);
	finger(rotateFinger);
	glPopMatrix();

	glPopMatrix();			// shoot out second

	glPushMatrix();			// shoot out third
	glTranslatef(0.0, thirdTranslate, 0.0);
	if (secondTranslate == 50) {
		glTranslatef(0.3, 0.2, 0.0);
	}

	//-----Ring Finger----//
	glPushMatrix();
	glTranslatef(-0.3, 0.4, 0.0);
	glScalef(0.2, 0.3, 0.2);
	finger(rotateFinger);
	glPopMatrix();

	glPopMatrix();			// shoot out thrid

	//glPopMatrix();			// rotate finger
}

void Hand::drawHand(bool isWeapon, float walkHandRotate, float rotateUpperArm, float rotateLowerArm, float rotateWrist, float rotateFinger, float firstTranslate, float secondTranslate, float thirdTranslate, float fightRotate) {

	glPushMatrix();	// walk hand rotate
	glTranslatef(0.0, 2.7, 0.0);
	glRotatef(walkHandRotate, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -2.7, 0.0);

	glPushMatrix();	// rotate upper arm
	glTranslatef(0.0, 2.7, 0.0);
	glRotatef(fightRotate, 0.0, 1.0, 0.0);
	glRotatef(rotateUpperArm, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -2.7, 0.0);

	//------ARM------//
	upperArm();

	glPushMatrix();	// rotate lower arm
	glTranslatef(0.0, 0.2, 0.0);
	glRotatef(rotateLowerArm, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.2, 0.0);

	//Joint --> Arm
	glPushMatrix();
	glColor3f(0.231, 0.267, 0.294);
	glTranslatef(0.0, 0.2, 0.0);
	ShapeDraw::drawSphere(GLU_FILL, 0.3, 30, 30);
	glPopMatrix();

	lowerArm();

	//------WRIST------//

	//-----Armor for wrist-----//
	glPushMatrix();
	glColor3f(0.231, 0.267, 0.294);
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_FILL, 0.3, 0.2, 0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glLineWidth(3.0);
	glColor3f(1, 0.749, 0);
	glTranslatef(0.0, -1.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	ShapeDraw::drawCylinder(GLU_SILHOUETTE, 0.32, 0.22, 0.4, 10, 10);
	glPopMatrix();

	glPushMatrix();	// rotate wrist
	glTranslatef(0.0, 0.2, 0.0);
	glRotatef(rotateWrist, 0.0, 1.0, 0.0);
	glTranslatef(0.0, -0.2, 0.0);

	if (isWeapon) {
		//----Palm----//
		glPushMatrix();
		glTranslatef(0.0, -2.0, 0.0);
		glRotatef(180, 0.0, 1.0, 0.0);
		palm();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1, -4.0, -0.05);
		glScalef(0.5, 0.5, 0.3);
		weapon();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(0.0, -2.0, 0.0);
		glRotatef(-180, 1.0, 0.0, 0.0);
		wrist(rotateFinger, firstTranslate, secondTranslate, thirdTranslate);
		glPopMatrix();
		
	}
	glPopMatrix();	// rotate wrist

	glPopMatrix();	// rotate lower arm

	glPopMatrix();	// rotate upper arm

	glPopMatrix();	// walk hand rotate
}