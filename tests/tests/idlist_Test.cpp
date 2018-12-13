#include "gtest/gtest.h"
#include "General/idlist.h"

const int ID_TEST_SIZE = 10;

struct idlistTest
{
	idlist<float> listTest;

	idlistTest() : listTest(ID_TEST_SIZE)
	{
		for (int i = 0; i < ID_TEST_SIZE; i++)
		{
			listTest.push(static_cast<float>(i));
		}
	}
};

TEST(idlist, loopContainer)
{
	idlistTest idt;
	for (size_t i = 0; i < idt.listTest.size(); i++)
	{
		EXPECT_EQ(static_cast<float>(i), idt.listTest[i]);
	}
}

TEST(idlist, push)
{
	idlist<float> idTest;

	idTest.push(1.0f);

	EXPECT_EQ(idTest[0], 1.0f);
}

TEST(idlist, remove)
{
	idlistTest idt;

	idt.listTest.remove(5);
	EXPECT_EQ(idt.listTest[5], 9.0f);
}

TEST(idlist, reserveCapacitySize)
{
	idlist<float> idTest;

	idTest.reserve(ID_TEST_SIZE);

	EXPECT_EQ(idTest.capacity(), ID_TEST_SIZE);
	EXPECT_EQ(idTest.size(), 0);

	idlistTest idt;

	EXPECT_EQ(idTest.capacity(), ID_TEST_SIZE);
	EXPECT_EQ(idt.listTest.size(), ID_TEST_SIZE);
}

TEST(idlist, getElementByID)
{
	idlistTest idt;

	float f = idt.listTest.getElementByID(5);

	EXPECT_EQ(f, 5.0f);

	idt.listTest.remove(5);

	EXPECT_THROW(idt.listTest.getElementByID(5), std::out_of_range);
}

TEST(idlist, peekNextID)
{
	idlist<float> idTest;

	EXPECT_THROW(idTest.peekNextID(), std::out_of_range);

	idTest.reserve(5);
	size_t id = idTest.peekNextID();

	EXPECT_EQ(id, 0);
}

TEST(idlist, empty)
{
	idlistTest idt;
	idlist<float> idTest;

	EXPECT_FALSE(idt.listTest.empty());
	EXPECT_TRUE(idTest.empty());
}

TEST(idlist, clear)
{
	idlistTest idt;

	idt.listTest.clear();

	EXPECT_EQ(idt.listTest.size(), 0);
	EXPECT_EQ(idt.listTest.capacity(), 10);
}