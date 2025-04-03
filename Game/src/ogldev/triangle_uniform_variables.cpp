#include <stdlib.h>
#include <math.h>

#include "triangle_uniform_variables.hpp"
#include "triangle_uniform_variables_shaders.h"
#include "../config.h"
#include "esUtil.h"

// Definition of the class
class TriangleUniformVariables {

private:
	typedef struct
	{
		// Pass the TriangleUniformVariables Demo object
		TriangleUniformVariables * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;

	// Uniforms
	GLint uScale;

public:
	TriangleUniformVariables()
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

		// Load the vertex/fragment shaders
		char *vertexShader = getTriangleUniformVariablesVertexShader();
		char *fragmentShader = getTriangleUniformVariablesFragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the attribute locations
		userData->Demo->aPosition = glGetAttribLocation ( userData->Demo->programObject, "a_position" );
		if (userData->Demo->aPosition <= -1)
		{
			esLogMessage("Error getting userData->a_position:\n%d\n", userData->Demo->uScale);
			return FALSE;
		}

		// Get the uniform offset location
		userData->Demo->uScale = glGetUniformLocation( userData->Demo->programObject, "u_scale" );

		if (userData->Demo->uScale <= -1)
		{
			esLogMessage("Error getting userData->uScale:\n%d\n", userData->Demo->uScale);
			return FALSE;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return TRUE;
	}

	static void Draw(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;
		GLfloat vVertices[] = {  0.0f,  1.0f, 0.0f, 
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f };

		// Set the viewport
		glViewport(0, 0, esContext->width, esContext->height);

		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Use the program object
		glUseProgram(userData->Demo->programObject);

		static float Scale = 0.0f;
		Scale += 0.01f;

		// Sine will always between -1 to 1
		float sine = sinf(Scale);
		
		// Set the Scale value with Sin using sinf
		glUniform1f(userData->Demo->uScale, sine);

		// Load the vertex data
		glVertexAttribPointer(userData->Demo->aPosition, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
	}

	void ShutDown( ESContext *esContext )
	{
	   UserData *userData = (UserData *) esContext->userData;

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

		esCreateWindow2(&esContext, "OGLDEV Triangle Uniform Variables", WINDOW_ICON, 1080, 720, ES_WINDOW_RGB);

		if(!Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterDrawFunc(&esContext, TriangleUniformVariables::Draw);

		esMainLoop(&esContext);

		ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};

int StartOglDevGameTriangleUniformVariables(int argc, char *argv[])
{
	TriangleUniformVariables Demo;
	return Demo.Start(argc, argv);
}