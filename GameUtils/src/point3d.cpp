#include "point3d.hpp"
#include "vector3d.hpp"
#include "game_math.hpp"

using namespace gameutils::math;

Point3D::Point3D() : Vector3D(0.f, 0.f, 0.f) { }

Point3D::Point3D(float a, float b, float c) : Vector3D(a, b, c) { }

Point3D& Point3D::operator =(const Vector3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return (*this);
}
