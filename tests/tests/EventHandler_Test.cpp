#include "gtest/gtest.h"
#include "General/EventHandler.h"


TEST(EventHandler, pollEventNoEvent)
{
	YEngine::EventHandler eh;
	YEngine::Event evOut;
	EXPECT_FALSE(eh.pollEvent(evOut));
}

TEST(EventHandler, addAndPollEvent)
{
	YEngine::EventHandler eh;
	YEngine::Event evIn(YEngine::EVENT::GAMEOVER, 0);
	YEngine::Event evOut;

	eh.addEvent(evIn);

	EXPECT_TRUE(eh.pollEvent(evOut));

	EXPECT_EQ(evIn.event, evOut.event);
	EXPECT_EQ(evIn.param, evOut.param);
}
