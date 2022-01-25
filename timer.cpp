#include <GL/glut.h>
#include "./mylib/gTime.h"
#include "./mylib/gGL.h"
#include "./mylib/gWindow.h"

float hAngle = 0;
float mAngle = 0;
float sAngle = 0;
float msAngle = 0;
float coverAngle = 0;

auto hstart = getCurrentTime();
auto mstart = getCurrentTime();
auto sstart = getCurrentTime();
auto msstart = getCurrentTime();

void clear()
{
	glClearColor(.8, .8, .8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void timer()
{
	long last = getCurrentTime();
	long hdiff = last - hstart;
	long mdiff = last - mstart;
	long sdiff = last - sstart;
	long msdiff = last - msstart;

	int hrs = 3600000;
	int mins = 60000;
	int seconds = 1000;

	if (hdiff >= hrs)
	{
		hstart = last;
		hAngle += 30;
	}
	if (mdiff >= mins)
	{
		mstart = last;
		mAngle += 6;
	}
	if (sdiff >= seconds)
	{
		sstart = last;
		sAngle += 6;
		msAngle = 0;
	}
	if (msdiff >= 1)
	{
		msstart = last;
		msAngle += 0.36;
		coverAngle += 0.1;
	}
	glutPostRedisplay();
}

void display()
{
	clear();
	timer();

	glPushMatrix();
	// hours
	glRotatef(coverAngle, 1.0, 1.0, 1.0);


	drawHand(hAngle, 7.0, 1, .9);
	// minutes
	drawHand(mAngle, 6.0, 2, .7);
	//seconds
	drawHand(sAngle, 5.0, 3, .5);
	//ms
	drawHand(msAngle, 4.0, 4, .2);

	drawHollowCircle(0.0, 0.0, 0.9, 0);

	glPopMatrix();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Crazy Clock");
	glutDisplayFunc(display);
	glutMainLoop();
}