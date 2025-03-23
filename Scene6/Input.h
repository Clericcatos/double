#ifndef INPUT_H
#define INPUT_H
#include <Windows.h>

namespace Input
{
    void Update();
    bool IsKeyDown(int vKey);
    bool IsKeyPressed(int vKey);
    bool IsKeyReleased(int vKey);
}

#endif