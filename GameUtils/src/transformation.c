#include <math.h>

#include "transformation.h"

void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p);

void rotateOnXRowMajor
(
 	float *matrixVector,
	float radians
);

void rotateOnXColumnMajor
(
 	float *matrixVector,
	float radians
);

void rotateOnYRowMajor
(
  	float *matrixVector,
	float radians
);

void rotateOnYColumnMajor
(
	float *matrixVector,
	float radians
);

void rotateOnZRowMajor
(
	float *matrixVector,
	float radians
);

void rotateOnZColumnMajor
(
	float *matrixVector,
	float radianOnZAxis
);

void scaleCommon
(
	float *matrixVector,
	float x, 
	float y, 
	float z
);

void translateColumnMajor
(
	float *matrixVector,
	float x, 
	float y, 
	float z
)
{
	matrixVector[0]  = 1.f; matrixVector[1] = 0.f; matrixVector[2]  = 0.f; matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f; matrixVector[5] = 1.f; matrixVector[6]  = 0.f; matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f; matrixVector[9] = 0.f; matrixVector[10] = 1.f; matrixVector[11] = 0.f;

	// ********************************
	// Column Major Translate position
	// ********************************
	matrixVector[12] =   x; matrixVector[13] =  y; matrixVector[14] =   z; matrixVector[15] = 1.f;
}

void translateRowMajor
(
	float *matrixVector,
	float x, 
	float y,
	float z
)
{
	// ************************************************************	[ Row Major Translate position ]
	matrixVector[0]  = 1.f; matrixVector[1]  = 0.f; matrixVector[2]  = 0.f; matrixVector[3]  = x;
	matrixVector[4]  = 0.f; matrixVector[5]  = 1.f; matrixVector[6]  = 0.f; matrixVector[7]  = y;
	matrixVector[8]  = 0.f; matrixVector[9]  = 0.f; matrixVector[10] = 1.f; matrixVector[11] = z;
	matrixVector[12] = 0.f; matrixVector[13] = 0.f; matrixVector[14] = 0.f; matrixVector[15] = 1.f;
}

void rotateRowMajor
(
	float *matrixVector,
	float radiansX,
	float radiansY,
	float radiansZ
)
{
	float RotationMatrixDeltaZY[16];
	float RotationZ[16];
	float RotationY[16];
	float RotationX[16];

	rotateOnXRowMajor(RotationX, radiansX);
	rotateOnYRowMajor(RotationY, radiansY);
	rotateOnZRowMajor(RotationZ, radiansZ);

	MultiplyMatrixAsArray(RotationZ, RotationY, RotationMatrixDeltaZY, 4, 4, 4);
	MultiplyMatrixAsArray(RotationMatrixDeltaZY, RotationX, matrixVector, 4, 4, 4);
}

void rotateColumnMajor
(
	float *matrixVector,
	float radiansX,
	float radiansY,
	float radiansZ
)
{
	float RotationMatrixDeltaZY[16];
	float RotationZ[16];
	float RotationY[16];
	float RotationX[16];

	rotateOnXColumnMajor(RotationX, radiansX);
	rotateOnYColumnMajor(RotationY, radiansY);
	rotateOnZColumnMajor(RotationZ, radiansZ);

	MultiplyMatrixAsArray(RotationZ, RotationY, RotationMatrixDeltaZY, 4, 4, 4);
	MultiplyMatrixAsArray(RotationMatrixDeltaZY, RotationX, matrixVector, 4, 4, 4);
}

void rotateOnXRowMajor
(
	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = 1.f; matrixVector[1]  = 0.f;			  matrixVector[2]  = 0.f;			 matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f; matrixVector[5]  = cosf(radians); matrixVector[6]  = -sinf(radians); matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f; matrixVector[9]  = sinf(radians); matrixVector[10] = cosf(radians);  matrixVector[11] = 0.f;
	matrixVector[12] = 0.f; matrixVector[13] = 0.f;			  matrixVector[14] = 0.f;			 matrixVector[15] = 1.f;
}

