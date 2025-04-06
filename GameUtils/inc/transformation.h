#ifndef __GAME_UTILS_TRANSFORMATION_SCALE_H__

#ifdef __cplusplus
extern "C" {
#endif

void translateColumnMajor
(
 	float *matrixVector,
	float x, 
	float y, 
	float z
);

void translateRowMajor
(
 	float *matrixVector,
	float x, 
	float y, 
	float z
);

#ifdef __cplusplus
}
#endif

#endif // __GAME_UTILS_TRANSFORMATION_H__
