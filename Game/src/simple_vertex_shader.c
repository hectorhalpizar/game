#include <stdlib.h>
#include "esUtil.h"
#include "simple_vertex_shader.h"
#include "simple_vertex_shader_shaders.h"
#include "config.h"

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;

   // Uniform locations
   GLint  mvpLoc;
   
   // Vertex daata
   GLfloat  *vertices;
   GLuint   *indices;
   int       numIndices;

   // Rotation angle
   GLfloat   angle;

   // MVP matrix
   ESMatrix  mvpMatrix;
} SimpleVertexShaderUserData;

///
// Initialize the shader and program object
//
int InitSimpleVertexShader(ESContext *esContext)
{
   SimpleVertexShaderUserData *userData = esContext->userData;
   GLbyte *vShaderStr = getSimpleVertexShaderVertexShader();
   GLbyte *fShaderStr = getSimpleVertexShaderFragmentShader();

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram(vShaderStr, fShaderStr);

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation(userData->programObject, "a_position");

   // Get the uniform locations
   userData->mvpLoc = glGetUniformLocation(userData->programObject, "u_mvpMatrix");
   
   // Generate the vertex data
   userData->numIndices = esGenCube(1.0, &userData->vertices,
                                     NULL, NULL, &userData->indices);
   
   // Starting rotation angle for the cube
   userData->angle = 45.0f;

   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   return TRUE;
}

///
// Update MVP matrix based on time
//
void UpdateSimpleVertexShader(ESContext *esContext, float deltaTime)
{
   SimpleVertexShaderUserData *userData = (SimpleVertexShaderUserData*) esContext->userData;
   ESMatrix perspective;
   ESMatrix modelview;
   float    aspect;
   
   // Compute a rotation angle based on time to rotate the cube
   userData->angle += (deltaTime * 40.0f);
   if(userData->angle >= 360.0f)
      userData->angle -= 360.0f;

   // Compute the window aspect ratio
   aspect = (GLfloat) esContext->width / (GLfloat) esContext->height;
   
   // Generate a perspective matrix with a 60 degree FOV
   esMatrixLoadIdentity(&perspective);
   esPerspective(&perspective, 60.0f, aspect, 1.0f, 20.0f);

   // Generate a model view matrix to rotate/translate the cube
   esMatrixLoadIdentity(&modelview);

   // Translate away from the viewer
   esTranslate(&modelview, 0.0, 0.0, -2.0);

   // Rotate the cube
   esRotate(&modelview, userData->angle, 1.0, 0.0, 1.0);
   
   // Compute the final MVP by multiplying the 
   // modevleiw and perspective matrices together
   esMatrixMultiply(&userData->mvpMatrix, &modelview, &perspective);
}

///
// Draw a triangle using the shader pair created in Init()
//
void DrawSimpleVertexShader(ESContext *esContext)
{
   SimpleVertexShaderUserData *userData = esContext->userData;
   
   // Set the viewport
   glViewport( 0, 0, esContext->width, esContext->height);
   
   
   // Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   // Use the program object
   glUseProgram(userData->programObject);

   // Load the vertex position
   glVertexAttribPointer(userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 3 * sizeof(GLfloat), userData->vertices);
   
   glEnableVertexAttribArray(userData->positionLoc);
   
   
   // Load the MVP matrix
   glUniformMatrix4fv(userData->mvpLoc, 1, GL_FALSE, (GLfloat*) &userData->mvpMatrix.m[0][0]);
   
   // Draw the cube
   glDrawElements(GL_TRIANGLES, userData->numIndices, GL_UNSIGNED_INT, userData->indices);

   eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

///
// Cleanup
//
void ShutDownSimpleVertexShader(ESContext *esContext)
{
   SimpleVertexShaderUserData *userData = esContext->userData;

   if(userData->vertices != NULL)
   {
      free ( userData->vertices );
   }

   if(userData->indices != NULL)
   {
      free(userData->indices);
   }

   // Delete program object
   glDeleteProgram ( userData->programObject );
}

int StartSimpleVertexShader(int argc, char *argv[])
{
   ESContext esContext;
   SimpleVertexShaderUserData  userData;

   esInitContext(&esContext);
   esContext.userData = &userData;

   esCreateWindow2(&esContext, "Simple Vertex Shader", WINDOW_ICON, 320, 240, ES_WINDOW_RGB);
   
   if (!InitSimpleVertexShader(&esContext))
      return GAME_ERROR_INIT_FAILED;

   esRegisterDrawFunc(&esContext, DrawSimpleVertexShader);
   esRegisterUpdateFunc(&esContext, UpdateSimpleVertexShader);
   
   esMainLoop(&esContext);

   ShutDownSimpleVertexShader(&esContext);

   return GAME_ENDED_SUCCESS;
}