#pragma once
#include <math.h>
#define PI 3.14159265

template <class T>

class Vec3
{
public:
	Vec3<T>();
	Vec3<T>(T x, T y, T z);
	~Vec3<T>();

	T x, y, z;


	Vec3<T>& add(Vec3<T> other);
	Vec3<T>& subtract(Vec3<T> other);
	Vec3<T>& scale(T scl);
	float angle(Vec3<T> other);
	float distance(Vec3<T> other);
	int dot(Vec3<T> other);
	Vec3<T>& cross(Vec3<T> other);
	float calMagnitude();
	float calMagnitudeSq();
	Vec3<T>& normalize();

	friend Vec3<T> operator+(Vec3<T> left, Vec3<T> right);
	friend Vec3<T> operator-(Vec3<T> left, Vec3<T> right);
	Vec3<T> &operator*(float const& other);
	Vec3<T> &operator*=(float const& other);
	Vec3<T> &operator/(float const& other);
	Vec3<T> &operator/=(float const& other);
	Vec3<T> &operator+=(Vec3<T> const& other);
	Vec3<T> &operator-=(Vec3<T> const& other);
	bool operator==(const Vec3<T> &other) const;
	void print();

};
template <class T>
Vec3<T>::Vec3(T x_, T y_, T z_)
	:x(x_), y(y_), z(z_)
{

}
template <class T>
Vec3<T>::Vec3()
{

}

template <class T>
Vec3<T>::~Vec3()
{

}

template <class T>
Vec3<T>& Vec3<T>::add(Vec3<T> other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;

	return *this;
}

template <class T>
Vec3<T>& Vec3<T>::subtract(Vec3<T> other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;

	return *this;
}
template <class T>
Vec3<T>& Vec3<T>::scale(T scl)
{
	x = x * scl;
	y = y * scl;
	z = z * scl;

	return *this;
}

template <class T>
Vec3<T> operator+(Vec3<T> left, Vec3<T> right)
{
	return left.add(right);
}
template <class T>
Vec3<T> operator-(Vec3<T> left, Vec3<T> right)
{
	return left.subtract(right);
}

template <class T>
bool Vec3<T>::operator==(const Vec3<T> & other) const
{
	return(x == other.x) && (y == other.y) && (z == other.z);
}
template <class T>
int Vec3<T>::dot(Vec3<T> other)
{
	return x * other.x + y * other.y + z * other.z;
}
template <class T>
Vec3<T>& Vec3<T>::cross(Vec3<T> other)
{
	//return x * other.y - y * other.x;
	Vec3<T> crossResult(0, 0, 0);
	crossResult.x = y * other.z - z * other.y;
	crossResult.y = z * other.x - x * other.z;
	crossResult.z = x * other.y - y * other.x;
	return crossResult;
}
template <class T>
float Vec3<T>::calMagnitude()
{
	return sqrt(x*x + y * y + z * z);
}
template <class T>
float Vec3<T>::calMagnitudeSq()
{
	return x * x + y * y + z * z;
}
template <class T>
Vec3<T>& Vec3<T>::normalize()
{
	x = x / calMagnitude();
	y = y / calMagnitude();
	z = z / calMagnitude();
	return *this;
}

template <class T>
float Vec3<T>::angle(Vec3<T> other)
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
float Vec3<T>::distance(Vec3<T> other)
{
	float newx = x - other.x;
	float newy = y - other.y;
	float newz = z - other.z;
	return sqrt(newx*newx + newy * newy + newz * newz);
	
}
template <class T>
Vec3<T>& Vec3<T>::operator+=(Vec3<T> const& other)
{
	return this->add(other);
}
template <class T>
Vec3<T>& Vec3<T>::operator-=(Vec3<T> const& other)
{
	return this->subtract(other);
}
template <class T>
Vec3<T>& Vec3<T>::operator*(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec3<T>& Vec3<T>::operator*=(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec3<T>& Vec3<T>::operator/(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
Vec3<T>& Vec3<T>::operator/=(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
void Vec3<T>::print()
{
	cout << "(" << x << "," << y << "," << z << ")" << endl;
}