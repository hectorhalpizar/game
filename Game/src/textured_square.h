#ifndef __GAME_TEXTURED_SQUARE_H__
#define __GAME_TEXTURED_SQUARE_H__

#include <stdlib.h>
#include "esUtil.h"

#define START_GAME_TEXTURED_SQUARE "GameTexturedTriangle"

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  texCoordLoc;

   // Sampler location
   GLint samplerLoc;

   // Texture handle
   GLuint textureId;

} TexturedSquareUserData;

///
// Create a simple 2x2 texture image with four different colors
//
GLuint TexturedSquareCreateSimpleTexture2D();

///
// Initialize the shader and program object
//
int TexturedSquareInit(ESContext *esContext);

///
// Draw a triangle using the shader pair created in Init()
//
void TexturedSquareDraw(ESContext *esContext);

///
// Cleanup
//
void TexturedSquareShutDown(ESContext *esContext);

int StartTexturedSquare(int argc, char *argv[]);

#endif // __GAME_TEXTURED_SQUARE_H__