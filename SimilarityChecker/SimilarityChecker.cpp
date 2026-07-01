#include <string>
using std::string;

class SimilarityChecker {
public:
	int runChecker(const string& str1, const string& str2) {
		longer = std::max(str1.length(), str2.length());
		shorter = std::min(str1.length(), str2.length());
		if (isEqualStringLength())
			return 60;
		if (isDouble())
			return 0;
		return getScore();
	}
	double getScore()
	{
		return (1 - static_cast<double>(longer - shorter) / shorter) * 60;
	}
	bool isDouble()
	{
		if (longer >= 2 * shorter)
			return true;
		return false;
	}
	bool isEqualStringLength()
	{
		if (longer == shorter)
			return true;
		return false;
	}
private:
	int longer;
	int shorter;
};