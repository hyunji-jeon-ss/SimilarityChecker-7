#include "SimilarityChecker.cpp"
#include "gmock/gmock.h"
using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	void checker(int expected, string statement1, string statement2) {
		SimilarityChecker checker;
		EXPECT_EQ(expected, checker.runChecker(statement1, statement2));
	}
};
 
TEST_F(SimilarityCheckerFixture, Test1)
{
	checker(40, "ASD", "DSA");
}

TEST_F(SimilarityCheckerFixture, Test2)
{
	checker(0, "A", "BB");
}

//TEST_F(SimilarityCheckerFixture, Test3)
//{
//	checker(20, "AAABB", "BAA");
//}



int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}