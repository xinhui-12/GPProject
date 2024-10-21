#include "ShapeDraw.h"

void ShapeDraw::drawCuboid(GLenum drawStyle, float sizeX, float sizeY, float sizeZ) {
	glBegin(drawStyle);

	// Face 1 : Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, sizeZ);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(sizeX, 0.0f, sizeZ);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(sizeX, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	// Face 2 : Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, sizeZ);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, sizeY, sizeZ);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, sizeY, 0.0f);
	// Face 3 : Front
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, sizeY, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(sizeX, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(sizeX, sizeY, 0.0f);
	// Face 4 : Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(sizeX, sizeY, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(sizeX, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(sizeX, 0.0f, sizeZ);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(sizeX, sizeY, sizeZ);
	// Face 5 : Back
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(sizeX, sizeY, sizeZ);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(sizeX, 0.0f, sizeZ);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, sizeZ);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, sizeY, sizeZ);
	// Face 6 : Above
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, sizeY, sizeZ);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(sizeX, sizeY, sizeZ);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(sizeX, sizeY, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, sizeY, 0.0f);

	glEnd();
}

void ShapeDraw::drawPyramid(bool isFill, float size) {
	// Pyramid base
	if (isFill)
		glBegin(GL_QUADS);
	else
		glBegin(GL_LINE_LOOP);

	// Define the normal for the base of the pyramid
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(size, 0.0f, size);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	// Pyramid 4 triangles
	if (isFill)
		glBegin(GL_TRIANGLE_FAN);
	else
		glBegin(GL_LINE_LOOP);

	glTexCoord2f(0.0f, 0.5f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(size / 2, size, size / 2);
	glTexCoord2f(0.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(size, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(size, 0.0f, size);
	glTexCoord2f(1.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, size);
	glTexCoord2f(0.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();
}

void ShapeDraw::drawSphere(GLenum drawStyle, double radius, int slices, int stacks) {
	GLUquadricObj* sphere = NULL;					//quadric obj pointer
	sphere = gluNewQuadric();						//create the quadric obj
	gluQuadricDrawStyle(sphere, drawStyle);			//set the draw style
	gluQuadricTexture(sphere, true);
	gluSphere(sphere, radius, slices, stacks);					//draw sphere
	gluDeleteQuadric(sphere);						//delete quadric obj pointer
}

void ShapeDraw::drawCylinder(GLenum drawStyle, double baseRadius, double topRadius, double height, int slices, int stacks) {
	GLUquadricObj* cylinder = NULL;					//quadric obj pointer
	cylinder = gluNewQuadric();						//create the quadric obj
	gluQuadricDrawStyle(cylinder, drawStyle);			//set the draw style
	gluQuadricTexture(cylinder, true);
	gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
	gluDeleteQuadric(cylinder);						//delete quadric obj pointer
}

void ShapeDraw::drawCone(GLenum drawStyle, double radius, double height, int slices, int stacks) {
	GLUquadricObj* cone = NULL;					//quadric obj pointer
	cone = gluNewQuadric();						//create the quadric obj
	gluQuadricDrawStyle(cone, drawStyle);			//set the draw style
	gluQuadricTexture(cone, true);
	gluCylinder(cone, 0, radius, height, slices, stacks);
	gluDeleteQuadric(cone);						//delete quadric obj pointer
}

void ShapeDraw::drawDisk(GLenum drawStyle, double innerRadius, double outerRadius) {
	GLUquadricObj* disk = NULL;					//quadric obj pointer
	disk = gluNewQuadric();						//create the quadric obj
	gluQuadricDrawStyle(disk, drawStyle);			//set the draw style
	gluQuadricTexture(disk, true);
	gluDisk(disk, innerRadius, outerRadius, 30, 30);
	gluDeleteQuadric(disk);						//delete quadric obj pointer
}

void ShapeDraw::drawPartialDisk(GLenum drawStyle, double innerRadius, double outerRadius, double startAngle, double endAngle) {
	GLUquadricObj* disk = NULL;					//quadric obj pointer
	disk = gluNewQuadric();						//create the quadric obj
	gluQuadricDrawStyle(disk, drawStyle);			//set the draw style
	gluQuadricTexture(disk, true);
	gluPartialDisk(disk, innerRadius, outerRadius, 10, 10, startAngle, endAngle);
	gluDeleteQuadric(disk);						//delete quadric obj pointer
}

void ShapeDraw::drawCircle(GLenum primitive, float centerX, float centerY, float xRadius, float yRadius) {
	ShapeDraw shape;
	glBegin(primitive);
	for (float circleAngle = 0; circleAngle <= (2 * shape.PI); circleAngle += (2 * shape.PI) / 360) {
		float x2 = centerX + xRadius * cos(circleAngle);
		float y2 = centerY + yRadius * sin(circleAngle);
		float textureX = (cos(circleAngle) + 1.0) * 0.5;
		float textureY = (sin(circleAngle) + 1.0) * 0.5;
		glTexCoord2f(textureX, textureY);
		glVertex2f(x2, y2);
	}
	glEnd();
}

