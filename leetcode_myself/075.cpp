#include <algorithm>
#include <iostream>
#include <vector>
using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // runtime 4ms 36%
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[r] == 2) r--;
        while (l < r && nums[l] == 0) l++;
        if (l == r) return;
        int m = l;
        while (m <= r) {
            if (nums[m] == 1)
                m++;
            else if (nums[m] == 0)
                swap(nums[l++], nums[m++]);
            else
                swap(nums[m], nums[r--]);  // nums[m]=2
        }
    }
};

int main() {
    vector<int> nums{2, 0, 1};

    Solution s;
    s.sortColors(nums);
    return 0;
}