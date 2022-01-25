#include <GL/glut.h>
#include <math.h>

/* void glVertex2window(float x, float y)
{
	int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

	x = (2 / (windowWidth / x)) - 1;
	y = (2 / (windowHeight / y)) - 1;
	glVertex2f(x, y);
} */

void drawHand(float angle, float lineWidth, int color, float size)
{
	switch (color)
	{
	case 1:
		glColor3f(.6, .7, .8);
		break;
	case 2:
		glColor3f(.5, .6, .7);
		break;
	case 3:
		glColor3f(.4, .5, .6);
		break;
	case 4:
		glColor3f(.3, .4, .5);
		break;

	default:
		break;
	}
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glLineWidth(lineWidth);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(angle, 0.0, 0.0, 1.0);

	glBegin(GL_LINES);

	glVertex2f(.0, .0);
	glVertex2f(.0, size);

	glEnd();
	glPopMatrix();
}

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius, float angle)
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.141592;

	glPushMatrix();

	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLineWidth(25.0);
	glMatrixMode(GL_MODELVIEW);
	glRotatef(angle, 0.0, 1.0, 0.0);

	glBegin(GL_LINE_LOOP);

	for (i = 0; i <= lineAmount; i++)
	{
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount)));
	}
	glEnd();
	glPopMatrix();
}