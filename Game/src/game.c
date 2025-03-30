#include <stdio.h>
#include "triangle.h"

int main(int argc, char * argv[]) {

	char * programToRun = "";

	if (argv[1] != NULL) {
		programToRun = argv[1];
	}

	printf("Running program %s.\n", programToRun);

	if (strcmp(programToRun, START_GAME_TRIANGLE) == 0)
	{
		StartGameTriangle(argc, argv);
	}
	else
	{
		printf("Program %s not found.\n", programToRun);
	}

	return 0;
}