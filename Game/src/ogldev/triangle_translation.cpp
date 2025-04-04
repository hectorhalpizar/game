#include <stdlib.h>
#include <math.h>

#include "triangle_translation.hpp"
#include "triangle_translation_shaders.h"
#include "../config.h"
#include "esUtil.h"
#include "../api/game_math.h"

// Definition of the class
class TriangleTranslation {

private:
	typedef struct
	{
		// Pass the TriangleTranslation Demo object
		TriangleTranslation * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;

	// Uniforms
	GLint uWorld;

	static GLuint VBO;

public:
	TriangleTranslation()
	{
		// Default
	}

private:
	GLuint LoadShader(GLenum type, const char *shaderSrc)
	{
		GLuint shader;
		GLint compiled;

		// Create the shader object
		shader = glCreateShader(type);

		if (shader == 0)
			return 0;

		// Load the shader source
		glShaderSource(shader, 1, &shaderSrc, NULL);

		// Compile the shader
		glCompileShader(shader);

		// Check the compile status
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

		if (!compiled)
		{
			GLint infoLen = 0;

			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

			if (infoLen > 1)
			{
				char* infoLog = (char *)malloc (sizeof(char) * infoLen );

				glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
				esLogMessage ( "Error compiling shader:\n%s\n", infoLog );            

				free ( infoLog );
			}

			glDeleteShader(shader);
			return 0;
		}

		return shader;
	}

	int Init(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;

		CreateVertexBuffer();

		// Load the vertex/fragment shaders
		char *vertexShader = getTriangleTranslationVertexShader();
		char *fragmentShader = getTriangleTranslationFragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the attribute locations
		userData->Demo->aPosition = glGetAttribLocation ( userData->Demo->programObject, "a_position" );
		if (userData->Demo->aPosition <= -1)
		{
			esLogMessage("Error getting userData->a_position:\n%d\n", userData->Demo->aPosition);
			return FALSE;
		}

		// Get the uniform offset location
		userData->Demo->uWorld = glGetUniformLocation( userData->Demo->programObject, "u_world" );

		if (userData->Demo->uWorld <= -1)
		{
			esLogMessage("Error getting userData->uWorld:\n%d\n", userData->Demo->uWorld);
			return FALSE;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return TRUE;
	}

	static void CreateVertexBuffer()
	{
		GLfloat vVertices[] = {  0.0f,  1.0f, 0.0f, 
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f };

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);
	}

	static void Draw(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;

		// Set the viewport
		glViewport(0, 0, esContext->width, esContext->height);

		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Use the program object
		glUseProgram(userData->Demo->programObject);

		static float Scale = 0.0f;
		static float Delta = 0.005f;
		Scale += Delta;

		if ((Scale >= 1.0f) || (Scale <= -1.0f))
		{
			Delta *= -1.0f;
		}

		// Set the Scale value with Sin using sinf
		GLfloat World[] = {  
							1.0f,  0.0f, 0.0f, Scale * 2,
							0.0f,  1.0f, 0.0f, Scale,
							0.0f,  0.0f, 1.0f, 0.0f,
						    0.0f,  0.0f, 0.0f, 1.0f 
						  };

		GLint rows = 4; GLint columns = 4;
		TransposeArray(World, &rows, &columns);

		/**
		 * OpenGLES transpose parameter GL_TRUE does NOT (ALWAYS) works as expected
		 * as in OpenGL. Therefore the transpose needs to be done manually.
		 */
		// glUniformMatrix4fv(userData->Demo->uWorld, 1, GL_TRUE, World);
		glUniformMatrix4fv(userData->Demo->uWorld, 1, GL_FALSE, World);

		// Load the vertex data
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(userData->Demo->aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
	}

	void ShutDown( ESContext *esContext )
	{
	   UserData *userData = (UserData *) esContext->userData;

	   // Delete Vertex Buffer Object
	   glDeleteBuffers(1, &VBO);

	   // Delete program object
	   glDeleteProgram ( userData->Demo->programObject );

	   // Delete demo
	   userData->Demo = NULL;
	}

public:
	int Start(int argc, char *argv[])
	{
		ESContext esContext;
		UserData  userData;
		userData.Demo = this;

		esInitContext(&esContext);
		esContext.userData = &userData;

		esCreateWindow2(&esContext, "OGLDEV Triangle Translation", WINDOW_ICON, 320, 240, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

		if(!this->Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterDrawFunc(&esContext, TriangleTranslation::Draw);

		esMainLoop(&esContext);

		this->ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};


GLuint TriangleTranslation::VBO = 0;

int RunOglDevGameTriangleTranslation(int argc, char *argv[])
{
	TriangleTranslation triangleTranslation;
	return triangleTranslation.Start(argc, argv);
}