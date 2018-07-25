#include "Triangle.h"
#include <GLFW/glfw3.h>


Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}

void Triangle::draw()
{
	
		to = to + transform.spd;
		glPushMatrix();
		glTranslatef(transform.t.x, transform.t.y, transform.t.z);
		glRotatef(to, transform.r.x, transform.r.y, transform.r.z);	
		glScalef(transform.s.x, transform.s.y, transform.s.z);
		glBegin(GL_TRIANGLES);
		glColor3f(transform.c.x, transform.c.y, transform.c.z);
		glVertex3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.732f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		
		glEnd();
		glPopMatrix();
	
}

void Triangle::drawPlane()
{
	to = to + transform.spd;
	glPushMatrix();
	glTranslatef(transform.t.x, transform.t.y, transform.t.z);
	glRotatef(to, transform.r.x, transform.r.y, transform.r.z);
	glScalef(transform.s.x, transform.s.y, transform.s.z);

	glBegin(GL_TRIANGLES);
	glColor3f(transform.c.x, transform.c.y, transform.c.z);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.732f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);

	glColor3f(transform.c.x, transform.c.y, transform.c.z);
	glVertex3f(-0.5f, -0.8f, 0.0f);
	glVertex3f(0.0f, 1.732f-0.8f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);

	glEnd();
	glPopMatrix();
}