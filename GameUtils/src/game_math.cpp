#include <stdio.h>
#include <stdlib.h>
#include <cfloat>

#include "game_math.hpp"

using namespace gameutils::math;

void gameutils::math::MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p)
{

	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) {
			Result[i * p + j] = 0;
		}
	}

	i = 0;
	j = 0;
	k = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) {
			for (k = 0; k < n; k++) {
				Result[i * p + j] += A[i * n + k] * B[k * p + j];
			}
		}
	}
}

// TODO: Validate edge cases and needs unit testing
void gameutils::math::TransposeArray(float *matrix, int *rows, int *cols)
{
	float *transposed = (float *)malloc((*rows) * (*cols) * sizeof(float));
	int i, j;
	int temp = *rows;

	if (!transposed) {
		printf("Error: No se pudo asignar memoria.\n");
		return;
	}

	for (i = 0; i < *rows; i++) {
		for (j = 0; j < *cols; j++) {
			transposed[j * (*rows) + i] = matrix[i * (*cols) + j];
		}
	}
    
	for (i = 0; i < (*rows) * (*cols); i++) {
		matrix[i] = transposed[i];
	}
    
	free(transposed);
    
	// Intercambiar las dimensiones
	*rows = *cols;
	*cols = temp;
}

float gameutils::math::DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v)
{
	Vector3D a = Cross(q - p, v);
	return (sqrt(Dot(a, a) / Dot(v, v)));
}

float gameutils::math::DistLineLine(const Point3D& p1, const Vector3D& v1,
				   const Point3D& p2, const Vector3D& v2)
{
	Vector3D dp = p2 - p1;

	float v12 = Dot(v1, v1);
	float v22 = Dot(v2, v2);
	float v1v2 = Dot(v1, v2);

	float det = v1v2 * v1v2 - v12 * v22;
	if (fabs(det) > FLT_MIN)
	{
		det = 1.0F / det;

		float dpv1 = Dot(dp, v1);
		float dpv2 = Dot(dp, v2);
		float t1 = (v1v2 * dpv2 - v22 * dpv1) * det;
		float t2 = (v12 * dpv2 - v1v2 * dpv1) * det;

		return (Magnitude(dp + v2 * t2 - v1 * t1));
	}

	// The lines are nearly parallel.

	Vector3D a = Cross(dp, v1);
	return (sqrt(Dot(a, a) / v12));
}

Matrix3D gameutils::math::Inverse(const Matrix3D& M)
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

Matrix3D gameutils::math::operator *(const Matrix3D& A, const Matrix3D& B)
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

Vector3D gameutils::math::operator *(const Matrix3D& M, const Vector3D& v)
{
	return (Vector3D(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
					 M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
					 M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z));
}

float gameutils::math::Determinant(const Matrix3D& M)
{
	return (M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))
		  + M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))
		  + M(0,2) * (M(1,0) * M(2,1) - M(1,1) * M(2,0)));
}

Matrix3D gameutils::math::MakeRotationX(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D(1.0F, 0.0F, 0.0F,
					 0.0F,  c,   -s,
					 0.0F,  s,    c  ));
}

Matrix3D gameutils::math::MakeRotationY(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D( c,   0.0F,  s,
					 0.0F, 1.0F, 0.0F,
					 -s,   0.0F,  c  ));
}


Matrix3D gameutils::math::MakeRotationZ(float t)
{
	float c = cos(t);
	float s = sin(t);

	return (Matrix3D( c,   -s,   0.0F,
					  s,    c,   0.0F,
					 0.0F, 0.0F, 1.0F));
}

Matrix3D gameutils::math::MakeRotation(float t, const Vector3D& a)
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

Matrix3D gameutils::math::MakeReflection(const Vector3D& a)
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

Matrix3D gameutils::math::MakeInvolution(const Vector3D& a)
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

Matrix3D gameutils::math::MakeScale(float sx, float sy, float sz)
{
	return (Matrix3D(sx, 0.0F, 0.0F, 0.0F, sy, 0.0F, 0.0F, 0.0F, sz));
}

