#include <string>
using std::string;

class SimilarityChecker {
public:
	int runChecker(const string& str1, const string& str2) {
		int len1 = str1.length();
		int len2 = str2.length();
		int longer = std::max(len1, len2);
		int shorter = std::min(len1, len2);	
		if (len1 == len2)
			return 60;
		else
			if (longer - shorter == shorter)
				return 0;
			else
				return (1 - static_cast<double>(longer - shorter) / shorter) * 60;
	}
};