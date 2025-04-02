#include "boot.hpp"
#include <stdio.h>

///
// Boots the Game
//		data - Pases any type of data that is going the game.
int BootGame(void * data)
{
	printf("Game booted\n");

	if (data == NULL)
	{
		printf("No Data passed\n");
	}

	return 0;
}
