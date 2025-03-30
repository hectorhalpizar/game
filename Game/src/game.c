#include <stdio.h>
#include "triangule.h"

int main(int argc, char * argv[]) {

	char * programToRun = "";

	if (argv[1] != NULL) {
		programToRun = argv[1];
	}

	printf("Running program %s.\n", programToRun);

	if (strcmp(programToRun, "GameTriangle") == 0)
	{
		GameTriangle(argc, argv);
	}
	else
	{
		printf("Program %s not found.\n", programToRun);
	}

	return 0;
}