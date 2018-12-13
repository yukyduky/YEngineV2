#include "gtest/gtest.h"
#include "General/IDHandler.h"

struct IDHandlerTest
{
	IDHandler handler;

	IDHandlerTest() : handler(10, 0)
	{

	}
};

TEST(IDHandler, idInUse)
{
	IDHandlerTest idt;

	EXPECT_FALSE(idt.handler.idInUse(0));

	idt.handler.getNewID();

	EXPECT_TRUE(idt.handler.idInUse(0));
}

TEST(IDHandler, getNrOfIDs)
{
	IDHandlerTest idt;

	EXPECT_EQ(idt.handler.getNrOfIDs(), 10);
}

TEST(IDHandler, peekNextID)
{
	IDHandlerTest idt;

	EXPECT_EQ(idt.handler.peekNextID(), 0);
}

TEST(IDHandler, empty)
{
	IDHandlerTest idt;

	EXPECT_TRUE(idt.handler.empty());

	idt.handler.getNewID();

	EXPECT_FALSE(idt.handler.empty());
}

TEST(IDHandler, getNewID)
{
	IDHandlerTest idt;

	EXPECT_EQ(idt.handler.getNewID(), 0);
}

TEST(IDHandler, clear)
{
	IDHandlerTest idt;

	idt.handler.clear();

	EXPECT_TRUE(idt.handler.empty());
}

TEST(IDHandler, remove)
{
	IDHandlerTest idt;

	for (size_t i = 0; i < 10; i++)
	{
		idt.handler.getNewID();
	}

	EXPECT_TRUE(idt.handler.remove(4));
	EXPECT_FALSE(idt.handler.remove(16));

	EXPECT_EQ(idt.handler.peekNextID(), 4);
	EXPECT_EQ(idt.handler.getNrOfIDs(), 9);
}