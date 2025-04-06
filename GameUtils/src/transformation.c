#include "transformation.h"

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

