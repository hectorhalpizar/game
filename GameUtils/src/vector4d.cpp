#include "vector4d.hpp"

Vector4D::Vector4D() {
	init(0.f, 0.f, 0.f, 0.f);
};

Vector4D::Vector4D(float x, float y, float z, float w)
{
	init(x, y, z, w);
}

float& Vector4D::operator [](int i)
{
	return ((&x)[i]);
}

const float& Vector4D::operator [](int i) const
{
	return ((&x)[i]);
}

Vector4D& Vector4D::operator *=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return (*this);
}

Vector4D& Vector4D::operator /=(float s)
{
	s = 1.0F / s;
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return (*this);
}

Vector4D& Vector4D::operator +=(const Vector4D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return (*this);
}

Vector4D& Vector4D::operator -=(const Vector4D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return (*this);
}

void Vector4D::init(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}


