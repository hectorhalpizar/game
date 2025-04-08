#include <stdlib.h>
#include "esUtil.h"
#include "textured_square.h"
#include "textured_square_shaders.h"
#include "../config.h"

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

GLuint TexturedSquareCreateSimpleTexture2D()
{
   // Texture object handle
   GLuint textureId;
   
   // 2x2 Image, 3 bytes per pixel (R, G, B)
   GLubyte pixels[4 * 3] =
   {  
      255,   0,   0, // Red
        0, 255,   0, // Green
        0,   0, 255, // Blue
      255, 255,   0  // Yellow
   };

   // Use tightly packed data
   glPixelStorei( GL_UNPACK_ALIGNMENT, 1);

   // Generate a texture object
   glGenTextures(1, &textureId);

   // Bind the texture object
   glBindTexture(GL_TEXTURE_2D, textureId);

   // Load the texture
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

   // Set the filtering mode
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   return textureId;
}

///
// Create a simple 2x2 texture image with four different colors
//
int TexturedSquareInit(ESContext *esContext)
{
   TexturedSquareUserData *userData = esContext->userData;
   GLbyte *vShaderStr = TexturedSquareVertexShader();
   
   GLbyte *fShaderStr = TexturedSquareFragmentShader();

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram(vShaderStr, fShaderStr);

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation(userData->programObject, "a_position");
   userData->texCoordLoc = glGetAttribLocation(userData->programObject, "a_texCoord");
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation(userData->programObject, "s_texture");

   // Load the texture
   userData->textureId = TexturedSquareCreateSimpleTexture2D();

   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void TexturedSquareDraw(ESContext *esContext)
{
   TexturedSquareUserData *userData = esContext->userData;
   GLfloat vVertices[] = { -0.5f,  0.5f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.5f, -0.5f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.5f, -0.5f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.5f,  0.5f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };
      
   // Set the viewport
   glViewport(0, 0, esContext->width, esContext->height);
   
   // Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   // Use the program object
   glUseProgram(userData->programObject);

   // Load the vertex position
   glVertexAttribPointer(userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices);
   // Load the texture coordinate
   glVertexAttribPointer(userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3]);

   glEnableVertexAttribArray(userData->positionLoc);
   glEnableVertexAttribArray(userData->texCoordLoc);

   // Bind the texture
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, userData->textureId);

   // Set the sampler texture unit to 0
   glUniform1i(userData->samplerLoc, 0);

   glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices);

   eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

///
// Cleanup
//
void TexturedSquareShutDown(ESContext *esContext)
{
   TexturedSquareUserData *userData = esContext->userData;

   // Delete texture object
   glDeleteTextures(1, &userData->textureId);

   // Delete program object
   glDeleteProgram(userData->programObject);
}

int StartTexturedSquare(int argc, char *argv[])
{
   ESContext esContext;
   TexturedSquareUserData userData;

   esInitContext(&esContext);
   esContext.userData = &userData;

   esCreateWindow2(&esContext, "Textured Square", WINDOW_ICON, 320, 240, ES_WINDOW_RGB);
   
   if(!TexturedSquareInit(&esContext))
      return GAME_ERROR_INIT_FAILED;

   esRegisterDrawFunc(&esContext, TexturedSquareDraw);
   
   esMainLoop(&esContext);

   TexturedSquareShutDown(&esContext);

   return GAME_ENDED_SUCCESS;
}