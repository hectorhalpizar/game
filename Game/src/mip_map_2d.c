#include <stdlib.h>
#include "esUtil.h"
#include "mip_map_2d.h"
#include "mip_map_2d_shaders.h"
#include "config.h"

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  texCoordLoc;

   // Sampler location
   GLint samplerLoc;

   // Offset location
   GLint offsetLoc;

   // Texture handle
   GLuint textureId;

} UserData;

///
//  Generate an RGB8 checkerboard image
//
GLubyte* MipMap2DGenCheckImage( int width, int height, int checkSize )
{
   int x,
       y;
   GLubyte *pixels = malloc( width * height * 3 );
   
   if ( pixels == NULL )
      return NULL;

   for ( y = 0; y < height; y++ )
      for ( x = 0; x < width; x++ )
      {
         GLubyte rColor = 0;
         GLubyte bColor = 0;

         if ( ( x / checkSize ) % 2 == 0 )
         {
            rColor = 255 * ( ( y / checkSize ) % 2 );
            bColor = 255 * ( 1 - ( ( y / checkSize ) % 2 ) );
         }
         else
         {
            bColor = 255 * ( ( y / checkSize ) % 2 );
            rColor = 255 * ( 1 - ( ( y / checkSize ) % 2 ) );
         }

         pixels[(y * height + x) * 3] = rColor;
         pixels[(y * height + x) * 3 + 1] = 0;
         pixels[(y * height + x) * 3 + 2] = bColor; 
      } 

   return pixels;
}

///
// Create a mipmapped 2D texture image 
//
GLuint MipMap2DCreateTexture2D( )
{
   // Texture object handle
   GLuint textureId;
   int    width = 256,
          height = 256;
   GLubyte *pixels;
      
   pixels = MipMap2DGenCheckImage( width, height, 64 );
   if ( pixels == NULL )
      return 0;

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load mipmap level 0
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, width, height, 
                  0, GL_RGB, GL_UNSIGNED_BYTE, pixels );
   
   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

   return textureId;

}


///
// Initialize the shader and program object
//
int MipMap2DInit ( ESContext *esContext )
{
   UserData *userData = esContext->userData;
   GLbyte *vShaderStr = getMipMap2dVertexShader();
   GLbyte *fShaderStr = getMipMap2dFragmentShader();

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( vShaderStr, fShaderStr );

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation ( userData->programObject, "a_position" );
   userData->texCoordLoc = glGetAttribLocation ( userData->programObject, "a_texCoord" );
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   // Get the offset location
   userData->offsetLoc = glGetUniformLocation( userData->programObject, "u_offset" );

   // Load the texture
   userData->textureId = MipMap2DCreateTexture2D();

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void MipMap2DDraw(ESContext *esContext)
{
   UserData *userData = esContext->userData;
   GLfloat vVertices[] = { -0.3f,  0.3f, 0.0f, 1.0f,  // Position 0
                           -1.0f,  -1.0f,              // TexCoord 0 
                           -0.3f, -0.3f, 0.0f, 1.0f, // Position 1
                           -1.0f,  2.0f,              // TexCoord 1
                            0.3f, -0.3f, 0.0f, 1.0f, // Position 2
                            2.0f,  2.0f,              // TexCoord 2
                            0.3f,  0.3f, 0.0f, 1.0f,  // Position 3
                            2.0f,  -1.0f               // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };
      
   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex position
   glVertexAttribPointer ( userData->positionLoc, 4, GL_FLOAT, 
                           GL_FALSE, 6 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 6 * sizeof(GLfloat), &vVertices[4] );

   glEnableVertexAttribArray ( userData->positionLoc );
   glEnableVertexAttribArray ( userData->texCoordLoc );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   // Draw quad with repeat wrap mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
   glUniform1f ( userData->offsetLoc, -0.7f );   
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   // Draw quad with clamp to edge wrap mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
   glUniform1f ( userData->offsetLoc, 0.0f );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   // Draw quad with mirrored repeat
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT );
   glUniform1f ( userData->offsetLoc, 0.7f );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

///
// Cleanup
//
void MipMap2DShutDown ( ESContext *esContext )
{
   UserData *userData = esContext->userData;

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );
}

int StartMipMap2D(int argc, char *argv[])
{
   ESContext esContext;
   UserData  userData;

   esInitContext ( &esContext );
   esContext.userData = &userData;

   esCreateWindow ( &esContext, "MipMap 2D", 640, 480, ES_WINDOW_RGB );
   
   if ( !MipMap2DInit ( &esContext ) )
      return GAME_ERROR_INIT_FAILED;

   esRegisterDrawFunc ( &esContext, MipMap2DDraw );
   
   esMainLoop ( &esContext );

   MipMap2DShutDown ( &esContext );

   return GAME_ENDED_SUCCESS;
}