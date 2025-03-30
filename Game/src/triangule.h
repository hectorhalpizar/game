#ifndef __GAME_TRIANGULE_H__
#define __GAME_TRIANGULE_H__

#include <stdlib.h>
#include "esUtil.h"

typedef struct
{
	// Handle to a program object
	GLuint programObject;

} UserData;

///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint LoadShader(GLenum type, const char *shaderSrc);

///
// Initialize the shader and program object
//
int Init(ESContext *esContext);

///
// Draw a triangle using the shader pair created in Init()
//
void Draw(ESContext *esContext);

///
// Starts game triangule logic
//
int GameTriangle(int argc, char *argv[]);


#endif //  __GAME_TRIANGULE_H__