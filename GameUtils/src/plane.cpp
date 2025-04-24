#include "../internal/plane.hpp"

using namespace gameutils::math;

Plane::Plane()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
}

Plane::Plane(float nx, float ny, float nz, float d)
{
	x = nx;
	y = ny;
	z = nz;
	w = d;
}

Plane::Plane(const Vector3D& n, float d)
{
	x = n.x;
	y = n.y;
	z = n.z;
	w = d;
}

const Vector3D& Plane::GetNormal(void) const
{
	return (reinterpret_cast<const Vector3D&>(x));
}
