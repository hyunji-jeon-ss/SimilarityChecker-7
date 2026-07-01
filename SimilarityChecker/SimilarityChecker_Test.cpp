#include "SimilarityChecker.cpp"
#include "gmock/gmock.h"
using namespace testing;

TEST(SimilarityCheckerTest, Test1)
{
	SimilarityChecker checker;
	int result = checker.runChecker("ASD", "DSA");
	int expected = 60;

	EXPECT_EQ(expected, result);
}

TEST(SimilarityCheckerTest, Test2)
{
	SimilarityChecker checker;
	int result = checker.runChecker("A", "BB");
	int expected = 00;

	EXPECT_EQ(expected, result);
}

TEST(SimilarityCheckerTest, Test3)
{
	SimilarityChecker checker;
	int result = checker.runChecker("AAABB", "BAA");
	int expected = 20;

	EXPECT_EQ(expected, result);
}



int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}