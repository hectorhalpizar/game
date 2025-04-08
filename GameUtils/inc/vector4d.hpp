#ifndef __GAME_UTILS_VECTOR4D_HPP__
#define __GAME_UTILS_VECTOR4D_HPP__

struct Vector4D
{
	float		x, y, z, w;

	Vector4D();

	Vector4D(float a, float b, float c, float d);

	float& operator [](int i);

	const float& operator [](int i) const;

	Vector4D& operator *=(float s);

	Vector4D& operator /=(float s);

	Vector4D& operator +=(const Vector4D& v);

	Vector4D& operator -=(const Vector4D& v);
};

#endif // __GAME_UTILS_VECTOR4D_HPP__
