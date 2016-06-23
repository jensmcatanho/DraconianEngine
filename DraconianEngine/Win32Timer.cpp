#include "Win32Timer.h"

namespace Draconian {

Win32Timer::Win32Timer() :
	Timer(),
	m_TimerMask(0) {

}


Win32Timer::~Win32Timer() {

}

void Win32Timer::reset() {
#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
	// "Retrieve the process affinity mask for the specified process and the system affinity mask for the system".
	DWORD_PTR processMask, systemMask;
	GetProcessAffinityMask(GetCurrentProcess(), &processMask, &systemMask);

	/* "If the calling process contains threads in multiple groups, the function returns zero for both affinity masks."
	   https://msdn.microsoft.com/en-us/library/windows/desktop/ms683213(v=vs.85).aspx
	   In this case, consider there is only one core available for the loop below to search it.

	   "The thread affinity mask (m_TimerMask) cannot specify a 1 bit for a processor when the process affinity
	   mask specifies a 0 bit for that processor."
	   https://msdn.microsoft.com/en-us/library/windows/desktop/ms686247(v=vs.85).aspx
	*/
	processMask = processMask ? processMask : 1;

	// Search for the lowest 1 bit of the process affinity mask to specify to the thread affinity mask.
	if (m_TimerMask == 0) {
		m_TimerMask = 1;
		
		while (!(m_TimerMask & processMask))
			m_TimerMask <<= 1;

	}

	// Set thread affinity mask to the first core of the process affinity mask.
	HANDLE thread = GetCurrentThread();
	DWORD_PTR oldMask = SetThreadAffinityMask(thread, m_TimerMask);
#endif

	// Retrieves the frequency of the performance counter (ticks-per-second).
	QueryPerformanceFrequency(&m_Frequency);
	// Retrieves the current value of the performance counter.
	QueryPerformanceCounter(&m_StartTime);
	// Retrieves the number of milliseconds that have elapsed since the system was started.
	m_StartTick = GetTickCount();

#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
	// Reset thread affinity mask.
	SetThreadAffinityMask(thread, oldMask);
#endif

	m_LastTime = 0;
	m_StartClock = clock();
}


ulong Win32Timer::getTime() {
		LARGE_INTEGER currentTime;

#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
	// Set thread affinity mask to the first core of the process affinity mask.
	HANDLE thread = GetCurrentThread();
	DWORD_PTR oldMask = SetThreadAffinityMask(thread, m_TimerMask);
#endif

	// Retrieves the current value of the performance counter.
	QueryPerformanceCounter(&currentTime);

#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
	// Reset thread affinity mask.
	SetThreadAffinityMask(thread, oldMask);
#endif
	
	// Time since the last reset.
	LONGLONG newTime = currentTime.QuadPart - m_StartTime.QuadPart;
	// Convert time to miliseconds before dividing by ticks-per-second to guard against precision loss.
	ulong newTicks = (ulong)((1000 * newTime) / m_Frequency.QuadPart);

	// Detect and compensate for frequency offsets if necessary.
	// Check https://msdn.microsoft.com/en-us/library/windows/desktop/dn553408(v=vs.85).aspx for more details.

	// Retrieves the number of milliseconds that have elapsed since the last reset.
	ulong check = GetTickCount() - m_StartTick;
	// Get the frequency offset error.
	signed long freqOffset = (signed long)(newTicks - check);

	if (freqOffset < -100 || freqOffset > 100) {
		// Needs further research
		LONGLONG adjust = std::min((freqOffset * m_Frequency.QuadPart) / 1000, newTime - m_LastTime);
		m_StartTime.QuadPart += adjust;
		newTime -= adjust;

	}

	// Save last time for the next adjust.
	m_LastTime = newTime;

	return (ulong)newTime;
}


ulong Win32Timer::getMilliseconds() {
	return (ulong)((1000 * getTime()) / m_Frequency.QuadPart);
}

ulong Win32Timer::getMillisecondsCPU() {
	clock_t newClock = clock();

	return (ulong)((float)(newClock - m_StartClock) / ((float)CLOCKS_PER_SEC / 1000.0));
}

ulong Win32Timer::getMicroseconds() {
	return (ulong)((1000000 * getTime()) / m_Frequency.QuadPart);
}

ulong Win32Timer::getMicrosecondsCPU() {
	clock_t newClock = clock();

	return (ulong)((float)(newClock - m_StartClock) / ((float)CLOCKS_PER_SEC / 1000000.0));
}

}