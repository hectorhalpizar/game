#include <stdlib.h>
#include "esUtil.h"
#include "simple_texture_cubemap.h"
#include "../config.h"

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  normalLoc;

   // Sampler location
   GLint samplerLoc;

   // Texture handle
   GLuint textureId;

   // Vertex data
   int      numIndices;
   GLfloat *vertices;
   GLfloat *normals;
   GLuint  *indices;

} UserData;

///
// Create a simple cubemap with a 1x1 face with a different
// color for each face
GLuint CreateSimpleTextureCubemap()
{
   GLuint textureId;
   // Six 1x1 RGB faces
   GLubyte cubePixels[6][3] =
   {
      // Face 0 - Red
      255, 0, 0,
      // Face 1 - Green,
      0, 255, 0, 
      // Face 3 - Blue
      0, 0, 255,
      // Face 4 - Yellow
      255, 255, 0,
      // Face 5 - Purple
      255, 0, 255,
      // Face 6 - White
      255, 255, 255
   };
   
   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_CUBE_MAP, textureId );
   
   // Load the cube face - Positive X
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[0] );

   // Load the cube face - Negative X
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[1] );

   // Load the cube face - Positive Y
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[2] );

   // Load the cube face - Negative Y
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[3] );

   // Load the cube face - Positive Z
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[4] );

   // Load the cube face - Negative Z
   glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, 1, 1, 0, 
                  GL_RGB, GL_UNSIGNED_BYTE, &cubePixels[5] );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   return textureId;

}


///
// Initialize the shader and program object
//
int SimpleTextureCubemapDrawInit(ESContext *esContext)
{
   UserData *userData = esContext->userData;
   GLbyte vShaderStr[] =  
      "attribute vec4 a_position;   \n"
      "attribute vec3 a_normal;     \n"
      "varying vec3 v_normal;       \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   v_normal = a_normal;      \n"
      "}                            \n";
   
   GLbyte fShaderStr[] =  
      "precision mediump float;                            \n"
      "varying vec3 v_normal;                              \n"
      "uniform samplerCube s_texture;                      \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = textureCube( s_texture, v_normal );\n"
      "}                                                   \n";

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram(vShaderStr, fShaderStr);

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation(userData->programObject, "a_position");
   userData->normalLoc = glGetAttribLocation(userData->programObject, "a_normal");
   
   // Get the sampler locations
   userData->samplerLoc = glGetUniformLocation(userData->programObject, "s_texture");

   // Load the texture
   userData->textureId = CreateSimpleTextureCubemap();

   // Generate the vertex data
   userData->numIndices = esGenSphere(20, 0.75f, &userData->vertices, &userData->normals, 
                                        NULL, &userData->indices);
   
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void SimpleTextureCubemapDraw ( ESContext *esContext )
{
   UserData *userData = esContext->userData;
      
   // Set the viewport
   glViewport(0, 0, esContext->width, esContext->height);
   
   // Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   
   glCullFace(GL_BACK);
   glEnable(GL_CULL_FACE);
   
   // Use the program object
   glUseProgram(userData->programObject);

   // Load the vertex position
   glVertexAttribPointer(userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 0, userData->vertices);
   // Load the normal
   glVertexAttribPointer(userData->normalLoc, 3, GL_FLOAT,
                           GL_FALSE, 0, userData->normals);

   glEnableVertexAttribArray(userData->positionLoc);
   glEnableVertexAttribArray(userData->normalLoc);

   // Bind the texture
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_CUBE_MAP, userData->textureId);

   // Set the sampler texture unit to 0
   glUniform1i(userData->samplerLoc, 0);

   glDrawElements(GL_TRIANGLES, userData->numIndices, 
                    GL_UNSIGNED_INT, userData->indices);

   eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

///
// Cleanup
//
void SimpleTextureCubemapShutDown ( ESContext *esContext )
{
   UserData *userData = esContext->userData;

   // Delete texture object
   glDeleteTextures(1, &userData->textureId);

   // Delete program object
   glDeleteProgram(userData->programObject);

   free(userData->vertices);
   free(userData->normals);
}

int StartSimpleTextureCubeMap(int argc, char *argv[])
{
   ESContext esContext;
   UserData  userData;

   esInitContext(&esContext);
   esContext.userData = &userData;

   esCreateWindow2(&esContext, "Simple Texture Cubemap", WINDOW_ICON, 320, 240, ES_WINDOW_RGB);
   
   if (!SimpleTextureCubemapDrawInit(&esContext))
      return GAME_ERROR_INIT_FAILED;

   esRegisterDrawFunc(&esContext, SimpleTextureCubemapDraw);
   
   esMainLoop(&esContext);

   SimpleTextureCubemapShutDown(&esContext);

   return GAME_ENDED_SUCCESS;
}