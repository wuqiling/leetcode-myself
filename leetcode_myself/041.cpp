#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // Runtime: 4 ms, faster than 86.15%
    int firstMissingPositive(vector<int>& nums) {
        if (!nums.size()) return 1;
        if (nums.size() == 1)
            if (nums[0] <= 0 || nums[0] > 1)
                return 1;
            else
                return 2;
        int resflag = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >= 0 && nums[i] < nums.size() && nums[i] != i) {
                if (nums[i] == nums[nums[i]])
                    nums[i] = -1;
                else
                    swap(nums[i], nums[nums[i]]);
            }
            if (nums[i] != i) {
                if (nums[i] == resflag) resflag++;
                nums[i] = -1;
            }
        }
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == -1) return i;
        return resflag;
    }
};

int main() {
    vector<int> nums{1, 2};

    Solution s;
    int ans = s.firstMissingPositive(nums);
    return 0;
}