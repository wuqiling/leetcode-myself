#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // Runtime: 0 ms, faster than 100.00%
    int rob(vector<int>& nums) {
        int res = 0, dp = 0, dp0 = 0, dp1 = 0, dp2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp = max(dp1 + nums[i], dp2 + nums[i]);
            res = max(res, dp);

            dp2 = dp1;
            dp1 = dp0;
            dp0 = dp;
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3, 1};
    int ans = Solution{}.rob(nums);
    return 0;
}