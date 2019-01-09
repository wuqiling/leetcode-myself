#include <string>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
	//hashtable
	//time O(M+N) space O(1)
	//Runtime: 4 ms, faster than 98.98%
	int numJewelsInStones(string J, string S) {
		vector<int>jtb(256, 0);
		for (const auto &j : J)
			jtb[j] = 1;
		int res = 0;
		for (const auto &s : S)
			if (jtb[s]) ++res;
		return res;
	}
};