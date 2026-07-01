#include <string>
using std::string;

class SimilarityChecker {
public:
	int runChecker(const string& str1, const string& str2) {
		int len1 = str1.length();
		int len2 = str2.length();
		if (len1 == len2)
			return 60;
		else return 0;
	}
};