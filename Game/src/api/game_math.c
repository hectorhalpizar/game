#include "game_math.h"

#include <stdlib.h>
#include <esUtil.h>

// TODO: Validate edge cases and needs unit testing
void TransposeArray(float *matrix, int *rows, int *cols)
{
    float *transposed = (float *)malloc((*rows) * (*cols) * sizeof(float));
	int i, j;
	int temp = *rows;

    if (!transposed) {
        esLogMessage("Error: No se pudo asignar memoria.\n");
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

// TODO: Rename the parameters
void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p) {

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