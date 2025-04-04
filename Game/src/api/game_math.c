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
