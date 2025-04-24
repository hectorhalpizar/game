#include "../internal/vector3d.hpp"

#include <stdio.h>

using namespace gameutils::math;

Vector3D::Vector3D(){
	// Default values
	init(0.f, 0.f, 0.f);
};

Vector3D::Vector3D(float x, float y, float z)
{
	init(x, y, z);
}

void Vector3D::init(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


float& Vector3D::operator [](int i)
{
	return ((&x)[i]);
}

const float& Vector3D::operator [](int i) const
{
	return ((&x)[i]);
}

Vector3D& Vector3D::operator *=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}

Vector3D& Vector3D::operator /=(float s)
{
	s = 1.0F / s;
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}

Vector3D& Vector3D::operator +=(const Vector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return (*this);
}

Vector3D& Vector3D::operator -=(const Vector3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return (*this);
}
