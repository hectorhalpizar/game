#include <stdio.h>
#include "triangule.h"

int main(int argc, char * argv[]) {

	char * greeting = "world";

	if (argv[1] != NULL) {
		greeting = argv[1];
	}

	printf("Hello %s.\n", greeting);

	UserData userData;
	userData.programObject = 1;

	printf("programObject %d.\n", userData.programObject);

	gameTriangule(argc, argv);

	return 0;
}