#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include<Windows.h>

#define WIDTH 80
#define HEIGHT 25

typedef enum {
	MENU,
	PLAY,
	END
}Scene;

extern Scene currentScene;
extern Scene nextScene;
extern bool quit;

void gameInitialize();
void gameUpdate();
void gameRender();

#endif