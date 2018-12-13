#include "GameTime.h"
#include <dwrite.h>


namespace YEngine
{
	GameTime::GameTime()
	{
		m_Frequency = 0.0;
		m_CounterStart = 0;
		m_PrevCount = 0;
		m_DeltaTime = 0.0;
	}
	
	void GameTime::StartTimer()
	{
		LARGE_INTEGER currentCount;
		// Gets the frequency of the performance counter which is fixed at boot and only needed to be stored once
		QueryPerformanceFrequency(&currentCount);
		m_Frequency = static_cast<float>(currentCount.QuadPart);
	
		// Get the current value of the performance counter since boot
		QueryPerformanceCounter(&currentCount);
		m_CounterStart = currentCount.QuadPart;
		QueryPerformanceCounter(&currentCount);
		m_PrevCount = currentCount.QuadPart;
	}
	
	float GameTime::GetTime()
	{
		LARGE_INTEGER currentCount;
	
		QueryPerformanceCounter(&currentCount);
		return static_cast<float>(currentCount.QuadPart - m_CounterStart) / m_Frequency;
	}
	
	void GameTime::UpdateDeltaTime()
	{
		LARGE_INTEGER currentCount;
		__int64 frameCount = 0;
	
		QueryPerformanceCounter(&currentCount);
	
		// Gets the count since last frame
		frameCount = currentCount.QuadPart - m_PrevCount;
		// Stores the current count for the next frame
		m_PrevCount = currentCount.QuadPart;
	
		// Count divided by frequency equals time in milliseconds
		m_DeltaTime = static_cast<float>(frameCount) / m_Frequency;
	}
	
	const float GameTime::getDeltaTime()
	{
		return m_DeltaTime;
	}
}
