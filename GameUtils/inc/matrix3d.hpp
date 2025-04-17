#ifndef __GAME_UTILS_MATRIX3D_HPP__
#define __GAME_UTILS_MATRIX3D_HPP__

#include "vector3d.hpp"

struct Matrix3D
{
	private:

		float		n[3][3];

	public:

		Matrix3D();

		Matrix3D(float n00, float n01, float n02,
		         float n10, float n11, float n12,
		         float n20, float n21, float n22);

		Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

		float& operator ()(int i, int j);

		const float& operator ()(int i, int j) const;

		Vector3D& operator [](int j);

		const Vector3D& operator [](int j) const;

	private:
		void init(float n00, float n01, float n02,
		     float n10, float n11, float n12,
		     float n20, float n21, float n22);

};

#endif // __GAME_UTILS_MATRIX3D_HPP__