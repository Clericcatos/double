#ifndef TIME_H
#define TIME_H

#include <windows.h>

namespace Time
{
    extern LARGE_INTEGER frequency;
    extern LARGE_INTEGER prevCounter;
    extern LARGE_INTEGER currentCounter;
    extern LARGE_INTEGER initCounter;
    extern float deltaTime;

    void Initialize();
    void UpdateTime();
    float GetElapsedTime();
    float GetTotalTime();
}

#endif // TIME_H