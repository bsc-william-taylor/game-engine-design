
#include "Timer.h"

Timer::Timer()
{
    QueryPerformanceFrequency(&freq);
    WaitBuffer = false;
    Buffer = false;
}

Timer::~Timer()
{
}

bool Timer::Waitfor(int seconds)
{
    if (!WaitBuffer)
    {
        WaitBuffer = true;
        Clear();
        QueryPerformanceCounter(&start);
    }

    QueryPerformanceCounter(&end);

    if (GetTimeInSeconds() >= seconds)
    {
        WaitBuffer = false;
        Clear();
        return true;
    }

    return false;
}

void Timer::Clear()
{
    start.QuadPart = NULL;
    end.QuadPart = NULL;
    Buffer = false;
}

void Timer::Start()
{
    QueryPerformanceCounter(&start);
}

void Timer::End()
{
    QueryPerformanceCounter(&end);
}

double Timer::GetTimeInSeconds()
{
    return(end.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

double Timer::GetTimeInMilliseconds()
{
    return (1.0e3*(end.QuadPart - start.QuadPart)) / freq.QuadPart;
}