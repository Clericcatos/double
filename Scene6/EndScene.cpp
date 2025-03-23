#include "EndScene.h"
#include "Game.h"
#include "Time.h"
#include "Input.h"
#include <stdio.h>
#include <Windows.h>

#define END_SCENE_DURATION 5.0f

float endSceneStartTime;

void endInitialize()
{
   endSceneStartTime = Time::GetTotalTime();   
}

void endUpdate()
{
    float elapsedTime = Time::GetTotalTime() - endSceneStartTime;  

    if (GetAsyncKeyState('E') & 0x8000) { // E Ű�� ���ȴ��� Ȯ��
        endSceneStartTime = Time::GetTotalTime(); // E Ű�� ���� ������ Ÿ�̸� �ʱ�ȭ        
    }

    if (Time::GetTotalTime() - endSceneStartTime >= END_SCENE_DURATION) { // 5�� ��� �� �޴� �� ��ȯ
        nextScene = MENU;
        printf("nextScene: MENU\n");
    }
}

void endRender(char buffer[][81])
{
    // Clear the buffer with spaces to prevent unwanted characters
    for (int i = 0; i < HEIGHT; i++)
    {
        memset(buffer[i], ' ', WIDTH);
        buffer[i][WIDTH] = '\0'; // Ensure null termination
    }

    float remainingTime = END_SCENE_DURATION - (Time::GetTotalTime() - endSceneStartTime);

    snprintf(buffer[10] + 30, WIDTH - 30 - 1, "Time left: %.1f sec ", remainingTime);
    snprintf(buffer[12] + 30, WIDTH - 30 - 1, "Auto return to the menu");
    snprintf(buffer[14] + 30, WIDTH - 30 - 1, "Press 'E' to return immediately. ");
}