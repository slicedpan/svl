#pragma once


#include "Vec4.h"
#include "Vec3.h"
#include "Mat4.h"

class Quaternion
{
public:
	Quaternion(void);
	Quaternion(Real w, Real i, Real j, Real k);
	Quaternion(Vec3& axis, float angle);
	~Quaternion();
	Mat4 ToMatrix();

	Quaternion operator+(const Quaternion& other); 
	Quaternion operator-(const Quaternion& other);
	Quaternion operator*(const Quaternion& other);
	Quaternion operator/(const Quaternion& other);

	Quaternion& operator=(const Quaternion& other);
	Quaternion& operator+=(const Quaternion& other);
	Quaternion& operator-=(const Quaternion& other);
	Quaternion& operator*=(const Quaternion& other);
	Quaternion& operator/=(const Quaternion& other);

	Real& operator[](const int index);
	Real Length();
private:
	Real elt[4];
};

inline Quaternion::Quaternion(void)
{
	elements.MakeZero();
}

inline Quaternion::Quaternion(Real w, Real i, Real j, Real k)
{
	elt[0] = w;
	elt[1] = i;
	elt[2] = j;
	elt[3] = k;
}

inline Quaternion::Quaternion(Vec3& axis, float angle)
{
	Real s = sin(angle / 2.0f);
	elt[0] = cos(angle / 2.0f);
	elt[1] = s * axis[0];
	elt[2] = s * axis[1];
	elt[3] = s * axis[2];
}

inline Quaternion Quaternion::operator + (const Quaternion& other)
{
	return Quaternion(elements[0] + other[0], elements[1] + other[1], elements[2] + other[2], elements[3] + other[3]);
}

inline Quaternion& Quaternion::operator = (const Quaternion& other)
{		
	elt[0] = other[0];
	elt[1] = other[1];
	elt[2] = other[2];
	elt[3] = other[3];
	return *this;
}

inline Real& Quaternion::operator[] (int index)
{
	return elt[index];
}

inline Quaternion& Quaternion::operator+=(const Quaternion& other)
{
	elt[0] += other[0];
	elt[1] += other[1];
	elt[2] += other[2];
	elt[3] += other[3];
	return *this;
}

inline Quaternion& Quaternion::operator-=(const Quaternion& other)
{
	elt[0] -= other[0];
	elt[1] -= other[1];
	elt[2] -= other[2];
	elt[3] -= other[3];
	return *this;
}

inline Quaternion& Quaternion::operator*=(const Quaternion& other)
{
	Quaternion tmp;
	tmp[0] = elt[0] * other[0] - elt[1] * other[1] - elt[2] * other[2] - elt[3] * other[3];
	tmp[1] = elt[0] * other[1] - elt[1] * other[0] + elt[2] * other[3] - elt[3] * other[2];
	tmp[2] = elt[0] * other[2] - elt[1] * other[3] + elt[2] * other[0] + elt[3] * other[1];
	tmp[3] = elt[0] * other[3] + elt[1] * other[2] - elt[2] * other[1] + elt[3] * other[0];
	*this = tmp;
	return *this;
}

inline Quaternion Quaternion::operator*(const Quaternion& lhs, const Quaternion& rhs)
{
	
}

inline Quaternion& Quaternion::operator/=(const Quaternion& other)
{
	Quaternion tmp;
	tmp = 
}

inline Real Quaternion::Length()
{
	return sqrt(pow(elt[0], 2.0f), pow(elt[1], 2.0f), pow(elt[2], 2.0f), pow(elt[3], 2.0f));
}


