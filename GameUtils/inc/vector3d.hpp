#ifndef __GAME_UTILS_VECTOR3D_HPP__
#define __GAME_UTILS_VECTOR3D_HPP__

#include <math.h>

struct Vector3D
{
	float		x, y, z;

	Vector3D();

	Vector3D(float a, float b, float c);

	float& operator [](int i);

	const float& operator [](int i) const;

	Vector3D& operator *=(float s);

	Vector3D& operator /=(float s);

	Vector3D& operator +=(const Vector3D& v);

	Vector3D& operator -=(const Vector3D& v);

private:
	void init(float x, float y, float z);
};

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

#endif // __GAME_UTILS_VECTOR3D_HPP__
