#include <iostream>

class Solution {
   public:
    // time O(logN) space O(1)
    // Runtime: 12 ms, faster than 40.50%
    int trailingZeroes(int n) {
        if (n <= 0) return 0;
        int64_t res = 0;
        for (int64_t i = 5; n / i > 0; i *= 5) res += n / i;
        return res;
    }
};

int main() {
    int ans = Solution().trailingZeroes(30);
    return 0;
}