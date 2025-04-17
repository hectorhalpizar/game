#include "matrix3d.hpp"
#include "game_math.hpp"

Matrix3D::Matrix3D() {
	init(0.f, 0.f, 0.f,
         0.f, 0.f, 0.f,
		 0.f, 0.f, 0.f);
};

Matrix3D::Matrix3D(float n00, float n01, float n02,
         float n10, float n11, float n12,
         float n20, float n21, float n22)
{
	init(n00, n01, n02,
         n10, n11, n12,
		 n20, n21, n22);
}

///
// This matrix is set a Column-Major
// 
// Result of the a Vector Matrix with input
// const Matrix3D testInstance = Matrix3D(Vector3D(1.f, 2.f, 3.f),
//      								  Vector3D(4.f, 5.f, 6.f),
//										  Vector3D(7.f, 8.f, 9.f));
//
// will be:
//
//		[1, 4, 7]
//		[2, 5, 8]
//		[3, 6, 9]

Matrix3D::Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
	init(a.x, b.x, c.x,
         a.y, b.y, c.y,
	     a.z, b.z, c.z);
}
