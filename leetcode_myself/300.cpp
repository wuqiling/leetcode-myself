#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) { return lengthOfLIS_dp(nums); }

   private:
    // dp time:O(N^2) space:O(N) 16ms 55%
    int lengthOfLIS_dp(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) return 0;

        vector<int> dp(N, 1);  // dp[i]: lis end with i
        int res = 1;
        for (int i = 1; i < N; i++) {
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] < nums[i]) dp[i] = max(dp[j] + 1, dp[i]);
            res = max(res, dp[i]);
        }

        return res;
    }

    int max(int a, int b) { return a > b ? a : b; }
};

int main() {
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    Solution s;
    int ans = s.lengthOfLIS(nums);
    return 0;
}