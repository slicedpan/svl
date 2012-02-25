
#ifndef __Quaternion__
#define __Quaternion__

#include "Mat4.h"
#include "Mat3.h"
#include "Vec4.h"
#include "Vec3.h"

inline Mat4 qGetTransform(Vec4& quat)
{
	float a = quat[0];
	float b = quat[1];
	float c = quat[2];
	float d = quat[3];
	float m00 = pow(a, 2) + pow(b, 2) - pow(c, 2) - pow(d, 2);
	float m10 = 2 * b *c - 2 * a * d;
	float m20 = 2 * b * d + 2 * a * c;
	float m30 = 0.0f;
	float m01 = 2 * b * c + 2 * a * d;
	float m11 = pow(a, 2) - pow(b, 2) + pow(c, 2) - pow(d, 2);
	float m21 = 2 * c * d - 2 * a * b;
	float m31 = 0.0f;
	float m02 = 2 * b * d - 2 * a * c;
	float m12 = 2 * c * d + 2 * a * b;
	float m22 = pow(a, 2) - pow(b, 2) - pow(c, 2) + pow(d, 2);
	float m32 = 0.0f;
	float m03 = 0.0f;
	float m13 = 0.0f;
	float m23 = 0.0f;
	float m33 = 1.0f;
	return Mat4(m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33);
}

inline Mat3 qGetMatrix(Vec4& quat)
{
	float a = quat[0];
	float b = quat[1];
	float c = quat[2];
	float d = quat[3];
	float m00 = pow(a, 2) + pow(b, 2) - pow(c, 2) - pow(d, 2);
	float m10 = 2 * b *c - 2 * a * d;
	float m20 = 2 * b * d + 2 * a * c;
	float m01 = 2 * b * c + 2 * a * d;
	float m11 = pow(a, 2) - pow(b, 2) + pow(c, 2) - pow(d, 2);
	float m21 = 2 * c * d - 2 * a * b;
	float m02 = 2 * b * d - 2 * a * c;
	float m12 = 2 * c * d + 2 * a * b;
	float m22 = pow(a, 2) - pow(b, 2) - pow(c, 2) + pow(d, 2);
	return Mat3(m00, m10, m20, m01, m11, m21, m02, m12, m22);
}

inline Vec4 qMultiply(Vec4 q1, Vec4 q2)
{
	Vec4 retVec;

	float a1 = q1[0];
	float b1 = q1[1];
	float c1 = q1[2];
	float d1 = q1[3];

	float a2 = q2[0];
	float b2 = q2[1];
	float c2 = q2[2];
	float d2 = q2[3];

	retVec[0] = a1 * a2 - b1 * b2 - c1 * c2 - d1 * d2;
	retVec[1] = a1 * b2 + b1 * a2 + c1 * d2 - d1 * c2;
	retVec[2] = a1 * c2 - b1 * d2 + c1 * a2 + d1 * b2;
	retVec[3] = a1 * d2 + b1 * c2 - c1 * b2 + d1 * a2;
/*
	retVec[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
	retVec[1] = q1[0] * q2[1] - q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
	retVec[2] = q1[0] * q2[2] - q1[1] * q2[3] + q1[2] * q2[0] + q1[3] * q2[1];
	retVec[3] = q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1] + q1[3] * q2[0];*/
	return retVec;
}

inline Vec3 qAxisAngle(Vec4 q1)
{	
	float angle = 2 * acos(q1[0]);
	if (angle == 0.0f)
		return Vec3(0.0, 0.0, 0.0);
	Vec3 retVec(q1[1], q1[2], q1[3]);
	float length = len(retVec);
	if (length < 0.00001f)
		return Vec3(0.0, 0.0, 0.0);
	return retVec * (angle);
}

#endif

