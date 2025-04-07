#include "game_math.h"

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
