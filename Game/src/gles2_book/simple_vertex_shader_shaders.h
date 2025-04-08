#ifndef __GAME_SIMPLE_VERTEX_SHADER_SHADERS_H__
#define __GAME_SIMPLE_VERTEX_SHADER_SHADERS_H__

#include "esUtil.h"

///
// This vertex shader processes the Model-View-Projection
// provided loaded on the DrawSimpleVertexShader method and is
// multiplied by vertex position provided on the SimpleVertexProgram.
GLbyte * getSimpleVertexShaderVertexShader()
{
	return      
		"uniform mat4 u_mvpMatrix;                   \n"
		"attribute vec4 a_position;                  \n"
		"void main()                                 \n"
		"{                                           \n"
		"   gl_Position = u_mvpMatrix * a_position;  \n"
		"}                                           \n";
}

///
// This fragment shader processes the color red with the maximium 
// alpha (RGBA = FF0000FF) for each vertex as hardcoded value.
// 
GLbyte * getSimpleVertexShaderFragmentShader()
{
	return
		"precision mediump float;                            \n"
		"void main()                                         \n"
		"{                                                   \n"
		"  gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0 );        \n"
		"}                                                   \n";
}

#endif // __GAME_SIMPLE_VERTEX_SHADER_SHADERS_H__