
#pragma once

#include "Main.h"

class Timer
{
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
    LARGE_INTEGER freq;

    bool bufferEnabled;
    bool waitBuffer;
public:
    Timer();
    ~Timer();

    double getTimeInMilliseconds();
    double getTimeInSeconds();

    bool waitFor(int);

    void start();
    void clear();
    void end();
};

