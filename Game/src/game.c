#include <stdio.h>
#include "triangle.h"
#include "simple_vertex_shader.h"
#include "textured_square.h"
#include "mip_map_2d.h"
#include "simple_texture_cubemap.h"
#include "texture_wrap.h"
#include "multitexture.h"
#include "multisample.h"
#include "stencil_test.h"
#include "main_game/boot.hpp"
#include "ogldev/triangle_uniform_variables.hpp"
#include "ogldev/triangle_translation.hpp"
#include "ogldev/triangle_rotation.hpp"
#include "ogldev/triangle_scale.hpp"
#include "ogldev/triangle_interpolation_color.hpp"
#include "config.h"

#define AMOUNT_OF_DEMOS 14

void printHelp(char * programToRun)
{
	char * DEMOS_AVAILABLE [AMOUNT_OF_DEMOS] = { 
		START_GAME_TRIANGLE,
		START_GAME_SIMPLE_VERTEX_SHADER,
		START_GAME_TEXTURED_SQUARE,
		START_GAME_MIP_MAP_2D,
		START_GAME_SIMPLE_TEXTURED_CUBEMAP,
		START_GAME_TEXTURE_WRAP,
		START_GAME_MULTITEXTURE,
		START_GAME_MULTISAMPLE,
		START_GAME_STENCIL_TEST,
		BOOT_GAME, 
		RUN_GAME_OGLDEV_TRIANGLE_UNIFORM_VARIABLES,
		RUN_GAME_OGLDEV_TRIANGLE_TRANSLATION,
		RUN_GAME_OGLDEV_TRIANGLE_ROTATION,
		RUN_GAME_OGLDEV_TRIANGLE_SCALE 
	};

	int demoIndex = 0;
	printf("\nProgram %s not found.\n\nAvailable demos:\n", programToRun);

	for (demoIndex; demoIndex < AMOUNT_OF_DEMOS; demoIndex ++)
	{
		printf("\t%s\n", DEMOS_AVAILABLE[demoIndex]);
	}

	printf("\n\n\tRun: Game.exe <DEMO ARGUMENT>"
		   "\n\n"
		   "\tExample: Game.exe GameTexturedTriangle"
		   "\n\n\n");
}

int main(int argc, char * argv[]) {

	char * programToRun = BOOT_GAME;
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
	else if (strcmp(programToRun, START_GAME_MULTITEXTURE) == 0)
	{
		runGameDemo = StartMultiTexture;
	}
	else if (strcmp(programToRun, START_GAME_MULTISAMPLE) == 0)
	{
		runGameDemo = StartMultiSample;
	}
	else if (strcmp(programToRun, START_GAME_STENCIL_TEST) == 0)
	{
		runGameDemo = StartStencilTest;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_UNIFORM_VARIABLES) == 0)
	{
		runGameDemo = RunOglDevGameTriangleUniformVariables;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_TRANSLATION) == 0)
	{
		runGameDemo = RunOglDevGameTriangleTranslation;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_ROTATION) == 0)
	{
		runGameDemo = RunOglDevGameTriangleRotation;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_SCALE) == 0)
	{
		runGameDemo = RunOglDevGameTriangleScale;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_INTERPOLATION_COLOR) == 0)
	{
		runGameDemo = RunOglGameDevTriangleInterpolationColor;
	}

	// Outcome of the selected runGameDemo value
	if (runGameDemo != NULL)
	{
		demoResult = runGameDemo(argc, argv);
	}
	else if (strcmp(programToRun, BOOT_GAME) == 0)
	{
		demoResult = BootGame(NULL);
	}
	else
	{
		printHelp(programToRun);
	}

	return demoResult;
}