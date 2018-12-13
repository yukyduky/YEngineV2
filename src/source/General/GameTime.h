#pragma once

namespace YEngine
{
	class GameTime
	{
	private:
		float m_Frequency;
		__int64 m_CounterStart;
		__int64 m_PrevCount;
		float m_DeltaTime;
	
	public:
		GameTime();
		virtual ~GameTime() {}

		void StartTimer();
		float GetTime();
		void UpdateDeltaTime();
		const float getDeltaTime();
	};
}
