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



int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}