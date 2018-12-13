#include "gtest/gtest.h"
#include "General/GameTime.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

TEST(GameTime, StartTimerAndGetTime)
{
	YEngine::GameTime gt;
	gt.StartTimer();
	Sleep(1);
	double t = gt.GetTime();
	EXPECT_GT(t, 0.0);
}

TEST(GameTime, DeltaTime)
{
	YEngine::GameTime gt;
	gt.StartTimer();
	Sleep(1);
	gt.UpdateDeltaTime();
	double t = gt.getDeltaTime();
	EXPECT_LT(t, 0.002);
	EXPECT_GT(t, 0.0);
}