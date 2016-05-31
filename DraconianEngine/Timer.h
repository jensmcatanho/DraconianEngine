#pragma once

#include <Windows.h>

namespace Draconian {

class Timer {
	public:
		Timer();
		~Timer();

		void reset();
		float elapsed();

	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
};

}