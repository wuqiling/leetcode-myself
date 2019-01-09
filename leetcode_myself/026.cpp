#include <iostream>
#include <vector>

using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // runtime 16ms 99%
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (i < nums.size() && nums[i - 1] == nums[i]) i++;
            if (i == nums.size()) return ans + 1;
            nums[++ans] = nums[i];
        }
        return ans + 1;
    }
};

int main() {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution s;
    int ans = s.removeDuplicates(nums);
    return 0;
}