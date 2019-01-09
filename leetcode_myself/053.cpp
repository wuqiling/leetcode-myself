#include <algorithm>
#include <iostream>
#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) { return maxSubArray_2(nums); }

   private:
    // time space O(N) space O(1)
    // runtime 4ms 100%
    int maxSubArray_1(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int res = nums[0],sum=nums[0];

		for (int i = 1; i < nums.size(); i++) {
			sum = max(sum, sum + nums[i]);
			res = max(sum, res);
		}
		return res;
    }

    // dp
    // time space O(N) space O(N)
    // runtime 8ms 66%
    int maxSubArray_2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution s;
    int ans = s.maxSubArray(nums);
    return 0;
}