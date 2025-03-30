#ifndef __GAME_SIMPLE_VERTEX_SHADER_H__
#define __GAME_SIMPLE_VERTEX_SHADER_H__

#define START_GAME_SIMPLE_VERTEX_SHADER "GameSimpleVertexShader"

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
int InitSimpleVertexShader(ESContext *esContext);

///
// Update MVP matrix based on time
//
void UpdateSimpleVertexShader(ESContext *esContext, float deltaTime);

///
// Draw a triangle using the shader pair created in Init()
//
void DrawSimpleVertexShader(ESContext *esContext);

///
// Cleanup
//
void ShutDownSimpleVertexShader(ESContext *esContext);


int StartSimpleVertexShader(int argc, char *argv[]);

#endif // __GAME_SIMPLE_VERTEX_SHADER_H__
