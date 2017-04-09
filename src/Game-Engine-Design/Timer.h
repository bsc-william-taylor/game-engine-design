
#pragma once

#include "Main.h"

class Timer
{
    LARGE_INTEGER start;
    LARGE_INTEGER freq;
    LARGE_INTEGER end;

    bool WaitBuffer;
    bool Buffer;
public:
    Timer();
    ~Timer();

    double GetTimeInMilliseconds();
    double GetTimeInSeconds();

    bool Waitfor(int);

    void Start();
    void Clear();
    void End();
};

