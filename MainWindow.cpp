
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <windowsx.h>
#include "View.h"
#include "Texture.h"
#include "Bridge.h"
#include "Background.h"
#include "Body.h"
#include "Leg.h"
#include "Head.h"
#include "Hand.h"
#include "ShapeDraw.h"

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "Robot"
float rotateSpeed = 3.0;

// Projection
View* view;
bool isOrtho = false;
int xPos = 0, yPos = 0, zPos = 0;
float cameraAngleY = 0.0;
float cameraDistance = -6.0;
float tempZ = 0.0; // validation check of the z position
float camX = 0, camY = -1, camSpeed = 1.0;
float rotateCam = 0;

// Bridge
bool isOpen = false;

// Walking animation
float walkSpeed = 0.02;
float walkModel = 0.0;
float walkHandRotate = 0.0;
float walkUpperLegRotate = 0.0;
float walkLowerLegRotate = 0.0;
bool walkHandPositive = true, walkUpperLegPositive = true, walkLowerLegPositive = true;
bool wPress = false;
void isWalking(bool press) {
	if (press) {
		walkModel += walkSpeed;
		// check whether the hand in positive direction or not
		if (walkHandRotate > 45)
			walkHandPositive = false;
		else if (walkHandRotate < -45)
			walkHandPositive = true;
		if (walkHandPositive)
			walkHandRotate += 1.0;
		else
			walkHandRotate -= 1.0;

		// check whether the leg in positive direction or not
		if (walkUpperLegRotate > 30) {
			walkUpperLegPositive = false;
		}else if (walkUpperLegRotate < -30) {
			walkUpperLegPositive = true;
		}
			
		if (walkUpperLegPositive)
			walkUpperLegRotate += 0.67;
		else
			walkUpperLegRotate -= 0.67;
	}
}

// Head movement
float rotateHeadSpeed = 0.8;
float rotateHeadX = 0, rotateHeadY = 0.01;;
bool rotateHeadXPos = true, rotateHeadYPos = true, yStop = false;
bool nodHead = false, shakeHead = false;
void headMovement(bool nodHead, bool shakeHead) {
	// Nod head
	if (rotateHeadX > 15) {
		rotateHeadXPos = false;
	}
	else if (rotateHeadX < 0) {
		rotateHeadXPos = true;
		nodHead = false;
	}
	if (nodHead) {
		if (rotateHeadXPos) {
			rotateHeadX += rotateHeadSpeed;
		}
		else {
			rotateHeadX -= rotateHeadSpeed;
		}
	}

	// shake head
	if (rotateHeadY > 45) {
		rotateHeadYPos = false;
	}
	else if (rotateHeadY < -45) {
		rotateHeadYPos = true;
		yStop = true;
	}
	if (rotateHeadY >= 0.0 && yStop) {
		shakeHead = false;
	}
	if (shakeHead) {
		if (rotateHeadYPos) {
			rotateHeadY += rotateHeadSpeed;
		}
		else {
			rotateHeadY -= rotateHeadSpeed;
		}
	}
}

// Hand movement
bool isHand = true;
bool isWeapon = false;
float rotateLeftUpperArm = 0.0, rotateLeftLowerArm = 0.0, rotateLeftWrist = 0.0, rotateLeftFinger = 0.0;
float rotateRightUpperArm = 0.0, rotateRightLowerArm = 0.0, rotateRightWrist = 0.0, rotateRightFinger = 0.0;
bool readyL = false, readyR = false;
void ready(bool readyL, bool readyR) {
	if (readyL) {
		rotateLeftWrist += 5;
	}
	if (readyR) {
		rotateRightWrist += 5;
	}
}
int numLeftShoot = 0, numRightShoot = 0;
float firstLeftTranslate = 0.0, secondLeftTranslate = 0.0, thirdLeftTranslate = 0.0;
float firstRightTranslate = 0.0, secondRightTranslate = 0.0, thirdRightTranslate = 0.0;
void shoot(int numLeftShoot, int numRightShoot) {
	if (numLeftShoot == 1) {
		if (firstLeftTranslate < 50) {
			firstLeftTranslate += 1.0;
		}
		else {
			firstLeftTranslate = 50;
		}
	}
	else if (numLeftShoot == 2) {
		if (secondLeftTranslate < 50) {
			secondLeftTranslate += 1.0;
		}
		else {
			secondLeftTranslate = 50;
		}
	}
	else if (numLeftShoot == 3) {
		if (thirdLeftTranslate < 50) {
			thirdLeftTranslate += 1.0;
		}
		else {
			thirdLeftTranslate = 50;
		}
	}
	else {
		firstLeftTranslate = 0;
		secondLeftTranslate = 0;
		thirdLeftTranslate = 0;
	}

	if (numRightShoot == 1) {
		if (firstRightTranslate < 50) {
			firstRightTranslate += 1.0;
		}
		else {
			firstRightTranslate = 50;
		}
	}
	else if (numRightShoot == 2) {
		if (secondRightTranslate < 50) {
			secondRightTranslate += 1.0;
		}
		else {
			secondRightTranslate = 50;
		}
	}
	else if (numRightShoot == 3) {
		if (thirdRightTranslate < 50) {
			thirdRightTranslate += 1.0;
		}
		else {
			thirdRightTranslate = 50;
		}
	}
	else {
		firstRightTranslate = 0;
		secondRightTranslate = 0;
		thirdRightTranslate = 0;
	}
}

