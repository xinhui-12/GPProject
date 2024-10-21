#include "Texture.h"

GLuint Texture::loadTexture(LPCSTR filename) {
	//Take from step 1
	BITMAP BMP;				// bitmap structure
	HBITMAP hBMP = NULL;	// bitmap handle
	GLuint texture = 0;		// texture name

	// Step 3: Initialize texture info
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), filename, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	GetObject(hBMP, sizeof(BMP), &BMP);

	// Step 4: Assign texture to polygon
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	//GL_NEAREST faster than GL_LINEAR
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);

	// take from step 5
	DeleteObject(hBMP);
	return texture;
}
