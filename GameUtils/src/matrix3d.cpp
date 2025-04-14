#include "matrix3d.hpp"

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

float& Matrix3D::operator ()(int i, int j)
{
	return (n[j][i]);
}

const float& Matrix3D::operator ()(int i, int j) const
{
	return (n[j][i]);
}

Vector3D& Matrix3D::operator [](int j)
{
	return (*reinterpret_cast<Vector3D *>(n[j]));
}

const Vector3D& Matrix3D::operator [](int j) const
{
	return (*reinterpret_cast<const Vector3D *>(n[j]));
}

void Matrix3D::init(float n00, float n01, float n02,
		            float n10, float n11, float n12,
		            float n20, float n21, float n22)
{
	n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
	n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
	n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
}

Matrix3D Inverse(const Matrix3D& M)
{
	const Vector3D& a = M[0];
	const Vector3D& b = M[1];
	const Vector3D& c = M[2];

	Vector3D r0 = Cross(b, c);
	Vector3D r1 = Cross(c, a);
	Vector3D r2 = Cross(a, b);

	float invDet = 1.0F / Dot(r2, c);

	return (Matrix3D(r0.x * invDet, r0.y * invDet, r0.z * invDet,
	                 r1.x * invDet, r1.y * invDet, r1.z * invDet,
	                 r2.x * invDet, r2.y * invDet, r2.z * invDet));
}

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
	return (Matrix3D(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
	                 A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
	                 A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
	                 A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
	                 A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
	                 A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
	                 A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
	                 A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
	                 A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)));
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v)
{
	return (Vector3D(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
	                 M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
	                 M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z));
}

float Determinant(const Matrix3D& M)
{
	return (M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))
	      + M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))
	      + M(0,2) * (M(1,0) * M(2,1) - M(1,1) * M(2,0)));
}

Matrix3D MakeRotationX(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D(1.0F, 0.0F, 0.0F,
	                 0.0F,  c,   -s,
	                 0.0F,  s,    c  ));
}

Matrix3D MakeRotationY(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D( c,   0.0F,  s,
	                 0.0F, 1.0F, 0.0F,
	                 -s,   0.0F,  c  ));
}


Matrix3D MakeRotationZ(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D( c,   -s,   0.0F,
	                  s,    c,   0.0F,
	                 0.0F, 0.0F, 1.0F));
}

Matrix3D MakeRotation(float t, const Vector3D& a)
{
	float c = cos(t);
	float s = sin(t);
	float d = 1.0F - c;

	float x = a.x * d;
	float y = a.y * d;
	float z = a.z * d;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(c + x * a.x, axay - s * a.z, axaz + s * a.y,
	                 axay + s * a.z, c + y * a.y, ayaz - s * a.x,
	                 axaz - s * a.y, ayaz + s * a.x, c + z * a.z));
}

Matrix3D MakeReflection(const Vector3D& a)
{
	float x = a.x * -2.0F;
	float y = a.y * -2.0F;
	float z = a.z * -2.0F;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x + 1.0F, axay, axaz,
	                 axay, y * a.y + 1.0F, ayaz,
	                 axaz, ayaz, z * a.z + 1.0F));
}

Matrix3D MakeInvolution(const Vector3D& a)
{
	float x = a.x * 2.0F;
	float y = a.y * 2.0F;
	float z = a.z * 2.0F;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x - 1.0F, axay, axaz,
	                 axay, y * a.y - 1.0F, ayaz,
	                 axaz, ayaz, z * a.z - 1.0F));
}
