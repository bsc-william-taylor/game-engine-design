
/* ------------------------------------------------

	@File		: Timer.h
	@Date		: 21/11/2013
	@Purpose	:

		A simple timer class that use
		the high resolution windows timer

 ------------------------------------------------ */

#pragma once

#include "Main.h"

class Timer {
	private:

		LARGE_INTEGER start;
		LARGE_INTEGER freq;
		LARGE_INTEGER end;

		bool WaitBuffer;
		bool Buffer;

	public:

	Timer();
		
		double GetTimeInMilliseconds();
		double GetTimeInSeconds();

		bool Waitfor(int);

		void Start();
		void Clear();
		void End();

	~Timer();
};