void rotateOnXColumnMajor
(
	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = 1.f; matrixVector[1]  = 0.f;			   matrixVector[2]  = 0.f;			 matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f; matrixVector[5]  = cosf(radians);  matrixVector[6]  = sinf(radians); matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f; matrixVector[9]  = -sinf(radians); matrixVector[10] = cosf(radians); matrixVector[11] = 0.f;
	matrixVector[12] = 0.f; matrixVector[13] = 0.f;			   matrixVector[14] = 0.f;			 matrixVector[15] = 1.f;
}

void rotateOnYRowMajor
(
  	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = cosf(radians); matrixVector[1]  = 0.f; matrixVector[2]  = -sinf(radians); matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f;			  matrixVector[5]  = 1.f; matrixVector[6]  = 0.f;			 matrixVector[7]  = 0.f;
	matrixVector[8]  = sinf(radians); matrixVector[9]  = 0.f; matrixVector[10] = cosf(radians);  matrixVector[11] = 0.f;
	matrixVector[12] = 0.f;			  matrixVector[13] = 0.f; matrixVector[14] = 0.f;			 matrixVector[15] = 1.f;
}

void rotateOnYColumnMajor
(
	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = cosf(radians);  matrixVector[1]  = 0.f; matrixVector[2]  = sinf(radians); matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f;			   matrixVector[5]  = 1.f; matrixVector[6]  = 0.f;			 matrixVector[7]  = 0.f;
	matrixVector[8]  = -sinf(radians); matrixVector[9]  = 0.f; matrixVector[10] = cosf(radians); matrixVector[11] = 0.f;
	matrixVector[12] = 0.f;			   matrixVector[13] = 0.f; matrixVector[14] = 0.f;			 matrixVector[15] = 1.f;
}

void rotateOnZRowMajor
(
 	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = cosf(radians); matrixVector[1]  = -sinf(radians); matrixVector[2]  = 0.f; matrixVector[3]  = 0.f;
	matrixVector[4]  = sinf(radians); matrixVector[5]  = cosf(radians);	 matrixVector[6]  = 0.f; matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f;			  matrixVector[9]  = 0.f;			 matrixVector[10] = 1.f; matrixVector[11] = 0.f;
	matrixVector[12] = 0.f;			  matrixVector[13] = 0.f;			 matrixVector[14] = 0.f; matrixVector[15] = 1.f;
}

void rotateOnZColumnMajor
(
 	float *matrixVector,
	float radians
)
{
	matrixVector[0]  = cosf(radians);  matrixVector[1]  = sinf(radians); matrixVector[2]  = 0.f; matrixVector[3]  = 0.f;
	matrixVector[4]  = -sinf(radians); matrixVector[5]  = cosf(radians); matrixVector[6]  = 0.f; matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f;			   matrixVector[9]  = 0.f;			 matrixVector[10] = 1.f; matrixVector[11] = 0.f;
	matrixVector[12] = 0.f;			   matrixVector[13] = 0.f;			 matrixVector[14] = 0.f; matrixVector[15] = 1.f;
}

void scaleRowMajor
(
	float *matrixVector,
	float x, 
	float y, 
	float z
)
{
	scaleCommon(matrixVector, x, y, z);
}

void scaleColumnMajor
(
	float *matrixVector,
	float x, 
	float y, 
	float z
)
{
	scaleCommon(matrixVector, x, y, z);
}

void scaleCommon
(
	float *matrixVector,
	float x, 
	float y, 
	float z
)
{
	matrixVector[0]  =   x; matrixVector[1]  = 0.f; matrixVector[2]  = 0.f; matrixVector[3]  = 0.f;
	matrixVector[4]  = 0.f; matrixVector[5]  =   y; matrixVector[6]  = 0.f; matrixVector[7]  = 0.f;
	matrixVector[8]  = 0.f; matrixVector[9]  = 0.f; matrixVector[10] =   z; matrixVector[11] = 0.f;
	matrixVector[12] = 0.f; matrixVector[13] = 0.f; matrixVector[14] = 0.f; matrixVector[15] = 1.f;
}

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