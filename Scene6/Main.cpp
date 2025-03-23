#include "Game.h"
#include "Input.h"
#include "Time.h"
#include <Windows.h>

int main()
{
    gameInitialize();
    Time::Initialize(); // Time 초기화

    LARGE_INTEGER frequency, startTime, endTime;
    QueryPerformanceFrequency(&frequency);

    while (!quit) // 게임 루프
    {
        QueryPerformanceCounter(&startTime);

        Time::UpdateTime(); // Time 업데이트
        Input::Update();
        gameUpdate();
        gameRender();      
        
    }

    return 0;
}