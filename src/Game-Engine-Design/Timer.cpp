
/* ------------------------------------------------

	@File		: Timer.cpp
	@Date		: 21/11/2013
	@Purpose	:

		Timer class implementation

 ------------------------------------------------ */

#include "Timer.h"

Timer::Timer() {
	// Get number of ticks per sec
	QueryPerformanceFrequency(&freq);
	WaitBuffer			= false;
	Buffer				= false;
}

bool Timer::Waitfor(int Seconds) {
	// get initial ticks
	if(!WaitBuffer) {
		WaitBuffer = true;
		Clear();	
		QueryPerformanceCounter(&start);
	}

	// check constantly until
	QueryPerformanceCounter(&end);

	// a certain time has passed
	if(GetTimeInSeconds() >= Seconds) {
		WaitBuffer = false;
		Clear();

		// return true to indicate that t secs
		// has passed
		return true;
	}

	// return false to indicate
	//that t secs has not passed
	return false;
}

void Timer::Clear() {
	start.QuadPart = NULL;
	end.QuadPart = NULL;
	Buffer = false;
}

void Timer::Start() {
	// Get Ticks
	QueryPerformanceCounter(&start);
}

void Timer::End() {
	// Get Ticks
	QueryPerformanceCounter(&end);
}

double Timer::GetTimeInSeconds() {
	// Convert To Seconds
	return(end.QuadPart - start.QuadPart)/(double)freq.QuadPart;
}

double Timer::GetTimeInMilliseconds() {
	// Convert result to Ms
	return (1.0e3*(end.QuadPart - start.QuadPart))/freq.QuadPart;
}

Timer::~Timer() {
	// No objects to delete
}