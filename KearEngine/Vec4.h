#pragma once
#include <math.h>
#define PI 3.14159265

template <class T>

class Vec4
{
public:
	Vec4<T>();
	Vec4<T>(T x, T y, T z , T w);
	~Vec4<T>();

	T x, y, z ,w;


	Vec4<T>& add(Vec4<T> other);
	Vec4<T>& subtract(Vec4<T> other);
	Vec4<T>& scale(T scl);
	float angle(Vec4<T> other);
	float distance(Vec4<T> other);
	int dot(Vec4<T> other);
	Vec4<T>& cross(Vec4<T> other);
	float calMagnitude();
	float calMagnitudeSq();
	Vec4<T>& normalize();

	friend Vec4<T> operator+(Vec4<T> left, Vec4<T> right);
	friend Vec4<T> operator-(Vec4<T> left, Vec4<T> right);
	Vec4<T> &operator*(float const& other);
	Vec4<T> &operator*=(float const& other);
	Vec4<T> &operator/(float const& other);
	Vec4<T> &operator/=(float const& other);
	Vec4<T> &operator+=(Vec4<T> const& other);
	Vec4<T> &operator-=(Vec4<T> const& other);
	bool operator==(const Vec4<T> &other) const;
	void print();
};
template <class T>
Vec4<T>::Vec4(T x_, T y_, T z_ , T a_)
	:x(x_), y(y_), z(z_), w(a_)
{
	
}
template <class T>
Vec4<T>::~Vec4()
{

}

template <class T>
Vec4<T>& Vec4<T>::add(Vec4<T> other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	w = w + other.w;
	return *this;
}

template <class T>
Vec4<T>& Vec4<T>::subtract(Vec4<T> other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	w = w - other.w;
	return *this;
}
template <class T>
Vec4<T>& Vec4<T>::scale(T scl)
{
	x = x * scl;
	y = y * scl;
	z = z * scl;
	w = w * scl;
	return *this;
}

template <class T>
Vec4<T> operator+(Vec4<T> left, Vec4<T> right)
{
	return left.add(right);
}
template <class T>
Vec4<T> operator-(Vec4<T> left, Vec4<T> right)
{
	return left.subtract(right);
}

template <class T>
bool Vec4<T>::operator==(const Vec4<T> & other) const
{
	return(x == other.x) && (y == other.y) && (z == other.z);
}
template <class T>
int Vec4<T>::dot(Vec4<T> other)
{
	return x * other.x + y * other.y + z * other.z;
}
template <class T>
Vec4<T>& Vec4<T>::cross(Vec4<T> other)
{
	//return x * other.y - y * other.x;
	Vec4<T> crossResult(0, 0, 0);
	crossResult.x = y * other.z - z * other.y;
	crossResult.y = z * other.x - x * other.z;
	crossResult.z = x * other.y - y * other.x;
	return crossResult;
}
template <class T>
float Vec4<T>::calMagnitude()
{
	return sqrt(x*x + y * y + z * z);
}
template <class T>
float Vec4<T>::calMagnitudeSq()
{
	return x * x + y * y + z * z;
}
template <class T>
Vec4<T>& Vec4<T>::normalize()
{
	x = x / calMagnitude();
	y = y / calMagnitude();
	z = z / calMagnitude();
	w = w / calMagnitude();
	return *this;
}

template <class T>
float Vec4<T>::angle(Vec4<T> other)
{
	
	if (atan(this->y / this->x) == atan(other.y / other.x) &&
		atan(this->y / this->z) == atan(other.y / other.z) &&
		atan(this->x / this->y) == atan(other.x / other.y))
	{
		return 0;
	}
	else return acos((this->dot(other)) / (calMagnitude() *other.calMagnitude())) * 180 / PI;
}
template <class T>
float Vec4<T>::distance(Vec4<T> other)
{
	return this->subtract(other).calMagnitude();
}
template <class T>
Vec4<T>& Vec4<T>::operator+=(Vec4<T> const& other)
{
	return this->add(other);
}
template <class T>
Vec4<T>& Vec4<T>::operator-=(Vec4<T> const& other)
{
	return this->subtract(other);
}
template <class T>
Vec4<T>& Vec4<T>::operator*(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec4<T>& Vec4<T>::operator*=(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec4<T>& Vec4<T>::operator/(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
Vec4<T>& Vec4<T>::operator/=(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
void Vec4<T>::print()
{
	cout << "(" << x << "," << y << "," << z << "," << w << ")" << endl;
}