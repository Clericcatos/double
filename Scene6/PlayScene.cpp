#include "PlayScene.h"
#include "Game.h"
#include "Game.h"
#include <stdio.h>
#include <Windows.h>

int playerX = WIDTH / 2;
int playerY = HEIGHT / 2;

void playInitialize() 
{	
	playerX = WIDTH / 2;
	playerY = HEIGHT / 2;
}

void playUpdate()
{
	if (GetAsyncKeyState('M') & 0x8000)
	{
		nextScene = MENU;// �޴� �� ��ȯ
	}

	else if (GetAsyncKeyState('E') & 0x8000)
	{
		nextScene = END;// ���� �� ��ȯ
	}
}

void playRender(char buffer[][81]) {
	memcpy_s(buffer[10] + 50, WIDTH - 50, "PLAY", strlen("PLAY"));
	memcpy_s(buffer[12] + 43, WIDTH - 40, "Press 'M' Button MENU", strlen("Press 'M' Button MENU"));
	memcpy_s(buffer[14] + 43, WIDTH - 40, "Press'E' Button END", strlen("Press 'E' Button END"));
}