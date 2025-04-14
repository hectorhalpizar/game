#ifndef __GAME_UTILS_MATRIX4D_HPP__
#define __GAME_UTILS_MATRIX4D_HPP__

#include "vector4d.hpp"

struct Matrix4D
{
	protected:

		float		n[4][4];

	public:

		Matrix4D();

		Matrix4D(float n00, float n01, float n02, float n03,
		         float n10, float n11, float n12, float n13,
		         float n20, float n21, float n22, float n23,
				 float n30, float n31, float n32, float n33);

		Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d);

		float& operator ()(int i, int j);

		const float& operator ()(int i, int j) const;

		Vector4D& operator [](int j);

		const Vector4D& operator [](int j) const;
	
	private:
		void init(float n00, float n01, float n02, float n03,
		          float n10, float n11, float n12, float n13,
		          float n20, float n21, float n22, float n23,
				  float n30, float n31, float n32, float n33);
};

#endif // __GAME_UTILS_MATRIX4D_HPP__