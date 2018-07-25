#pragma once
#include "Vec4.h"
class Mat4
{
public:
	Mat4();
	Mat4( const Vec4<float>& row0,
		  const Vec4<float>& row1,
		  const Vec4<float>& row2,
		  const Vec4<float>& row3
	);
	Mat4(float a);
	
	~Mat4();

	Mat4& mul(const Mat4& other);
	Mat4& scl(float sclvalue);
	friend Mat4 operator*(Mat4 left, const Mat4& right);
	friend Vec4<float> operator*(const Mat4& left, const Vec4<float>& right);

	Mat4& operator*=(const Mat4& other);
	Mat4& minor();
	Mat4& cofactor();
	Mat4& transpose();
	Mat4& inverse();
	static Mat4 Identity();
	static Mat4 Inverse(const Mat4& matrix);
	void zero();
	float det();
	float m[4][4];
	
	void print();
	
};

