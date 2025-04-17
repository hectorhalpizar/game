#include <stdio.h>
#include <stdlib.h>
#include <cfloat>

#include "game_math.hpp"

void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p)
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
void TransposeArray(float *matrix, int *rows, int *cols)
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


float DistPointLine(const Point3D& q, const Point3D& p, const Vector3D& v)
{
	Vector3D a = Cross(q - p, v);
	return (sqrt(Dot(a, a) / Dot(v, v)));
}

float DistLineLine(const Point3D& p1, const Vector3D& v1,
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

Matrix3D MakeScale(float sx, float sy, float sz)
{
	return (Matrix3D(sx, 0.0F, 0.0F, 0.0F, sy, 0.0F, 0.0F, 0.0F, sz));
}

Matrix3D MakeScale(float s, const Vector3D& a)
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

Matrix3D MakeSkew(float t, const Vector3D& a, const Vector3D& b)
{
	t = tan(t);
	float x = a.x * t;
	float y = a.y * t;
	float z = a.z * t;

	return (Matrix3D(x * b.x + 1.0F, x * b.y, x * b.z,
	                 y * b.x, y * b.y + 1.0F, y * b.z,
	                 z * b.x, z * b.y, z * b.z + 1.0F));
}
