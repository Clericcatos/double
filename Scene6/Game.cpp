#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "Input.h"
#include "Time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

Scene currentScene = MENU;
Scene nextScene = MENU;
bool quit = false;
char buffer[2][HEIGHT][WIDTH + 1];
int currentBuffer = 0;

void gameInitialize()
{
    if (currentScene != nextScene)
    {
        switch (nextScene)
        {
        case MENU:
            menuInitialize();
            break;
        case PLAY:
            playInitialize();
            break;
        case END:
            Time::Initialize();
            endInitialize();
            break;
        }
        currentScene = nextScene;
    }
}

void gameUpdate()
{
    Input::Update();

    switch (nextScene)
    {
    case MENU:
        menuUpdate();
        break;
    case PLAY:
        playUpdate();
        break;
    case END:
        endUpdate();
        break;
    }

    if (currentScene != nextScene)
    {
        gameInitialize();
    }
    currentScene = nextScene;
}

void gameRender()
{
    char(*backBuffer)[WIDTH + 1] = buffer[1 - currentBuffer];
    char(*primaryBuffer)[WIDTH + 1] = buffer[currentBuffer];

    for (int i = 0; i < HEIGHT; i++)
    {
        memset(backBuffer[i], ' ', WIDTH); // 공백 문자로 버퍼 초기화
        backBuffer[i][WIDTH] = '\0';
    }

    switch (currentScene)
    {
    case MENU:
        menuRender(backBuffer);
        break;
    case PLAY:
        playRender(backBuffer);
        break;
    case END:
        endRender(backBuffer);
        break;
    }

    // 변경된 부분만 화면 버퍼로 복사 및 출력
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    DWORD written;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (primaryBuffer[i][j] != backBuffer[i][j])
            {
                coord.X = j;
                coord.Y = i;
                SetConsoleCursorPosition(hConsole, coord);
                WriteConsoleA(hConsole, &backBuffer[i][j], 1, &written, NULL);
                primaryBuffer[i][j] = backBuffer[i][j];
            }
        }
    }

    currentBuffer = 1 - currentBuffer;
}