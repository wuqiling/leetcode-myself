#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
	   //dp
	   //time O(N) space O(N)
	   //runtime ~0 100%
    int climbStairs(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

int main() {
    Solution s;

    int ans = s.climbStairs(7);
    return 0;
}