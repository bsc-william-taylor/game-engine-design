
#include "Timer.h"

Timer::Timer()
{
    QueryPerformanceFrequency(&freq);
    waitBuffer = false;
    bufferEnabled = false;
}

Timer::~Timer()
{
}

bool Timer::waitFor(int seconds)
{
    if (!waitBuffer)
    {
        waitBuffer = true;
        clear();
        QueryPerformanceCounter(&startTime);
    }

    QueryPerformanceCounter(&endTime);

    if (getTimeInSeconds() >= seconds)
    {
        waitBuffer = false;
        clear();
        return true;
    }

    return false;
}

void Timer::clear()
{
    startTime.QuadPart = NULL;
    endTime.QuadPart = NULL;
    bufferEnabled = false;
}

void Timer::start()
{
    QueryPerformanceCounter(&startTime);
}

void Timer::end()
{
    QueryPerformanceCounter(&endTime);
}

double Timer::getTimeInSeconds()
{
    return(endTime.QuadPart - startTime.QuadPart) / (double)freq.QuadPart;
}

double Timer::getTimeInMilliseconds()
{
    return (1.0e3*(endTime.QuadPart - startTime.QuadPart)) / freq.QuadPart;
}