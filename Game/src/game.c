#include <stdio.h>
#include "triangle.h"
#include "simple_vertex_shader.h"
#include "textured_square.h"
#include "mip_map_2d.h"
#include "simple_texture_cubemap.h"
#include "texture_wrap.h"

int main(int argc, char * argv[]) {

	char * programToRun = START_GAME_TEXTURE_WRAP;

	if (argv[1] != NULL) {
		programToRun = argv[1];
	}

	printf("Running program %s.\n", programToRun);

	if (strcmp(programToRun, START_GAME_TRIANGLE) == 0)
	{
		StartGameTriangle(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_VERTEX_SHADER) == 0)
	{
		StartSimpleVertexShader(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_TEXTURED_SQUARE) == 0)
	{
		StartTexturedSquare(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_MIP_MAP_2D) == 0)
	{
		StartMipMap2D(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_SIMPLE_TEXTURED_CUBEMAP) == 0)
	{
		StartSimpleTextureCubeMap(argc, argv);
	}
	else if (strcmp(programToRun, START_GAME_TEXTURE_WRAP) == 0)
	{
		StartTextureWrap(argc, argv);
	}
	else
	{
		printf("Program %s not found.\n", programToRun);
	}

	return 0;
}