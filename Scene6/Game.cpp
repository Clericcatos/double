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
char buffer[2][HEIGHT][WIDTH + 1];  // 텍스트 버퍼
int currentBuffer = 0;
HANDLE hScreenBuffer[2];  // 콘솔 화면 버퍼


void gameInitialize()
{
    hScreenBuffer[0] = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);

    hScreenBuffer[1] = CreateConsoleScreenBuffer(
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL);

    SetConsoleActiveScreenBuffer(hScreenBuffer[currentBuffer]);
}

void gameUpdate()
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
            endInitialize();
            break;
        }
        currentScene = nextScene;
    }

    switch (currentScene)
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
}

void gameRender()
{
    char(*backBuffer)[WIDTH + 1] = buffer[1 - currentBuffer];

    // 버퍼 초기화
    for (int i = 0; i < HEIGHT; i++)
    {
        memset(backBuffer[i], ' ', WIDTH);
        backBuffer[i][WIDTH] = '\0';
    }

    // 씬 렌더링
    switch (currentScene)
    {
    case MENU: menuRender(backBuffer); break;
    case PLAY: playRender(backBuffer); break;
    case END: endRender(backBuffer); break;
    }

    // 콘솔 화면 버퍼로 데이터 출력
    DWORD charsWritten;

    for (int i = 0; i < HEIGHT; i++)
    {
        COORD coord;
        coord.X = 0;
        coord.Y = (SHORT)i; // (SHORT) 캐스팅 (정상적인 변환인지 확인)

        // 버퍼 핸들 체크
        if (hScreenBuffer[1 - currentBuffer] != INVALID_HANDLE_VALUE)
        {
            if (!WriteConsoleOutputCharacterA(hScreenBuffer[1 - currentBuffer], backBuffer[i], WIDTH, coord, &charsWritten))
            {
                printf("WriteConsoleOutputCharacterA failed! Error code: %lu\n", GetLastError());
            }
        }
    }

    // 콘솔 버퍼 변경
    SetConsoleActiveScreenBuffer(hScreenBuffer[1 - currentBuffer]);
    currentBuffer = 1 - currentBuffer;
}

void gameShutdown()
{
    // 콘솔 화면 버퍼 해제
    CloseHandle(hScreenBuffer[0]);
    CloseHandle(hScreenBuffer[1]);
}