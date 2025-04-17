#include <stdlib.h>
#include <math.h>
#include <cstddef>

#include "transformation.h"
#include "game_math.hpp"

#include "perspective_camera.hpp"
#include "perspective_camera_shaders.h"
#include "../config.h"
#include "esUtil.h"

#include "Vertex.h"

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080

#define M_PI (3.14)
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

// Definition of the class
class PerspectiveCamera {

private:
	typedef struct
	{
		// Pass the TriangleTranslation Demo object
		PerspectiveCamera * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;
	GLint aColor;

	// Uniforms
	GLint uWvp;

	static GLuint VBO;
	static GLuint IBO;

public:
	PerspectiveCamera()
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
		char *vertexShader = getPerspectiveCameraVertexShader();
		char *fragmentShader = getPerspectiveCameraFragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the varying locations
		userData->Demo->aColor = glGetAttribLocation ( userData->Demo->programObject, "a_color" );
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
		userData->Demo->uWvp = glGetUniformLocation( userData->Demo->programObject, "u_wvp" );

		if (userData->Demo->uWvp <= -1)
		{
			esLogMessage("Error getting userData->u_scale:\n%d\n", userData->Demo->uWvp);
			return FALSE;
		}

				// Use the program object
		glUseProgram(userData->Demo->programObject);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return TRUE;
	}

	static void CreateVertexBuffer()
	{
		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CW);
		glCullFace(GL_BACK);

		Vertex Vertices[8];

		Vertices[0] = Vertex(0.5f, 0.5f, 0.5f);
		Vertices[1] = Vertex(-0.5f, 0.5f, -0.5f);
		Vertices[2] = Vertex(-0.5f, 0.5f, 0.5f);
		Vertices[3] = Vertex(0.5f, -0.5f, -0.5f);
		Vertices[4] = Vertex(-0.5f, -0.5f, -0.5f);
		Vertices[5] = Vertex(0.5f, 0.5f, -0.5f);
		Vertices[6] = Vertex(0.5f, -0.5f, 0.5f);
		Vertices[7] = Vertex(-0.5f, -0.5f, 0.5f);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	}

	static void CreateIndexBuffer()
	{
		unsigned int Indices[] = {
							  0, 1, 2,
							  1, 3, 4,
							  5, 6, 3,
							  7, 3, 6,
							  2, 4, 7,
							  0, 7, 6,
							  0, 5, 1,
							  1, 5, 3,
							  5, 0, 6,
							  7, 4, 3,
							  2, 1, 4,
							  0, 2, 7
		};

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

		Scale += 0.02f;

		GLfloat Rotation[16];
		rotateRowMajor(Rotation, 0.f, Scale, 0.f);

		GLfloat Translation[16];
		translateRowMajor(Translation, 0.f, 0.f, 2.f);

		GLfloat World[16];
		GLint size = 4;
		MultiplyMatrixAsArray(Translation, Rotation, World, size, size, size);

		// Manipulate this values and you'll have a Camera working
		GLfloat CameraPos[] = { 0.f,  0.f,  -10.25f };
		GLfloat U[]         = { 1.f,  0.f,  0.f };
		GLfloat V[]         = { 0.f,  1.f,  0.f };
		GLfloat N[]         = { 0.f,  0.f,  1.f };

		GLfloat MatrixCamera[] = { U[0], U[1], U[2], -CameraPos[0],
								   V[0], V[1], V[2], -CameraPos[1],
								   N[0], N[1], N[2], -CameraPos[2],
								   0.f,  0.f,	0.f,		  1.f };


		// Projection
		float VFOV = 45.0f;
		float tanHalfVFOV = tanf(ToRadian(VFOV / 2.0f));
		float d = 1.f/tanHalfVFOV;

		float ar = (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT;

		float NearZ = 1.0f;
		// Modified this values to see if 
		float FarZ = 1000.0f;
		// float FarZ = 0.5f;

		float zRange = NearZ - FarZ;
		
		float A = (-FarZ - NearZ) / zRange;
		float B = 2.0f * FarZ * NearZ / zRange;

		GLfloat Projection [] = { d/ar, 0.0f, 0.0f, 0.0f, 
								   0.f,  d,	  0.0f, 0.0f, 
								   0.0,	 0.0, A,	B, 
								   0.0,  0.0 ,1.0f, 0.0f };

		GLfloat auxWvp[16];
		GLfloat wvp[16];
		MultiplyMatrixAsArray(MatrixCamera, World, auxWvp, size, size, size);
		MultiplyMatrixAsArray(Projection, auxWvp, wvp, size, size, size);
		TransposeArray(wvp, &size, &size);
		glUniformMatrix4fv(userData->Demo->uWvp, 1, GL_FALSE, wvp);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		// Load the vertex data
		glEnableVertexAttribArray(userData->Demo->aPosition);
		glVertexAttribPointer(userData->Demo->aPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, pos));

		// Load color data
		glEnableVertexAttribArray(userData->Demo->aColor);
		glVertexAttribPointer(userData->Demo->aColor, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

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

		esCreateWindow2(&esContext, 
						"OGLDEV Perspecive Camera", 
						WINDOW_ICON, 
						WINDOW_WIDTH, 
						WINDOW_HEIGHT, 
						ES_WINDOW_RGB | ES_WINDOW_DEPTH);

		if(!this->Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterDrawFunc(&esContext, PerspectiveCamera::Draw);

		esMainLoop(&esContext);

		this->ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};


GLuint PerspectiveCamera::VBO = 0;
GLuint PerspectiveCamera::IBO = 0;

int RunOglDevGamePerspectiveCamera(int argc, char *argv[])
{
	PerspectiveCamera perspectiveCamera;
	return perspectiveCamera.Start(argc, argv);
}
