#include "svl/Quaternion.h"

Quaternion::~Quaternion()
{

}

Mat4 Quaternion::ToMatrix()
{
	float a = elements[0];
	float b = elements[1];
	float c = elements[2];
	float d = elements[3];
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
	float m23 = 0.0;
	float m33 = 1.0f;
	return Mat4(m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33);
}