Matrix3D gameutils::math::MakeScale(float s, const Vector3D& a)
{
	s -= 1.0F;
	float x = a.x * s;
	float y = a.y * s;
	float z = a.z * s;
	float axay = x * a.y;
	float axaz = x * a.z;
	float ayaz = y * a.z;

	return (Matrix3D(x * a.x + 1.0F, axay, axaz,
					 axay, y * a.y + 1.0F, ayaz,
					 axaz, ayaz, z * a.z + 1.0F));
}

Matrix3D gameutils::math::MakeSkew(float t, const Vector3D& a, const Vector3D& b)
{
	t = tan(t);
	float x = a.x * t;
	float y = a.y * t;
	float z = a.z * t;

	return (Matrix3D(x * b.x + 1.0F, x * b.y, x * b.z,
					 y * b.x, y * b.y + 1.0F, y * b.z,
					 z * b.x, z * b.y, z * b.z + 1.0F));
}

Matrix4D gameutils::math::Inverse(const Matrix4D& M)
{
	const Vector3D& a = reinterpret_cast<const Vector3D&>(M[0]);
	const Vector3D& b = reinterpret_cast<const Vector3D&>(M[1]);
	const Vector3D& c = reinterpret_cast<const Vector3D&>(M[2]);
	const Vector3D& d = reinterpret_cast<const Vector3D&>(M[3]);

	const float& x = M(3,0);
	const float& y = M(3,1);
	const float& z = M(3,2);
	const float& w = M(3,3);

	Vector3D s = Cross(a, b);
	Vector3D t = Cross(c, d);
	Vector3D u = a * y - b * x;
	Vector3D v = c * w - d * z;

	float invDet = 1.0F / (Dot(s, v) + Dot(t, u));
	s *= invDet;
	t *= invDet;
	u *= invDet;
	v *= invDet;

	Vector3D r0 = Cross(b, v) + t * y;
	Vector3D r1 = Cross(v, a) - t * x;
	Vector3D r2 = Cross(d, u) + s * w;
	Vector3D r3 = Cross(u, c) - s * z;

	return (Matrix4D(r0.x, r0.y, r0.z, -Dot(b, t),
					 r1.x, r1.y, r1.z,  Dot(a, t),
					 r2.x, r2.y, r2.z, -Dot(d, s),
					 r3.x, r3.y, r3.z,  Dot(c, s)));
}

Transform4D gameutils::math::Inverse(const Transform4D& H)
{
	const Vector3D& a = H[0];
	const Vector3D& b = H[1];
	const Vector3D& c = H[2];
	const Vector3D& d = H[3];

	Vector3D s = Cross(a, b);
	Vector3D t = Cross(c, d);

	float invDet = 1.0F / Dot(s, c);

	s *= invDet;
	t *= invDet;
	Vector3D v = c * invDet;

	Vector3D r0 = Cross(b, v);
	Vector3D r1 = Cross(v, a);

	return (Transform4D(r0.x, r0.y, r0.z, -Dot(b, t),
						r1.x, r1.y, r1.z,  Dot(a, t),
						 s.x,  s.y,  s.z, -Dot(d, s)));
}

Transform4D gameutils::math::operator *(const Transform4D& A, const Transform4D& B)
{
	return (Transform4D(
		A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
		A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
		A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
		A(0,0) * B(0,3) + A(0,1) * B(1,3) + A(0,2) * B(2,3) + A(0,3),
		A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
		A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
		A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
		A(1,0) * B(0,3) + A(1,1) * B(1,3) + A(1,2) * B(2,3) + A(1,3),
		A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
		A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
		A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2),
		A(2,0) * B(0,3) + A(2,1) * B(1,3) + A(2,2) * B(2,3) + A(2,3)));
}

Vector3D gameutils::math::operator *(const Transform4D& H, const Vector3D& v)
{
	return (Vector3D(H(0,0) * v.x + H(0,1) * v.y + H(0,2) * v.z,
					 H(1,0) * v.x + H(1,1) * v.y + H(1,2) * v.z,
					 H(2,0) * v.x + H(2,1) * v.y + H(2,2) * v.z));
}

Point3D gameutils::math::operator *(const Transform4D& H, const Point3D& p)
{
	return (Point3D(H(0,0) * p.x + H(0,1) * p.y + H(0,2) * p.z + H(0,3),
					H(1,0) * p.x + H(1,1) * p.y + H(1,2) * p.z + H(1,3),
					H(2,0) * p.x + H(2,1) * p.y + H(2,2) * p.z + H(2,3)));
}

