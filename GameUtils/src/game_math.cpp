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
