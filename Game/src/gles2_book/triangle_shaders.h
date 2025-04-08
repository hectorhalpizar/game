#ifndef __GAME_TRIANGULE_SHADERS_H__ 
#define __GAME_TRIANGULE_SHADERS_H__ 

#include "esUtil.h"

///
// This vertex shader just passes the every vertex position 
// from the C code to gl_position to processed for each of 
// its 3 vertex.
GLbyte* getTriangleVertexShader()
{
	return
		"attribute vec4 vPosition;    \n"
		"void main()                  \n"
		"{                            \n"
		"   gl_Position = vPosition;  \n"
		"}                            \n";
};

///
// This fragment shader processes the color red with the maximium 
// alpha (RGBA = FF0000FF) for each vertex as hardcoded value.
// 
GLbyte* getTriangleFragmentShader()
{
	return
		"precision mediump float;\n"\
		"void main()                                  \n"
		"{                                            \n"
		"  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
		"}                                            \n";
};

#endif // __GAME_TRIANGULE_SHADERS_H__ 