#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLIS_binarySearch(nums);
    }

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

    // loop+binary search method: time:O(NlogN) space:O(N)
    // time ~0 100%
    // input:[0,8,4,12,2]
    // dp:[0]
    // dp:[0,8]
    // dp:[0,4]
    // dp:[0,4,12]
    // dp:[0,2,12]
    // ret=dp.size
    int lengthOfLIS_binarySearch(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) return 0;

        vector<int64_t> dp(N + 1, (1LL << 40));
        int res = 0;
        dp[0] = -(1LL << 40);
        for (int i = 0; i < N; i++) {
            int ans = 0;
            for (int l = 0, r = res; l <= r;) {
                int mid = (l + r) >> 1;
                if (nums[i] > dp[mid]) {
                    ans = mid;
                    l = mid + 1;
                } else
                    r = mid - 1;
            }
            dp[ans + 1] = min(dp[ans + 1], (int64_t)nums[i]);
            res = max(res, ans + 1);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0, 8, 4, 12, 2};
    Solution s;
    int ans = s.lengthOfLIS(nums);
    return 0;
}