#include "../internal/matrix4d.hpp"
#include "../internal/vector4d.hpp"
#include "../internal/vector3d.hpp"
#include "game_math.hpp"

using namespace gameutils::math;

Matrix4D::Matrix4D()
{
	init(0.f, 0.f, 0.f, 0.f,
		 0.f, 0.f, 0.f, 0.f,
		 0.f, 0.f, 0.f, 0.f,
		 0.f, 0.f, 0.f, 0.f);
}

Matrix4D::Matrix4D(float n00, float n01, float n02, float n03,
		 float n10, float n11, float n12, float n13,
		 float n20, float n21, float n22, float n23,
		 float n30, float n31, float n32, float n33)
{
	init(n00, n01, n02, n03,
		 n10, n11, n12, n13,
		 n20, n21, n22, n23,
		 n30, n31, n32, n33);
}

///
// This matrix is set a Column-Major
// 
// Result of the a Vector Matrix with input
// const Matrix3D testInstance = Matrix3D(Vector4D( 1.f,  2.f,  3.f,  4.f),
//      								  Vector4D( 5.f,  6.f,  7.f,  8.f),
//										  Vector4D( 9.f, 10.f, 11.f, 12.f),
//										  Vector4D(13.f, 14.f, 15.f, 16.f));
//
// will be:
//
//		[1, 5,  9, 13]
//		[2, 6, 10, 14]
//		[3, 7, 11, 15]
//		[4, 8, 12, 16]

Matrix4D::Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d)
{
	init(a.x, b.x, c.x, d.x,
         a.y, b.y, c.y, d.y,
	     a.z, b.z, c.z, d.z,
		 a.w, b.w, c.w, d.w);
}

float& Matrix4D::operator ()(int i, int j)
{
	return (n[j][i]);
}

const float& Matrix4D::operator ()(int i, int j) const
{
	return (n[j][i]);
}

Vector4D& Matrix4D::operator [](int j)
{
	return (*reinterpret_cast<Vector4D *>(n[j]));
}

const Vector4D& Matrix4D::operator [](int j) const
{
	return (*reinterpret_cast<const Vector4D *>(n[j]));
}

void Matrix4D::init(float n00, float n01, float n02, float n03,
		            float n10, float n11, float n12, float n13,
		            float n20, float n21, float n22, float n23,
				    float n30, float n31, float n32, float n33)
{
	n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
	n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
	n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
	n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
}
