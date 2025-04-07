#include <stdlib.h>
#include <math.h>

#include "game_math.h"

#include "triangle_interpolation_color.hpp"
#include "triangle_interpolation_color_shaders.h"
#include "../config.h"
#include "esUtil.h"
#include "../api/game_math.h"

// Definition of the class
class TriangleInterpolation {

private:
	typedef struct
	{
		// Pass the TriangleTranslation Demo object
		TriangleInterpolation * Demo;

	} UserData;

public:
	// Handle to a program object
	GLuint programObject;

	// Attributes
	GLint aPosition;

	// Uniforms
	GLint uScale;

	// Varying
	GLint vColor;

	static GLuint VBO;

public:
	TriangleInterpolation()
	{
		// Default
	}

private:
	int Init(ESContext *esContext)
	{
		UserData *userData = (UserData *)esContext->userData;

		CreateVertexBuffer();

		// Load the vertex/fragment shaders
		char *vertexShader = getTriangleInterpolationColorVertexShader();
		char *fragmentShader = getTriangleInterpolationColorFragmentShader();

		userData->Demo->programObject = esLoadProgram ( vertexShader, fragmentShader );

		// Get the attribute locations
		userData->Demo->aPosition = glGetAttribLocation ( userData->Demo->programObject, "a_position" );
		if (userData->Demo->aPosition <= -1)
		{
			esLogMessage("Error getting userData->a_position:\n%d\n", userData->Demo->aPosition);
			return FALSE;
		}

		//userData->Demo->vColor = glGetAttribLocation( userData->Demo->programObject, "a_color");
		//if (userData->Demo->vColor <= -1)
		//{
		//	esLogMessage("Error getting userData->vColor:\n%d\n", userData->Demo->aPosition);
		//	return FALSE;
		//}


		// Get the uniform offset location
		userData->Demo->uScale = glGetUniformLocation( userData->Demo->programObject, "u_scale" );

		if (userData->Demo->uScale <= -1)
		{
			esLogMessage("Error getting userData->u_scale:\n%d\n", userData->Demo->uScale);
			return FALSE;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		return TRUE;
	}

	static void CreateVertexBuffer()
	{
		GLfloat vVertices[] = { 1.0f, -1.0f, 0.0f, 
								0.0f,  1.0f, 0.0f, 
								-1.0f, -1.0f, 0.0f
							   };

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vVertices), vVertices, GL_STATIC_DRAW);
	}

	static void SimpleScaling(UserData *userData)
	{
		
		GLfloat aColors[] = { 1.0f,  0.0f, 0.0f, 1.0f };
		
		// glUniform1f(userData->Demo->uVertexIndex, VertexIndex);
		// GLuint colorAttrib = glGetAttribLocation(userData->Demo->programObject, "a_color");
		//glVertexAttribPointer(userData->Demo->vColor, 4, GL_FLOAT, GL_FALSE, sizeof(aColors), (void*)aColors);

		static float Scale = 1.0f;
		static float Delta = 0.01f;

		Scale += Delta;
		if ((Scale >= 1.5f) || (Scale <= 0.5)) {
			Delta *= -1.0f;
		}

		// Set the Scale value with Sin using sinf
		GLfloat ScaleMatrix[] = {  
							Scale, 0.0f, 0.0f, 0.0f,
							0.0f, Scale, 0.0f, 0.0f,
							0.0f, 0.0f, Scale, 0.0f,
							0.0f, 0.0f, 0.0f, 1.0f
						  };

		GLint rows = 4; GLint columns = 4;
		TransposeArray(ScaleMatrix, &rows, &columns);

		/**
		 * OpenGLES transpose parameter GL_TRUE does NOT (ALWAYS) works as expected
		 * as in OpenGL. Therefore the transpose needs to be done manually.
		 */
		// glUniformMatrix4fv(userData->Demo->uScale, 1, GL_TRUE, ScaleMatrix);
		glUniformMatrix4fv(userData->Demo->uScale, 1, GL_FALSE, ScaleMatrix);
	}

	static void CombinedTranformation1(UserData *userData)
	{
		static float Scale = 1.5f;

		GLfloat ScalingMatrix[] = { Scale, 0.0f,  0.0f,  0.0f,
								  0.0f,  Scale, 0.0f,  0.0f,
								  0.0f,  0.0f,  Scale, 0.0f,
								  0.0f,  0.0f,  0.0f,  1.0f };

		GLint rows = 4; GLint columns = 4;
		// TransposeArray(ScalingMatrix, &rows, &columns);

		static float Loc = 0.0f;
		static float Delta = 0.01f;

		Loc += Delta;
		if ((Loc >= 0.5f) || (Loc <= -0.5f)) {
			Delta *= -1.0f;
		}

		GLfloat TranslationMatrix [] = { 
										1.0f, 0.0f, 0.0f, Loc,
							            0.0f, 1.0f, 0.0f, 0.0,
							            0.0f, 0.0f, 1.0f, 0.0,
							            0.0f, 0.0f, 0.0f, 1.0f
									   };
		
		// TransposeArray(TranslationMatrix, &rows, &columns);

		#define MATRIX_SIZE 16

		GLfloat FinalTransformMatrix[MATRIX_SIZE];
		MultiplyMatrixAsArray(ScalingMatrix, TranslationMatrix, FinalTransformMatrix, 4, 4, 4);

		TransposeArray(FinalTransformMatrix, &rows, &columns);

		/**
		 * OpenGLES transpose parameter GL_TRUE does NOT (ALWAYS) works as expected
		 * as in OpenGL. Therefore the transpose needs to be done manually.
		 */
		// glUniformMatrix4fv(userData->Demo->uScale, 1, GL_TRUE, FinalTransformMatrix);
		glUniformMatrix4fv(userData->Demo->uScale, 1, GL_FALSE, FinalTransformMatrix);
	}

	static void CombinedTranformation2(UserData *userData)
	{
		static float Scale = 0.25f;

		GLfloat Scaling [] = { Scale, 0.0f,  0.0f,  0.0f,
							   0.0f,  Scale, 0.0f,  0.0f,
						       0.0f,  0.0f,  Scale, 0.0f,
							   0.0f,  0.0f,  0.0f,  1.0f };

		static float AngleInRadians = 0.0f;
		static float Delta = 0.01f;

		AngleInRadians += Delta;

		GLfloat Rotation [] = { cosf(AngleInRadians), -sinf(AngleInRadians), 0.0f, 0.0f,
						        sinf(AngleInRadians), cosf(AngleInRadians),  0.0f, 0.0f,
						        0.0,                  0.0f,                  1.0f, 0.0f,
								0.0f,                 0.0f,                  0.0f, 1.0f };

		static float Loc = 0.5f;

		GLfloat Translation [] = { 1.0f, 0.0f, 0.0f, Loc,
							       0.0f, 1.0f, 0.0f, 0.0,
							       0.0f, 0.0f, 1.0f, 0.0,
								   0.0f, 0.0f, 0.0f, 1.0f };

		//// Matrix4f FinalTransform = Translation * Rotation * Scaling;
		// Matrix4f FinalTransform = Rotation * Translation * Scaling;
		GLint rows = 4; GLint columns = 4;

		/**
		 * This is hideous. This needs a better Multiply Matrix function
		 */
		GLfloat Temporal [MATRIX_SIZE];
		GLfloat FinalTransform [MATRIX_SIZE];
		MultiplyMatrixAsArray(Rotation, Translation, Temporal, rows, rows, rows);
		MultiplyMatrixAsArray(Temporal, Scaling, FinalTransform, rows, rows, rows);

		TransposeArray(FinalTransform, &rows, &columns);

		glUniformMatrix4fv(userData->Demo->uScale, 1, GL_FALSE, FinalTransform);
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

		// Use one of these three functions
		SimpleScaling(userData);
		// CombinedTranformation1(userData);
		// CombinedTranformation2(userData);

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

		esCreateWindow2(&esContext, "OGLDEV Triangle Scale", WINDOW_ICON, 720, 720, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

		if(!this->Init(&esContext))
			return GAME_ERROR_INIT_FAILED;

		esRegisterDrawFunc(&esContext, TriangleInterpolation::Draw);

		esMainLoop(&esContext);

		this->ShutDown(&esContext);

		return GAME_ENDED_SUCCESS;
	}
};


GLuint TriangleInterpolation::VBO = 0;

int RunOglGameDevTriangleInterpolationColor(int argc, char *argv[])
{
	TriangleInterpolation TriangleInterpolation;
	return TriangleInterpolation.Start(argc, argv);
}