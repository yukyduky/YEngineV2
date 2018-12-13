#include "gtest/gtest.h"
#include "General/ComponentManager.h"
#include "sharedTestDefinitions.h"


struct CMTest
{
	TestComponent testComponent;
	YEngine::ComponentManager cm;

	CMTest()
	{
		testComponent.registerComponent(new TestComponent, sizeof(TestComponent), "Test", 10);
	}
};

TEST(ComponentManager, addAndRemoveEntity)
{
	YEngine::Component* testC = nullptr;
	CMTest cmt;
	
	size_t id = cmt.cm.addEntity(cmt.testComponent.getComponentBitmask());

	EXPECT_TRUE(cmt.cm.getComponentFromEntity(id, cmt.testComponent.getComponentBitmask(), testC));

	cmt.cm.removeEntity(id);

	EXPECT_FALSE(cmt.cm.getComponentFromEntity(id, cmt.testComponent.getComponentBitmask(), testC));
}
