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
	Quaternion operator=(const Quaternion& other);

private:
	Vec4 elements;
};

inline Quaternion::Quaternion(void)
{
	elements.MakeZero();
}

inline Quaternion::Quaternion(Real w, Real i, Real j, Real k)
{
	elements[0] = w;
	elements[1] = i;
	elements[2] = j;
	elements[3] = k;
}

inline Quaternion::Quaternion(Vec3& axis, float angle)
{
	Real s = sin(angle / 2.0f);
	elements[0] = cos(angle / 2.0f);
	elements[1] = s * axis[0];
	elements[2] = s * axis[1];
	elements[3] = s * axis[2];
}

inline Quaternion Quaternion::operator+(const Quaternion& other)
{
	
}

