#include "Background.h"
#include "ShapeDraw.h"
#include "Texture.h"
Texture texture;

void Background::perspectiveBackground()
{
	GLuint tex;
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glTranslatef(-10.0, -10.0, -10.0);
	tex = texture.loadTexture("sky3.bmp");
	glColor3f(1.0, 1.0, 1.0);
	ShapeDraw::drawCuboid(GL_QUADS, 20.0, 20.0, 20.0);
	glPopMatrix();
	glDeleteTextures(1, &tex);

	glPushMatrix();
	glTranslatef(-10.0, -8.0, -10.0);
	tex = texture.loadTexture("ocean.bmp");
	glColor3f(1.0, 1.0, 1.0);
	ShapeDraw::drawCuboid(GL_QUADS, 20.0, 5.0, 20.0);
	glPopMatrix();
	glDeleteTextures(1, &tex);

	glDisable(GL_TEXTURE_2D);
}

void Background::orthoBackground()
{
	GLuint tex;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(-20.0, -10.0, 0.0);
	tex = texture.loadTexture("sky3.bmp");
	glColor3f(1.0, 1.0, 1.0);
	ShapeDraw::drawCuboid(GL_QUADS, 40.0, 40.0, 20.0);
	glPopMatrix();
	glDeleteTextures(1, &tex);

	glPushMatrix();
	glTranslatef(-20.0, -10.0, -11.0);
	tex = texture.loadTexture("ocean.bmp");
	glColor3f(1.0, 1.0, 1.0);
	ShapeDraw::drawCuboid(GL_QUADS, 40.0, 10.0, 15.0);
	glPopMatrix();
	glDeleteTextures(1, &tex);

	glDisable(GL_TEXTURE_2D);
}
