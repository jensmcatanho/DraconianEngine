#pragma once

#include "Prerequisites.h"

namespace Draconian {

class Timer {
	public:
		Timer();
		~Timer();

		void reset();
		virtual unsigned long getMilliseconds() = 0;
		virtual unsigned long getMillisecondsCPU() = 0;
		virtual unsigned long getMicroseconds() = 0;
		virtual unsigned long getMicrosecondsCPU() = 0;
};

}