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
extern HANDLE hScreenBuffer[2];
extern int currentBuffer;
extern char buffer[2][HEIGHT][WIDTH + 1];

void gameInitialize();
void gameUpdate();
void gameRender();

#endif