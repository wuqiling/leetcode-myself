#include <iostream>


class Solution {
public:
	//math
	//Runtime: 0 ms, faster than 100.00%
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n) {
			n = (n - 1) & n;
			++res;
		}
		return res;
	}
};

int main() {
	int ans = Solution{}.hammingWeight(3);
	return 0;
}