Vector3D gameutils::math::operator *(const Vector3D& n, const Transform4D& H)
{
	return (Vector3D(n.x * H(0,0) + n.y * H(1,0) + n.z * H(2,0),
					 n.x * H(0,1) + n.y * H(1,1) + n.z * H(2,1),
					 n.x * H(0,2) + n.y * H(1,2) + n.z * H(2,2)));
}

Quaternion gameutils::math::operator *(const Quaternion& q1, const Quaternion& q2)
{
	return (Quaternion(
		q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
		q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
		q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
		q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z));
}

Vector3D gameutils::math::Transform(const Vector3D& v, const Quaternion& q)
{
	const Vector3D& b = q.GetVectorPart();
	float b2 = b.x * b.x + b.y * b.y + b.z * b.z;
	return (v * (q.w * q.w - b2) + b * (Dot(v, b) * 2.0F)
		+ Cross(b, v) * (q.w * 2.0F));
}

float gameutils::math::Dot(const Plane& f, const Vector3D& v)
{
	return (f.x * v.x + f.y * v.y + f.z * v.z);
}

float gameutils::math::Dot(const Plane& f, const Point3D& p)
{
	return (f.x * p.x + f.y * p.y + f.z * p.z + f.w);
}

Transform4D gameutils::math::MakeReflection(const Plane& f)
{
	float x = f.x * -2.0F;
	float y = f.y * -2.0F;
	float z = f.z * -2.0F;
	float nxny = x * f.y;
	float nxnz = x * f.z;
	float nynz = y * f.z;

	return (Transform4D(x * f.x + 1.0F, nxny, nxnz, x * f.w,
						nxny, y * f.y + 1.0F, nynz, y * f.w,
						nxnz, nynz, z * f.z + 1.0F, z * f.w));
}

bool gameutils::math::IntersectLinePlane(const Point3D& p, const Vector3D& v,
						const Plane& f, Point3D *q)
{
	float fv = Dot(f, v);
	if (fabs(fv) > FLT_MIN)
	{
		*q = p - v * (Dot(f, p) / fv);
		return (true);
	}

	return (false);
}

bool gameutils::math::IntersectThreePlanes(const Plane& f1, const Plane& f2,
						  const Plane& f3, Point3D *p)
{
	const Vector3D& n1 = f1.GetNormal();
	const Vector3D& n2 = f2.GetNormal();
	const Vector3D& n3 = f3.GetNormal();

	Vector3D n1xn2 = Cross(n1, n2);
	float det = Dot(n1xn2, n3);
	if (fabs(det) > FLT_MIN)
	{
		*p = (Cross(n3, n2) * f1.w + Cross(n1, n3) * f2.w
				- n1xn2 * f3.w) / det;
		return (true);
	}

	return (false);
}

bool gameutils::math::IntersectTwoPlanes(const Plane& f1, const Plane& f2,
						Point3D *p, Vector3D *v)
{
	const Vector3D& n1 = f1.GetNormal();
	const Vector3D& n2 = f2.GetNormal();

	*v = Cross(n1, n2);
	float det = Dot(*v, *v);
	if (fabs(det) > FLT_MIN)
	{
		*p = (Cross(*v, n2) * f1.w + Cross(n1, *v) * f2.w) / det;
		return (true);
	}

	return (false);
}

Plane gameutils::math::operator *(const Plane& f, const Transform4D& H)
{
	return (Plane(f.x * H(0,0) + f.y * H(1,0) + f.z * H(2,0),
				  f.x * H(0,1) + f.y * H(1,1) + f.z * H(2,1),
				  f.x * H(0,2) + f.y * H(1,2) + f.z * H(2,2),
				  f.x * H(0,3) + f.y * H(1,3) + f.z * H(2,3) + f.w));
}

Line gameutils::math::Transform(const Line& line, const Transform4D& H)
{
	Matrix3D adj(Cross(H[1], H[2]), Cross(H[2], H[0]), Cross(H[0], H[1]));
	const Point3D& t = H.GetTranslation();

	Vector3D v = H * line.direction;
	Vector3D m = adj * line.moment + Cross(t, v);
	return (Line(v, m));
}

