#include "gtest/gtest.h"
#include "General/MemoryManager.h"

struct MemoryTest
{
	MemoryManager mm;
	float num;
	float* ptr;

	MemoryTest() : mm(4, 16), num(5.0f), ptr(nullptr)
	{
		mm.requestMemory(ptr, &num, sizeof(float));
	}
};

TEST(MemoryManager, requestMemory)
{
	MemoryTest mt;

	EXPECT_EQ(5.0f, *mt.ptr);
}

TEST(MemoryManager, releaseMemory)
{
	MemoryTest mt;
	mt.mm.releaseMemory(mt.ptr);

	EXPECT_EQ(5.0f, *mt.ptr);

	mt.num = 6.0f;
	float* ptr = nullptr;
	mt.mm.requestMemory(ptr, &mt.num, sizeof(float));

	EXPECT_EQ(6.0f, *mt.ptr);
	EXPECT_EQ(6.0f, *ptr);
}

TEST(MemoryManager, resizeMemory)
{
	MemoryTest mt;
	mt.mm.resizeMemory(8, 8);
	EXPECT_NE(5.0f, *mt.ptr);
}

TEST(MemoryManager, resetMemory)
{
	MemoryTest mt;
	mt.mm.resetMemory();

	EXPECT_EQ(5.0f, *mt.ptr);

	mt.num = 6.0f;
	float* ptr;
	mt.mm.requestMemory(ptr, &mt.num, sizeof(float));

	EXPECT_EQ(6.0f, *mt.ptr);
}

TEST(MemoryManager, defrag)
{
	MemoryTest mt;
	float* ptr1;
	float* ptr2;
	float num1 = 6.0f;
	float num2 = 7.0f;

	mt.mm.requestMemory(ptr1, &num1, sizeof(float));
	mt.mm.requestMemory(ptr2, &num2, sizeof(float));
	mt.mm.releaseMemory(ptr1);
	mt.mm.defrag();

	EXPECT_EQ(7.0f, *ptr1);
}
