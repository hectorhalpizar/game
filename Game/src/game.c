#include <stdio.h>
#include "triangle.h"
#include "simple_vertex_shader.h"

int main(int argc, char * argv[]) {

	char * programToRun = "GameSimpleVertexShader";

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
	else
	{
		printf("Program %s not found.\n", programToRun);
	}

	return 0;
}