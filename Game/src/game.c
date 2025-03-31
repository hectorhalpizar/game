#include <stdio.h>
#include "triangle.h"
#include "simple_vertex_shader.h"
#include "textured_square.h"
#include "mip_map_2d.h"
#include "simple_texture_cubemap.h"
#include "texture_wrap.h"
#include "config.h"

int main(int argc, char * argv[]) {

	char * programToRun = START_GAME_TEXTURE_WRAP;
	int demoResult = GAME_ERROR_DEMO_NOT_FOUND;
	int (*runGameDemo) (int, char **) = NULL;

	if (argv[1] != NULL) {
		programToRun = argv[1];
	}

	printf("Running program %s.\n", programToRun);

	// Assigning runGameDemo
	if (strcmp(programToRun, START_GAME_TRIANGLE) == 0)
	{
		runGameDemo = StartGameTriangle;
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_VERTEX_SHADER) == 0)
	{
		runGameDemo = StartSimpleVertexShader;
	}
	else if (strcmp(programToRun, START_GAME_TEXTURED_SQUARE) == 0)
	{
		runGameDemo = StartTexturedSquare;
	}
	else if (strcmp(programToRun, START_GAME_MIP_MAP_2D) == 0)
	{
		runGameDemo = StartMipMap2D;
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_TEXTURED_CUBEMAP) == 0)
	{
		runGameDemo = StartSimpleTextureCubeMap;
	}
	else if (strcmp(programToRun, START_GAME_TEXTURE_WRAP) == 0)
	{
		runGameDemo = StartTextureWrap;
	}

	// Outcome of the selected runGameDemo value
	if (runGameDemo != NULL)
	{
		demoResult = runGameDemo(argc, argv);
	}
	else
	{
		printf("Program %s not found.\n", programToRun);
	}

	return demoResult;
}