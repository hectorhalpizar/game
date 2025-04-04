#ifndef __GAME_API_MATH_H__
#define __GAME_API_MATH_H__

#ifdef __cplusplus
extern "C" { 
#endif

#include <esUtil.h>

void TransposeArray(float *matrix, int *rows, int *cols);

void MultiplyMatrixAsArray(float *A, float *B, float *Result, int m, int n, int p);

#ifdef __cplusplus
} 
#endif

#endif // __GAME_API_MATH_H__