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
	int demoResult = GAME_ERROR_NO_DEMO_SELECTED;

	if (argv[1] != NULL) {
		programToRun = argv[1];
	}

	printf("Running program %s.\n", programToRun);

	if (strcmp(programToRun, START_GAME_TRIANGLE) == 0)
	{
		demoResult = StartGameTriangle(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_VERTEX_SHADER) == 0)
	{
		demoResult = StartSimpleVertexShader(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_TEXTURED_SQUARE) == 0)
	{
		demoResult = StartTexturedSquare(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_MIP_MAP_2D) == 0)
	{
		demoResult = StartMipMap2D(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_TEXTURED_CUBEMAP) == 0)
	{
		demoResult = StartSimpleTextureCubeMap(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_TEXTURE_WRAP) == 0)
	{
		demoResult = StartTextureWrap(argc, argv);
	}
	else
	{
		printf("Program %s not found.\n", programToRun);
		demoResult = GAME_ERROR_DEMO_NOT_FOUND;
	}

	return demoResult;
}