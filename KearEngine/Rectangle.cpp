#include <iostream>
#include "Rectangle.h"
#include <GLFW/glfw3.h>
#include <math.h>
#include <time.h>

Rectangle::Rectangle()
{
	
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	to = to + transform.spd;
	moveDown =  moveDown + randomSpd;
	transform.t.y = 1-moveDown;
	glPushMatrix();
	glRotatef(to, transform.r.x, transform.r.y, transform.r.z);
	glTranslatef(transform.t.x, transform.t.y, transform.t.z);
	glScalef(transform.s.x, transform.s.y, transform.s.z);

	glBegin(GL_QUADS);
	glColor3f(transform.c.x, transform.c.y, transform.c.z);
	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f,- 0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glEnd();
	glPopMatrix();

}

void Rectangle::setnewMove()
{
	
	round++;
	transform.t.y = 1.0f;
	moveDown = 0;
	randomSpd = Rand(ranSpdMin, ranSpdMax)*((100+round*10)/100);	
	transform.t.x = Rand(ranSideMin, randSideMax);
	
}

float Rectangle::Rand(float Min, float Max)
{
	
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}
