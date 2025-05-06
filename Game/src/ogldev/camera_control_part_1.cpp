#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstddef>

#include "transformation.h"
#include "game_math.hpp"
#include "game_utils.hpp"
#include "world_transform.hpp"
#include "camera.hpp"

#include "camera_control_part_1.hpp"
#include "camera_control_part_1_shaders.h"
#include "../config.h"
#include "esUtil.h"

using namespace gameutils;
using namespace gameutils::math;

#define WINDOW_WIDTH  1920 >> 1
#define WINDOW_HEIGHT 1080 >> 1

#define M_PI (3.14)
#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

// Vertex without color
struct Vertex {
	GLfloat pos[3];

	Vertex() {}

	Vertex(float x, float y)
	{
		Vertex(x, y, 1.f);
	}

	Vertex(float x, float y, float z)
	{
		pos[0] = x; pos[1] = y; pos[2] = z;
	}
};


// Definition of the class
class CameraControlPart1 {

private:
	typedef struct
	{
		CameraControlPart1 * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;
	GLint aColor;

	// Uniforms
	GLint gWVPLocation;

	static GLuint VBO;
	static GLuint IBO;

	WorldTransform CubeWorldTransform;
	Camera GameCamera;
	PerspectiveProjection GamePerspectiveProjection;

public:
	CameraControlPart1()
	{
		// Default
		GamePerspectiveProjection = PerspectiveProjection(45.0F, 1.F, 10);
		GameCamera.SetPosition(0.f, 0.f, 0.f);
	}

private:
	int Init(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;
		
		CreateVertexBuffer();
		CreateIndexBuffer();

		// Load the vertex/fragment shaders
		char *vertexShader = getCameraControlPart1VertexShader();
		char *fragmentShader = getCameraControlPart1FragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the attribute locations
		userData->Demo->aPosition = glGetAttribLocation ( userData->Demo->programObject, "a_position" );
		if (userData->Demo->aPosition <= -1)
		{
			esLogMessage("Error getting userData->a_position:\n%d\n", userData->Demo->aPosition);
			return FALSE;
		}


		// Get the uniform offset location
		userData->Demo->gWVPLocation = glGetUniformLocation( userData->Demo->programObject, "u_wvp" );

		if (userData->Demo->gWVPLocation <= -1)
		{
			esLogMessage("Error getting userData->u_scale:\n%d\n", userData->Demo->gWVPLocation);
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

	static void OnKeyPress(ESContext *esContext, unsigned char key, int x, int y)
	{
		UserData *userData = (UserData *)esContext->userData;
		CameraControlPart1 *demo = userData->Demo;
		Camera& GameCamera = demo->GameCamera;

		switch(key)
		{
			case 'w':
			case 'W':
				GameCamera.Maniputale(Camera::MOVE_UP);
				break;
			case 's':
			case 'S':
				GameCamera.Maniputale(Camera::MOVE_DOWN);
				break;
			case 'a':
			case 'A':
				GameCamera.Maniputale(Camera::MOVE_LEFT);
				break;
			case 'd':
			case 'D':
				GameCamera.Maniputale(Camera::MOVE_RIGHT);
				break;
			case 'y':
			case 'Y':
				GameCamera.Maniputale(Camera::MOVE_FORWARD);
				break;
			case 'h':
			case 'H':
				GameCamera.Maniputale(Camera::MOVE_BACKWARD);
				break;
			case '+':
				GameCamera.Maniputale(Camera::SPEED_UP);
				break;
			case '-':
				GameCamera.Maniputale(Camera::SPEED_DOWN);
				break;
		}


	}

	static void Draw(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;
		CameraControlPart1 *demo = userData->Demo;

		WorldTransform CubeWorldTransform = demo->CubeWorldTransform;
		Camera GameCamera = demo->GameCamera;
		PerspectiveProjection GamePerspectiveProjection = demo->GamePerspectiveProjection;

		// Set the viewport
		glViewport(0, 0, esContext->width, esContext->height);

		// Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		#ifdef _WIN64
			static float YRotationAngle = 0.1f;
		#else
			static float YRotationAngle = 0.0f;
		#endif

		YRotationAngle += 1.15F;

		CubeWorldTransform.Rotate(0.0f, YRotationAngle, 0.0f);
		CubeWorldTransform.SetPosition(0.0f, 0.0f, -2.F);
		
		Matrix4D World = CubeWorldTransform.GetMatrix();
		Matrix4D View = GameCamera.GetMatrix();
		Matrix4D Projection = MakePerspectiveProjectionTransform(
								GamePerspectiveProjection, 
								esContext->width, 
								esContext->height
							);

		// TODO: Not quite working correctly.
		Matrix4D WVP = Transponse(Projection * View * World);
		glUniformMatrix4fv(userData->Demo->gWVPLocation, 1, GL_FALSE, &WVP[0][0]);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		// Load the vertex data
		glEnableVertexAttribArray(userData->Demo->aPosition);
		glVertexAttribPointer(userData->Demo->aPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, pos));

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
						"OGLDEV Camera Part 1", 
						WINDOW_ICON, 
						WINDOW_WIDTH, 
						WINDOW_HEIGHT, 
						ES_WINDOW_RGB | ES_WINDOW_DEPTH);

		if(!this->Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterKeyFunc(&esContext,CameraControlPart1::OnKeyPress);

		esRegisterDrawFunc(&esContext, CameraControlPart1::Draw);

		esMainLoop(&esContext);

		this->ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};


GLuint CameraControlPart1::VBO = 0;
GLuint CameraControlPart1::IBO = 0;

int RunOglDevGameCameraControlPart1(int argc, char *argv[])
{
	CameraControlPart1 cameraControlPart1;
	return cameraControlPart1.Start(argc, argv);
}
