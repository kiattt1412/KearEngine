#pragma once
#include "Vec3.h"
#include "Transform.h"
class Triangle
{
public:
	Triangle();
	~Triangle();

	Transform transform;
	float to = 0;
	
	void draw();
	void drawPlane();
};