// Leg movement
float rotateLeftUpperLeg = 0.0, rotateLeftLowerLeg = 0.0, rotateLeftFeet = 0.0;
float rotateRightUpperLeg = 0.0, rotateRightLowerLeg = 0.0, rotateRightFeet = 0.0;

// Body
bool boxOpen = false;

// Fighting animation
bool rightFight = false, leftFight = false;
bool rightStop = false, leftStop = false;
float rightWeaponRotate = 0.0, leftWeaponRotate = 0.0;
float rotateWeaponSpeed = 3.0;
void fighting(bool rightFight, bool leftFight) {
	if (rightFight && !rightStop) {
		if (rightWeaponRotate < 45) {
			rightWeaponRotate += rotateWeaponSpeed;
		}
		else {
			rightWeaponRotate = 0.0;
			rotateRightUpperArm = 0.0;
			rightStop = true;
		}
	}
	if (leftFight && !leftStop) {
		if (leftWeaponRotate > -45) {
			leftWeaponRotate -= rotateWeaponSpeed;
		}
		else {
			leftWeaponRotate = 0.0;
			rotateLeftUpperArm = 0.0;
			leftStop = true;
		}
	}
}

// Texture
int noOfTexture = 0;

// Lighting
bool lightOn = false, lightPositionBinding = true;
float lightX = 2.0, lightY = 2.0, lightZ = 1.0;
float lightColorR = 1.0, lightColorG = 1.0, lightColorB = 1.0;

