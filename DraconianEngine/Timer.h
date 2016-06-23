#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Timer {
	public:
		Timer();
		~Timer();

		virtual void reset() = 0;
		virtual ulong getMilliseconds() = 0;
		virtual ulong getMillisecondsCPU() = 0;
		virtual ulong getMicroseconds() = 0;
		virtual ulong getMicrosecondsCPU() = 0;

	protected:
		virtual ulong getTime() = 0;
};

}