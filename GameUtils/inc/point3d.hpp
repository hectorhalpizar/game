#ifndef __GAME_UTILS_POINT3D_HPP__
#define __GAME_UTILS_POINT3D_HPP__

#include "vector3d.hpp"

struct Point3D : public Vector3D
{
	Point3D();

	Point3D(float a, float b, float c);

	Point3D& operator =(const Vector3D& v);
};

float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v);

float DistLineLine(const Point3D& p1, const Vector3D& v1,
                   const Point3D& p2, const Vector3D& v2);

inline Point3D operator +(const Point3D& a, const Vector3D& b)
{
	return (Point3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Point3D operator -(const Point3D& a, const Vector3D& b)
{
	return (Point3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator -(const Point3D& a, const Point3D& b)
{
	return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

#endif // __GAME_UTILS_POINT3D_HPP__