#pragma once
#include "Vec3.h"
class Transform
{
public:
	Transform();
	~Transform();
public:
	Vec3<float> t, r, s, c;
	float spd;
	
	Transform(Vec3<float> _t, Vec3<float> _r, Vec3<float> _s, Vec3<float> _c, float _spd) :t(_t), r(_r), s(_s), c(_c), spd(_spd) {};

};

