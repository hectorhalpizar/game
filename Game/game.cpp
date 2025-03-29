#include <stdio.h>

int main(int argc, char * argv[]) {

	char * greeting = "world";

	if (argv[1] != NULL) {
		greeting = argv[1];
	}

	printf("Hello %s.\n", greeting);
	return 0;
}