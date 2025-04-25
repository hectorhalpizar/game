#include <stdio.h>
#include "main_game/boot.hpp"
#include "gles2_book/triangle.h"
#include "gles2_book/simple_vertex_shader.h"
#include "gles2_book/textured_square.h"
#include "gles2_book/mip_map_2d.h"
#include "gles2_book/simple_texture_cubemap.h"
#include "gles2_book/texture_wrap.h"
#include "gles2_book/multitexture.h"
#include "gles2_book/multisample.h"
#include "gles2_book/stencil_test.h"
#include "ogldev/triangle_uniform_variables.hpp"
#include "ogldev/triangle_translation.hpp"
#include "ogldev/triangle_rotation.hpp"
#include "ogldev/triangle_scale.hpp"
#include "ogldev/triangle_interpolation_color.hpp"
#include "ogldev/triangle_index_draws.hpp"
#include "ogldev/perspective_projection.hpp"
#include "ogldev/camera_space.hpp"
#include "config.h"

#define AMOUNT_OF_DEMOS 18

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
		RUN_GAME_OGLDEV_TRIANGLE_SCALE,
		RUN_GAME_OGLDEV_TRIANGLE_INTERPOLATION_COLOR,
		RUN_GAME_OGLDEV_TRIANGLE_INDEX_DRAWS,
		RUN_GAME_OGLDEV_PESPSPECTIVE_PROJECTION,
		RUN_GAME_OGLDEV_CAMERA_SPACE
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
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_TRIANGLE_INDEX_DRAWS) == 0)
	{
		runGameDemo = RunOglDevGameTriangleIndexDraws;
	}
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_PESPSPECTIVE_PROJECTION) == 0)
	{
		runGameDemo = RunOglDevGamePerspectiveProjection;
	}// RunOglDevGamePerspectiveCamera
	else if (strcmp(programToRun, RUN_GAME_OGLDEV_CAMERA_SPACE) == 0)
	{
		runGameDemo = RunOglDevGameCameraSpace;
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