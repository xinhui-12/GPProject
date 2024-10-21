
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

class ShapeDraw
{
public:
	// drawStyle == GLU_POINT, GLU_LINE, GLU_FILL, GLU_SILHOUETTE
	// recommend to use for below method
	// GLU_LINE, GLU_FILL
	static void drawSphere(GLenum drawStyle, double radius, int slices, int stacks);
	static void drawCylinder(GLenum drawStyle, double baseRadius, double topRadius, double height, int slices, int stacks);
	static void drawCone(GLenum drawStyle, double radius, double height, int slices, int stacks);
	static void drawDisk(GLenum drawStyle, double innerRadius, double outerRadius);
	static void drawPartialDisk(GLenum drawStyle, double innerRadius, double outerRadius, double startAngle, double endAngle);

	// primitive == GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_POLYGON, GL_QUADS, GL_QUAD_STRIP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	// recommend to use for below method
	// GL_LINE_LOOP, GL_TRIANGLE_FAN
	static void drawCircle(GLenum primitive, float centerX, float centerY, float xRadius, float yRadius);

	// GL_LINE_STRIP, GL_QUADS
	static void drawCuboid(GLenum drawStyle, float sizeX, float sizeY, float sizeZ);

	static void drawPyramid(bool isFill, float size);

private:
	float PI = 3.1429;    // PI
};

