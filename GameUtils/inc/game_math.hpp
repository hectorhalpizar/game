#ifndef __GAME_UTILS_MATH_H__
#define __GAME_UTILS_MATH_H__

#include "vector3d.hpp"

void TransposeArray(float *matrix, int *rows, int *cols);

void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p);

inline Vector3D operator /(const Vector3D& v, float s)
{
	s = 1.0F / s;
	return (Vector3D(v.x * s, v.y * s, v.z * s));
};

inline Vector3D operator *(const Vector3D& v, float s)
{
	return (Vector3D(v.x * s, v.y * s, v.z * s));
};

inline float Magnitude(const Vector3D& v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
	return (v / Magnitude(v));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float Dot(const Vector3D& a, const Vector3D& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
{
	return (Vector3D(a.y * b.z - a.z * b.y,
	                 a.z * b.x - a.x * b.z,
	                 a.x * b.y - a.y * b.x));
}

inline Vector3D Project(const Vector3D& a, const Vector3D& b)
{
	return (b * (Dot(a, b) / Dot(b, b)));
}

inline Vector3D Reject(const Vector3D& a, const Vector3D& b)
{
	return (a - b * (Dot(a, b) / Dot(b, b)));
}

#endif // __GAME_UTILS_MATH_H__