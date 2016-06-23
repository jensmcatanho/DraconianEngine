#pragma once

#include "Timer.h"

#ifndef WIN32_LEAN_AND_MEAN
#   define WIN32_LEAN_AND_MEAN
#endif
#if !defined(NOMINMAX) && defined(_MSC_VER)
#   define NOMINMAX
#endif
#include <Windows.h>

#if 0
namespace Draconian {

class Win32Timer : public Timer {
	public:
		Win32Timer();
		~Win32Timer();

		void reset() override;
		ulong getMilliseconds() override;
		ulong getMillisecondsCPU() override;
		ulong getMicroseconds() override;
		ulong getMicrosecondsCPU() override;
		
	protected:
		ulong getTime() override;
		
    private:
        clock_t m_StartClock;

        DWORD m_StartTick;
        LONGLONG m_LastTime;
        LARGE_INTEGER m_StartTime;
        LARGE_INTEGER m_Frequency;

#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
        DWORD_PTR m_TimerMask;
#endif
};

}
#endif