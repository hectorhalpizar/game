#include "esUtil.h"
#include "triangle.h"
#include "triangle_shaders.h"
#include "../config.h"

typedef struct
{
	// Handle to a program object
	GLuint programObject;

} UserData;

///
// Create a shader object, load the shader source, and
// compile the shader.
//
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
			char* infoLog = malloc (sizeof(char) * infoLen );

			glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
			esLogMessage ( "Error compiling shader:\n%s\n", infoLog );            

			free ( infoLog );
		}

		glDeleteShader(shader);
		return 0;
	}

	return shader;

}

///
// Initialize the shader and program object
//
int Init(ESContext *esContext)
{
	UserData *userData = esContext->userData;

	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint programObject;
	GLint linked;

	// Load the vertex/fragment shaders
	vertexShader = LoadShader(GL_VERTEX_SHADER, getTriangleVertexShader());
	fragmentShader = LoadShader(GL_FRAGMENT_SHADER, getTriangleFragmentShader());

	// Create the program object
	programObject = glCreateProgram();

	if (programObject == 0)
		return 0;

	glAttachShader(programObject, vertexShader);
	glAttachShader(programObject, fragmentShader);

	// Bind vPosition to attribute 0   
	glBindAttribLocation(programObject, 0, "vPosition");

	// Link the program
	glLinkProgram(programObject);

	// Check the link status
	glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

	if(!linked) 
	{
		GLint infoLen = 0;

		glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

		if(infoLen > 1)
		{
			char* infoLog = malloc(sizeof(char) * infoLen);

			glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
			esLogMessage("Error linking program:\n%s\n", infoLog);            

			free(infoLog);
		}

		glDeleteProgram(programObject);
		return FALSE;
	}

	// Store the program object
	userData->programObject = programObject;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw(ESContext *esContext)
{
	UserData *userData = esContext->userData;
	GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f, 
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f };

	// Set the viewport
	glViewport(0, 0, esContext->width, esContext->height);

	// Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Use the program object
	glUseProgram(userData->programObject);

	// Load the vertex data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

int StartGameTriangle(int argc, char *argv[])
{
	ESContext esContext;
	UserData  userData;

	esInitContext(&esContext);
	esContext.userData = &userData;

	esCreateWindow2(&esContext, "Hello Triangle", WINDOW_ICON, 320, 240, ES_WINDOW_RGB);

	if(!Init(&esContext))
		return GAME_ERROR_INIT_FAILED;

	esRegisterDrawFunc(&esContext, Draw);

	esMainLoop(&esContext);

	return GAME_ENDED_SUCCESS;
}
