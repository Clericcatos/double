#include "MenuScene.h"
#include "Game.h"
#include <stdio.h>
#include <Windows.h>

int MENUX = WIDTH / 2;
int MENUY = HEIGHT / 2;


void menuInitialize()
{
    MENUX = WIDTH / 2;
    MENUY = HEIGHT / 2;
}

void menuUpdate()
{
	if (GetAsyncKeyState('P') & 0x8000)
	{
		nextScene = PLAY;// �÷��� �� ��ȯ
	}

	else if (GetAsyncKeyState('E') & 0x8000)
	{
		nextScene = END;// �÷��� �� ��ȯ
	}
}

void menuRender(char buffer[][81])
{
	memcpy_s(buffer[10] + 50, WIDTH - 50, "MENU", strlen("MENU"));
	memcpy_s(buffer[12] + 40, WIDTH - 40, "Press 'P' Button PLAY", strlen("Press 'P' Button PLAY"));
	memcpy_s(buffer[14] + 40, WIDTH - 40, "Press'E' Button EXIT", strlen("Press 'E' Button EXIT"));
}
