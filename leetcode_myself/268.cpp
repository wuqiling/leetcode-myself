#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // runtime 4ms 100%
    int missingNumber(vector<int>& nums) { return missingNumber_3(nums); }

   private:
    // time O(N) space O(1)
    // runtime 4ms 100%
    int missingNumber_1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i && nums[i] != -1) {
                if (nums[i] == nums.size())
                    nums[i] = -1;
                else
                    swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == -1) return i;
        return nums.size();
    }

    // xor
    // time O(N) space O(1)
    int missingNumber_2(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i <= nums.size(); i++) res = res ^ i ^ nums[i - 1];
        return res;
    }

    // sum
    // potential to cause overflow
    // time O(N) space O(1)
    int missingNumber_3(vector<int>& nums) {
        int n = nums.size();
        int64_t sum = 0;
        for (const auto& num : nums) sum += num;
        return n * (n + 1) / 2 - sum;
    }
};

int main() {
    vector<int> nums{1, 0, 2};

    Solution s;
    int ans = s.missingNumber(nums);
    return 0;
}