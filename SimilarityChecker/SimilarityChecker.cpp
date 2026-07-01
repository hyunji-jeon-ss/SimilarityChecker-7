#include <string>
using std::string;
#include <vector>
#include <set>
using std::vector;
using std::set;

#define MAX_LENGTH_SCORE 60
#define MIN_LENGTH_SCORE 0

class SimilarityChecker {
public:
	int runChecker(const string& str1, const string& str2) {
		int lengthScore = getLengthScore(str1, str2);
		int alphabetScore = getAlphabetScore(str1, str2);
		return lengthScore + alphabetScore;
	}
	int getAlphabetScore(const std::string& str1, const std::string& str2)
	{
		set<char> alphabet1, alphabet2;
		for (char alpha : str1)
			alphabet1.insert(alpha);
		for (char alpha : str2)
			alphabet2.insert(alpha);

		int sameAlphabetCount = 0;
		for (char alpha : alphabet2)
		{
			if (alphabet1.contains(alpha))
				sameAlphabetCount++;
		}
		int totalAlphabetCount = alphabet1.size() + alphabet2.size() - sameAlphabetCount;
		return static_cast<double>(sameAlphabetCount) / totalAlphabetCount * 40;
		
	}
	int getLengthScore(const std::string& str1, const std::string& str2)
	{
		longer = std::max(str1.length(), str2.length());
		shorter = std::min(str1.length(), str2.length());
		if (isEqualStringLength())
			return MAX_LENGTH_SCORE;
		if (isDouble())
			return MIN_LENGTH_SCORE;
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