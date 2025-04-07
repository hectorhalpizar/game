#include <stdlib.h>
#include <math.h>
#include <cstddef>

#include "game_math.h"

#include "triangle_index_draws.hpp"
#include "triangle_index_draws_shaders.h"
#include "../config.h"
#include "esUtil.h"
#include "../api/game_math.h"

#include "Vertex.h"


// Definition of the class
class TriangleIndexDraw {

private:
	typedef struct
	{
		// Pass the TriangleTranslation Demo object
		TriangleIndexDraw * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;
	GLint aColor;

	// Uniforms
	GLint uWorld;

	static GLuint VBO;
	static GLuint IBO;

public:
	TriangleIndexDraw()
	{
		// Default
	}

private:
	int Init(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;

		CreateVertexBuffer();
		CreateIndexBuffer();

		// Load the vertex/fragment shaders
		char *vertexShader = getTriangleIndexDrawsVertexShader();
		char *fragmentShader = getTriangleIndexDrawsFragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the varying locations
		userData->Demo->aColor = glGetAttribLocation ( userData->Demo->programObject, "b_color" );
		if (userData->Demo->aColor <= -1)
		{
			esLogMessage("Error getting userData->aColor:\n%d\n", userData->Demo->aColor);
			return FALSE;
		}

		// Get the attribute locations
		userData->Demo->aPosition = glGetAttribLocation ( userData->Demo->programObject, "a_position" );
		if (userData->Demo->aPosition <= -1)
		{
			esLogMessage("Error getting userData->a_position:\n%d\n", userData->Demo->aPosition);
			return FALSE;
		}


		// Get the uniform offset location
		userData->Demo->uWorld= glGetUniformLocation( userData->Demo->programObject, "u_world" );

		if (userData->Demo->uWorld <= -1)
		{
			esLogMessage("Error getting userData->u_scale:\n%d\n", userData->Demo->uWorld);
			return FALSE;
		}

				// Use the program object
		glUseProgram(userData->Demo->programObject);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return TRUE;
	}

	static void CreateVertexBuffer()
	{
		Vertex Vertices[19];

		// Center
		Vertices[0] = Vertex(0.0f, 0.0);

		// Top row
		Vertices[1] = Vertex(-1.0f,  1.0f);
		Vertices[2] = Vertex(-0.75f, 1.0f);
		Vertices[3] = Vertex(-0.50f, 1.0f);
		Vertices[4] = Vertex(-0.25f, 1.0f);
		Vertices[5] = Vertex(-0.0f,  1.0f);
		Vertices[6] = Vertex(0.25f,  1.0f);
		Vertices[7] = Vertex(0.50f,  1.0f);
		Vertices[8] = Vertex(0.75f,  1.0f);
		Vertices[9] = Vertex(1.0f,   1.0f);

		// Bottom row
		Vertices[10] = Vertex(-1.0f,  -1.0f);
		Vertices[11] = Vertex(-0.75f, -1.0f);
		Vertices[12] = Vertex(-0.50f, -1.0f);
		Vertices[13] = Vertex(-0.25f, -1.0f);
		Vertices[14] = Vertex(-0.0f,  -1.0f);
		Vertices[15] = Vertex(0.25f,  -1.0f);
		Vertices[16] = Vertex(0.50f,  -1.0f);
		Vertices[17] = Vertex(0.75f,  -1.0f);
		Vertices[18] = Vertex(1.0f,   -1.0f);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	}

	static void CreateIndexBuffer()
	{
	    unsigned int Indices[] = { 
						   // Top triangles
                           0, 2, 1,
                           0, 3, 2,
                           0, 4, 3,
                           0, 5, 4,
                           0, 6, 5,
                           0, 7, 6,
                           0, 8, 7,
                           0, 9, 8,

                           // Bottom triangles
                           0, 10, 11,
                           0, 11, 12,
                           0, 12, 13,
                           0, 13, 14,
                           0, 14, 15,
                           0, 15, 16,
                           0, 16, 17,
                           0, 17, 18,

                           // Left triangle
                           0, 1, 10,

                           // Right triangle
                           0, 18, 9 };

		int size = sizeof(Indices);

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, Indices, GL_STATIC_DRAW);
	}

	static void Draw(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;

		// Set the viewport
		glViewport(0, 0, esContext->width, esContext->height);

		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		static float Scale = 0.0f;
		// Scale += 0.01f;

		Scale += 0.01f;

		GLfloat World [] = 	{ cosf(Scale), -sinf(Scale),  0.0f, 0.0f, 
							   sinf(Scale), cosf(Scale),  0.0f, 0.0f, 
							   0.0,         0.0,          1.0f, 0.0f, 
							   0.0,         0.0 ,         0.0f, 1.0f };

		GLint size = 4;
		TransposeArray(World, &size, &size); 
		glUniformMatrix4fv(userData->Demo->uWorld, 1, GL_FALSE, World);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		// Load the vertex data
		glEnableVertexAttribArray(userData->Demo->aPosition);
		glVertexAttribPointer(userData->Demo->aPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, pos));

		// Load color data
		glEnableVertexAttribArray(userData->Demo->aColor);
		glVertexAttribPointer(userData->Demo->aColor, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));

		glDrawElements(GL_TRIANGLES, 54, GL_UNSIGNED_INT, 0);

		GLenum err = glGetError();
		if (err != GL_NO_ERROR) {
			esLogMessage("OpenGL Error: %d\n", err);
			
			GLint bufferSize = 0;
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);

			esLogMessage("VBO Size:: %d\n", bufferSize);
		}

		glDisableVertexAttribArray(userData->Demo->aPosition);
		glDisableVertexAttribArray(userData->Demo->aColor);

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

		esCreateWindow2(&esContext, "OGLDEV Index draw", WINDOW_ICON, 720, 720, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

		if(!this->Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterDrawFunc(&esContext, TriangleIndexDraw::Draw);

		esMainLoop(&esContext);

		this->ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};


GLuint TriangleIndexDraw::VBO = 0;
GLuint TriangleIndexDraw::IBO = 0;

int RunOglDevGameTriangleIndexDraws(int argc, char *argv[])
{
	TriangleIndexDraw triangleIndexDraw;
	return triangleIndexDraw.Start(argc, argv);
}