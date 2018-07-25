#pragma once
#include "Vec3.h"
#include "Transform.h"
class Rectangle
{
public:
	Rectangle();
	~Rectangle();

	Transform transform;
	void setnewMove();
	float to = 0;
	float randomSpd;
	float moveDown = 0;
	float moveSide = 0;
	float ranSpdMin = 0.00005f, ranSpdMax = 0.0005f;
	float ranSideMin = -1.0f, randSideMax = 1.0f;
	int round = 1;
	void draw();
	float Rectangle::Rand(float Min, float Max);
};

