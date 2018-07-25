#pragma once
#include <math.h>
#define PI 3.14159265

template <class T>

class Vec2
{
public:
	Vec2<T>();
	Vec2<T>(T x, T y);
	~Vec2<T>();
	T x;
	T y;


	Vec2<T>& add(Vec2<T> other);
	Vec2<T>& subtract(Vec2<T> other);
	Vec2<T>& scale(T scl);
	float distance(Vec2<T> other);
	float angle(Vec2<T> other);
	int dot(Vec2<T> other);
	int cross(Vec2<T> other);
	float calMagnitude();
	float calMagnitudeSq();
	Vec2<T>& normalize();
	
	template <class T>
	friend Vec2<T> operator+(Vec2<T> left, Vec2<T> right);
	template <class T>
	friend Vec2<T> operator-(Vec2<T> left, Vec2<T> right);

	Vec2<T> &operator*(float const& other);
	Vec2<T> &operator*=(float const& other);
	Vec2<T> &operator/(float const& other);
	Vec2<T> &operator/=(float const& other);
	Vec2<T> &operator+=(Vec2<T> const& other);
	Vec2<T> &operator-=(Vec2<T> const& other);
	void print();
	bool operator==(const Vec2<T> &other) const;

};

template <class T>
Vec2<T>::Vec2(T x_, T y_)
	:x(x_), y(y_)
{

}

template <class T>
Vec2<T>::~Vec2()
{
}

template <class T>
Vec2<T> &Vec2<T>::add(Vec2<T> other)
{
	x = x + other.x;
	y = y + other.y;

	return *this;
}

template <class T>
Vec2<T> &Vec2<T>::subtract(Vec2<T> other)
{
	x = x - other.x;
	y = y - other.y;

	return *this;
}
template <class T>
Vec2<T> &Vec2<T>::scale(T scl)
{
	x = x * scl;
	y = y * scl;

	return *this;
}
template <class T>
Vec2<T> operator+(Vec2<T> left, Vec2<T> right)
{
	return left.add(right);
}
template <class T>
Vec2<T>& Vec2<T>::operator+=(Vec2<T> const& other)
{
	return this->add(other);
}
template <class T>
Vec2<T> operator-(Vec2<T> left, Vec2<T> right)
{
	return left.subtract(right);
}
template <class T>
Vec2<T>& Vec2<T>::operator*(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec2<T>& Vec2<T>::operator*=(float const& other)
{
	return this->scale(other);
}
template <class T>
Vec2<T>& Vec2<T>::operator/(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
Vec2<T>& Vec2<T>::operator/=(float const& other)
{
	return this->scale(1 / other);
}
template <class T>
Vec2<T>& Vec2<T>::operator-=(Vec2<T> const& other)
{
	return this->subtract(other);
}

template <class T>
bool Vec2<T>::operator==(const Vec2<T> & other) const
{
	return(x == other.x) && (y == other.y);
}
template <class T>
float Vec2<T>::angle(Vec2<T> other)
{
	if (this->x == 0 && other.x == 0) { return 0; }
	else if (this->y == 0 && other.y == 0) { return 0; }
	else if ((this->x == 0 && other.y == 0)  || (this->y == 0 && other.x == 0) ) { return 90; }
	else if ((this->x == 0 && other.y != 0)  || (other.x == 0 && this->y != 0)) { return atan(x/y)* 180 / PI; }
	else if (atan(y / x) == atan(other.y / other.x)) { return 0; }
	else return acos((this->dot(other)) / (calMagnitude() *other.calMagnitude())) * 180 / PI;
}


template <class T>
int Vec2<T>::dot(Vec2<T> other)
{
	return x * other.x + y * other.y;
}
template <class T>
int Vec2<T>::cross(Vec2<T> other)
{
	return x * other.y - y * other.x;
}
template <class T>
float Vec2<T>::calMagnitude()
{
	return sqrt(x*x + y * y);
}
template <class T>
float Vec2<T>::calMagnitudeSq()
{
	return x * x + y * y;
}
template <class T>
Vec2<T>& Vec2<T>::normalize()
{
	x = x / calMagnitude();
	y = y / calMagnitude();
	return *this;
}
template <class T>
float Vec2<T>::distance(Vec2<T> other)
{
	return this->subtract(other).calMagnitude();
}
template <class T>
void Vec2<T>::print()
{
	cout << "(" << x << "," << y << ")" << endl;
}

