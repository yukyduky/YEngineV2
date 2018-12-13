#include "gtest/gtest.h"
#include "sharedTestDefinitions.h"


TEST(Component, registerComponent)
{
	TestComponent testComponent;

	testComponent.registerComponent(new TestComponent, sizeof(TestComponent), "Test", 10);

	EXPECT_EQ(testComponent.getComponentBitmask(), std::bitset<YEngine::BITMASK_SIZE>(1ULL << 0));
}

TEST(Component, unregisterComponent)
{
	TestComponent testComponent;

	testComponent.registerComponent(new TestComponent, sizeof(TestComponent), "Test", 10);

	EXPECT_TRUE(testComponent.getIsRegistered());

	testComponent.unregisterComponent();

	EXPECT_FALSE(testComponent.getIsRegistered());
}