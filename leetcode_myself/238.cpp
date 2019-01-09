#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    // time O(N) space O(N)
    // Runtime: 40 ms, faster than 42.97%
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
		vector<int> res(n, 1);
		for (int i = 0, fromLeft = 1; i < n; i++) {
			res[i] *= fromLeft;
			fromLeft *= nums[i];
		}
		for (int i = n - 1, fromRight = 1; i >= 0; i--) {
			res[i] *= fromRight;
			fromRight *= nums[i];
		}
		return res;
    }
};

int main() {
    vector<int> nums{1, 2, 3};

    Solution s;
    vector<int> ans = s.productExceptSelf(nums);
    return 0;
}