//----------------------------------------------------------------------------

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_MOUSEMOVE:
		// Rotate the model
		if (wParam == MK_LBUTTON)
		{
			cameraAngleY += (LOWORD(lParam) - xPos);
			xPos = LOWORD(lParam);
		}
		break;
	case WM_MOUSEWHEEL:				// Zoom in (Scroll backward), Zoom out (scroll forward)
		tempZ = (short)HIWORD(wParam) / 300.0f;
		if (tempZ < 0 && cameraDistance < -4.0) {
			cameraDistance -= tempZ;
			zPos = HIWORD(lParam);
		}
		else if (tempZ > 0 && cameraDistance > -7) {
			cameraDistance -= tempZ;
			zPos = HIWORD(lParam);
		}
		break;

	case WM_LBUTTONDOWN:
		xPos = LOWORD(lParam);
		break;

	case WM_LBUTTONUP:
		xPos = LOWORD(lParam);
		break;

	case WM_RBUTTONDOWN:
		yPos = HIWORD(lParam);
		break;

	case WM_RBUTTONUP:
		yPos = HIWORD(lParam);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) PostQuitMessage(0);
		else if (wParam == VK_SPACE) {		// Reset all
			// Projection
			camX = 0.0;
			camY = -1.0;
			cameraAngleY = 0.0;
			if (isOrtho) {
				cameraDistance = 0.0;
			}
			else {
				cameraDistance = -6.0;
			}
			rotateCam = 0.0;

			// Walking animation
			walkModel = 0.0;
			walkHandRotate = 0.0;
			walkUpperLegRotate = 0.0;

			// Hand movement
			isWeapon = false;
			rotateLeftUpperArm = 0.0;
			rotateLeftLowerArm = 0.0;
			rotateLeftWrist = 0.0;
			rotateLeftFinger = 0.0;
			rotateRightUpperArm = 0.0;
			rotateRightLowerArm = 0.0;
			rotateRightWrist = 0.0;
			rotateRightFinger = 0.0;
			readyL = false;
			readyR = false;
			numLeftShoot = 0;
			numRightShoot = 0;

			// Leg movement
			rotateLeftUpperLeg = 0.0;
			rotateLeftLowerLeg = 0.0;
			rotateLeftFeet = 0.0;
			rotateRightUpperLeg = 0.0;
			rotateRightLowerLeg = 0.0;
			rotateRightFeet = 0.0;

			// Texture
			noOfTexture = 0;

			// Lighting
			lightX = 2.0;
			lightY = 2.0;
			lightZ = 1.0;
			lightColorR = 1.0;
			lightColorG = 1.0;
			lightColorB = 1.0;
		}

		else if (wParam == 'O') {			// Orthographic projection
			isOrtho = true;
			camX = 0.0;
			camY = 0.0;
			cameraAngleY = 0.0;
			cameraDistance = 0.0;
			rotateCam = 0.0;
		}
		else if (wParam == 'P') {			// Perspective projection
			isOrtho = false;
			camX = 0.0;
			camY = -1.0;
			cameraAngleY = 0.0;
			cameraDistance = -6.0;
			rotateCam = 0.0;
		}
		else if (wParam == VK_LEFT) {		// Translate camera to left
			if (camX >= 8)
				camX = 8;
			else
				camX += camSpeed;
		}
		else if (wParam == VK_RIGHT) {		// Translate camera to right
			if (camX <= -8)
				camX = -8;
			else
				camX -= camSpeed;
		}
		else if (wParam == VK_UP) {			// Translate camera to up
			if (camY <= -8)
				camY = -8;
			else
				camY -= camSpeed;
		}
		else if (wParam == VK_DOWN) {		// Translate camera to down
			if (camY >= 0)
				camY = 0;
			else
				camY += camSpeed;
		}
		else if (wParam == VK_OEM_COMMA) {	// Rotate camera anticlockwise
			rotateCam += rotateSpeed;
		}
		else if (wParam == VK_OEM_PERIOD) {	// Rotate camera clockwise
			rotateCam -= rotateSpeed;
		}

		else if (wParam == VK_TAB) {		// Middle of the bridge open or close
			isOpen = !isOpen;
		}

		else if (wParam == 'W') {			// walking animation
			wPress = !wPress;
		}

		else if (wParam == 0x31) {			// nod head in x-axis (num1)
			rotateHeadX = 0.01;
			nodHead = true;
		}
		else if (wParam == 0x32) {			// shake head in y-axis (num2)
			rotateHeadY = 0.0;
			rotateHeadYPos = true;
			yStop = false;
			shakeHead = true;
		}
		else if (wParam == 0x33) {			// change keybind to hand movement
			isHand = true;
		}
		else if (wParam == 0x34) {			// change keybind to leg movement
			isHand = false;
		}
		else if (wParam == 'E') {			
			if (isHand) {
				// Right upper arm rotate front
				if (rotateRightUpperArm <= -180) {
					rotateRightUpperArm = -180;
				}
				else {
					rotateRightUpperArm -= rotateSpeed;
				}
			}
			else {
				// Right upper leg rotate front
				if (rotateRightUpperLeg <= -45) {
					rotateRightUpperLeg = -45;
				}
				else {
					rotateRightUpperLeg -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'R') {
			if (isHand) {
				// Right upper arm rotate back
				if (rotateRightUpperArm >= 60) {
					rotateRightUpperArm = 60;
				}
				else {
					rotateRightUpperArm += rotateSpeed;
				}
			}
			else {
				// Right upper leg rotate back
				if (rotateRightUpperLeg >= 45) {
					rotateRightUpperLeg = 45;
				}
				else {
					rotateRightUpperLeg += rotateSpeed;
				}
			}
		}
		else if (wParam == 'D') {
			if (isHand) {
				// Right lower arm rotate front
				if (rotateRightLowerArm <= -110) {
					rotateRightLowerArm = -110;
				}
				else {
					rotateRightLowerArm -= rotateSpeed;
				}
			}
			else {
				// Right lower leg rotate front
				if (rotateRightLowerLeg <= 0) {
					rotateRightLowerLeg = 0;
				}
				else {
					rotateRightLowerLeg -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'F') {
			if (isHand) {
				// Right lower arm rotate back
				if (rotateRightLowerArm >= 0) {
					rotateRightLowerArm = 0;
				}
				else {
					rotateRightLowerArm += rotateSpeed;
				}
			}
			else {
				// Right lower leg rotate back
				if (rotateRightLowerLeg >= 70) {
					rotateRightLowerLeg = 70;
				}
				else {
					rotateRightLowerLeg += rotateSpeed;
				}
			}
		}
		else if (wParam == 'C') {
			if (isHand) {
				//Right wrist rotate clockwise
				rotateRightWrist -= rotateSpeed;
			}
			else {
				// Right feet rotate front
				if (rotateRightFeet <= 0) {
					rotateRightFeet = 0;
				}
				else {
					rotateRightFeet -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'V') {
			if (isHand) {
				//Right wrist rotate anticlockwise
				rotateRightWrist += rotateSpeed;
			}
			else {
				// Right feet rotate back
				if (rotateRightFeet >= 30) {
					rotateRightFeet = 30;
				}
				else {
					rotateRightFeet += rotateSpeed;
				}
			}
		}
		else if (wParam == 'Z') {
			if (isHand) {
				// Right finger grab together
				if (rotateRightFinger <= -30) {
					rotateRightFinger = -30;
				}
				else {
					rotateRightFinger -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'X') {
			if (isHand) {
				// Right finger release grab
				if (rotateRightFinger >= 0) {
					rotateRightFinger = 0;
				}
				else {
					rotateRightFinger += rotateSpeed;
				}
			}
		}
		else if (wParam == 'T') {
			if (isHand) {
				// Left upper leg rotate front
				if (rotateLeftUpperArm <= -180) {
					rotateLeftUpperArm = -180;
				}
				else {
					rotateLeftUpperArm -= rotateSpeed;
				}
			}
			else {
				// Left upper leg rotate front
				if (rotateLeftUpperLeg <= -45) {
					rotateLeftUpperLeg = -45;
				}
				else {
					rotateLeftUpperLeg -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'Y') {
			if (isHand) {
				// Left upper arm rotate back
				if (rotateLeftUpperArm >= 60) {
					rotateLeftUpperArm = 60;
				}
				else {
					rotateLeftUpperArm += rotateSpeed;
				}
			}
			else {
				// Left upper leg rotate back
				if (rotateLeftUpperLeg >= 45) {
					rotateLeftUpperLeg = 45;
				}
				else {
					rotateLeftUpperLeg += rotateSpeed;
				}
			}
		}
		else if (wParam == 'G') {
			if (isHand) {
				// Left lower arm rotate front
				if (rotateLeftLowerArm <= -110) {
					rotateLeftLowerArm = -110;
				}
				else {
					rotateLeftLowerArm -= rotateSpeed;
				}
			}
			else {
				// Left lower leg rotate front
				if (rotateLeftLowerLeg <= 0) {
					rotateLeftLowerLeg = 0;
				}
				else {
					rotateLeftLowerLeg -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'H') {
			if (isHand) {
				// Left lower arm rotate back
				if (rotateLeftLowerArm >= 0) {
					rotateLeftLowerArm = 0;
				}
				else {
					rotateLeftLowerArm += rotateSpeed;
				}
			}
			else {
				// Left lower leg rotate back
				if (rotateLeftLowerLeg >= 70) {
					rotateLeftLowerLeg = 70;
				}
				else {
					rotateLeftLowerLeg += rotateSpeed;
				}
			}
		}
		else if (wParam == 'B') {
			if (isHand) {
				// Left wrist rotate clockwise
				rotateLeftWrist -= rotateSpeed;
			}
			else {
				// Left feet rotate front
				if (rotateLeftFeet <= 0) {
					rotateLeftFeet = 0;
				}
				else {
					rotateLeftFeet -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'N') {
			if (isHand) {
				// Left wrist rotate anticlockwise
				rotateLeftWrist += rotateSpeed;
			}
			else {
				// Left feet rotate back
				if (rotateLeftFeet >= 30) {
					rotateLeftFeet = 30;
				}
				else {
					rotateLeftFeet += rotateSpeed;
				}
			}
		}
		else if (wParam == 'U') {
			if (isHand) {
				// Left finger rotate front
				if (rotateLeftFinger <= -30) {
					rotateLeftFinger = -30;
				}
				else {
					rotateLeftFinger -= rotateSpeed;
				}
			}
		}
		else if (wParam == 'I') {
			if (isHand) {
				// Left finger rotate back
				if (rotateLeftFinger >= 0) {
					rotateLeftFinger = 0;
				}
				else {
					rotateLeftFinger += rotateSpeed;
				}
			}
		}
		else if (wParam == 'A') {			
			if (isHand) {
				// change the right hand to ready state
				readyR = !readyR;
				rotateRightLowerArm = -90;
			}
		}
		else if (wParam == 'S') {
			if (isHand) {
				// shoot the bullet from right
				if (readyR && !isWeapon) {
					if (numRightShoot == 3) {
						numRightShoot = 0;
					}
					else {
						numRightShoot++;
					}
				}
			}
		}
		else if (wParam == 'J') {			
			if (isHand) {
				// change the left hand to ready state
				readyL = !readyL;
				rotateLeftLowerArm = -90;
			}
		}
		else if (wParam == 'K') {
			if (isHand) {
				//shoot the bullet from left
				if (readyL && !isWeapon) {
					if (numLeftShoot == 3) {
						numLeftShoot = 0;
					}
					else {
						numLeftShoot++;
					}
				}
			}
		}
		else if (wParam == 'Q') {			// change hand to sword
			isWeapon = !isWeapon;
		}

		else if (wParam == 0x30) {			// change texture (num 0)
			if (noOfTexture == 2) {
				noOfTexture = 0;
			}
			else {
				noOfTexture++;
			}
		}
		else if (wParam == 0x39) {			// on/off light (num 9)
			lightOn = !lightOn;
		}
		else if (wParam == 0x38) {			// Change keybind to change light position (num 8)
			lightPositionBinding = true;
		}
		else if (wParam == 0x37) {			// Change keybind to change light color (num 7)
			lightPositionBinding = false;
		}
		else if (wParam == VK_F1) {
			if (lightPositionBinding) {
				// Light move left
				lightX -= 0.1;
			}
			else {
				// Increase red color value to the light
				if (lightColorR >= 1.0) {
					lightColorR = 1.0;
				}
				else {
					lightColorR += 0.1;
				}
			}
			
		}
		else if (wParam == VK_F2) {
			if (lightPositionBinding) {
				// Light move right
				lightX += 0.1;
			}
			else {
				// Decrease red color value to the light
				if (lightColorR <= 0.0) {
					lightColorR = 0.0;
				}
				else {
					lightColorR -= 0.1;
				}
			}
		}
		else if (wParam == VK_F3) {
			if (lightPositionBinding) {
				// Light move up
				lightY += 0.1;
			}
			else {
				// Increase green color value to the light
				if (lightColorG >= 1.0) {
					lightColorG = 1.0;
				}
				else {
					lightColorG += 0.1;
				}
			}
		}
		else if (wParam == VK_F4) {
			if (lightPositionBinding) {
				// Light move down
				lightY -= 0.1;
			}
			else {
				// Decrease green color value to the light
				if (lightColorG <= 0.0) {
					lightColorG = 0.0;
				}
				else {
					lightColorG -= 0.1;
				}
			}
		}
		else if (wParam == VK_F5) {
			if (lightPositionBinding) {
				// Light move front
				lightZ += 0.1;
			}
			else {
				// Increase blue color value to the light
				if (lightColorB >= 1.0) {
					lightColorB = 1.0;
				}
				else {
					lightColorB += 0.1;
				}
			}
		}
		else if (wParam == VK_F6) {
			if (lightPositionBinding) {
				// Light move back
				lightZ -= 0.1;
			}
			else {
				// Decrease blue color value to the light
				if (lightColorB <= 0.0) {
					lightColorB = 0.0;
				}
				else {
					lightColorB -= 0.1;
				}
			}
		}

		else if (wParam == 'M') {		// Open battery box behind the body
			boxOpen = !boxOpen;
		}

		else if (wParam == 0x35) {			// Fighting animation on right weapon
			rightFight = true;
			rightStop = false;
			rightWeaponRotate = -45.0;
			rotateRightUpperArm = -90;
			isWeapon = true;
		}

		else if (wParam == 0x36) {			// Fighting animation on left weapon
			leftFight = true;
			leftStop = false;
			leftWeaponRotate = 45.0;
			rotateLeftUpperArm = -90;
			isWeapon = true;
		}

		break;
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void robotModel() {
	isWalking(wPress);
	ready(readyL, readyR);
	shoot(numLeftShoot, numRightShoot);
	fighting(rightFight, leftFight);

	glPushMatrix(); //Move the robot
	glTranslatef(0.0, 0.0, walkModel);

	glPushMatrix();
	glTranslatef(0.0, 2.7, 0.1);
	glScalef(0.4, 0.4, 0.4);
	headMovement(nodHead, shakeHead);
	Head::drawHead(rotateHeadX,rotateHeadY);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 1.5, 0.0);
	Body::upperBody(boxOpen);
	Body::lowerBody();
	glPopMatrix();

	// Right Hand
	glPushMatrix();
	glTranslatef(-1.1, 0.9, 0.47);
	glScalef(0.5, 0.5, 0.5);
	Hand::drawHand(isWeapon, walkHandRotate,rotateRightUpperArm,rotateRightLowerArm,rotateRightWrist, rotateRightFinger, firstRightTranslate, secondRightTranslate, thirdRightTranslate, rightWeaponRotate);
	glPopMatrix();

	// Left Hand
	glPushMatrix();
	glTranslatef(1.1, 0.9, 0.47);
	glScalef(0.5, 0.5, 0.5);
	Hand::drawHand(isWeapon, -walkHandRotate, rotateLeftUpperArm, rotateLeftLowerArm, rotateLeftWrist, rotateLeftFinger, firstLeftTranslate, secondLeftTranslate, thirdLeftTranslate, leftWeaponRotate);
	glPopMatrix();

	// Right leg
	glPushMatrix();
	glTranslatef(-0.25, 0.55, 0.5);
	glScalef(1.0, 0.8, 1.0);
	Leg::drawleg(walkUpperLegRotate, rotateRightUpperLeg, rotateRightLowerLeg,rotateRightFeet);
	glPopMatrix();

	// Left leg
	glPushMatrix();
	glTranslatef(0.25, 0.55, 0.5);
	glScalef(1.0, 0.8, 1.0);
	Leg::drawleg(-walkUpperLegRotate, rotateLeftUpperLeg, rotateLeftLowerLeg, rotateLeftFeet);
	glPopMatrix();

	glPopMatrix(); //Move the robot
}

void lighting() {
	if (lightOn) {
		glEnable(GL_LIGHTING);
	}
	else {
		glDisable(GL_LIGHTING);
	}

	glEnable(GL_COLOR_MATERIAL);

	GLfloat light_ambient[] = { 0.3,0.3,0.3,0.5 };
	GLfloat light_diffuse[] = { lightColorR,lightColorG,lightColorB,1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

	//material
	GLfloat mat_ambient[] = { 0.3,0.3,0.3,0.5 };
	GLfloat mat_diffuse[] = { lightColorR,lightColorG,lightColorB,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

	GLfloat light_position[] = { lightX,lightY,lightZ,1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);

}

void display()
{
	Texture tex;

	glClearColor(0.698, 0.839, 0.961, 0.741);
	glShadeModel(GL_SMOOTH);							// Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Nice perspective corrections	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	View::projection(isOrtho, camX, camY);
	glRotatef(rotateCam, 0.0, 1.0, 0.0);
	if (isOrtho)
		Background::orthoBackground();
	else
		Background::perspectiveBackground();

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();		// rotate model

	if(isOrtho){
		glTranslatef(0, 0, cameraDistance);
		glTranslatef(0, -2.0, 5.5);
		glRotatef(cameraAngleY, 0, 1, 0);
		glScalef(1.5, 1.5, 1.5);
	}
	else {
		View::viewing(cameraDistance, cameraAngleY);
	}

	if (lightOn) {
		glPushMatrix();
		glTranslatef(lightX, lightY, lightZ);

		glColor3f(lightColorR, lightColorG, lightColorB);
		ShapeDraw::drawSphere(GLU_FILL, 0.5, 30, 30);

		glPopMatrix();
	}
	lighting();
	

	GLuint texture;
	glEnable(GL_TEXTURE_2D);
	if (noOfTexture == 0) {
		texture = tex.loadTexture("");
	}
	else if (noOfTexture == 1) {
		texture = tex.loadTexture("Metal2.bmp");
	}
	else if (noOfTexture == 2) {
		texture = tex.loadTexture("wood.bmp");
	}
	robotModel();

	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();		// rotate model

	glPushMatrix();
	glTranslatef(-0.5, -1.0, -5.0);
	Bridge::drawBridge(isOpen);
	glPopMatrix();
	glDisable(GL_LIGHTING);

}
//--------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		0, 0, 800, 1000,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------