#include "Game.h"
#include "Input.h"
#include "Time.h"
#include <Windows.h>


int main()
{
    gameInitialize();
    Time::Initialize(); // Time �ʱ�ȭ

    LARGE_INTEGER frequency, startTime, endTime;
    QueryPerformanceFrequency(&frequency);

    while (!quit) // ���� ����
    {
        QueryPerformanceCounter(&startTime);

        Time::UpdateTime(); // Time ������Ʈ
        Input::Update();
        gameUpdate();
        gameRender();      
        
    }

    return 0;
}