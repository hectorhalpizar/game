#ifndef __GAME_BOOT_H__
#define __GAME_BOOT_H__

#define BOOT_GAME "BootGame"

#ifdef __cplusplus
extern "C" {
#endif

///
// Boots the Game
//		data - Pases any type of data that is going the game.
int BootGame(void * data);

#ifdef __cplusplus
}
#endif

#endif // __GAME_BOOT_H__