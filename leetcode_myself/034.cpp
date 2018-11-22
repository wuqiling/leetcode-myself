#include <vector>

using std::vector;

class Solution {
   public:
    // time:O(logN) space:O(1)
    vector<int> searchRange(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N == 0) return {-1, -1};
        // left
        int ansL = -1;
        for (int l = 0, r = N - 1; l <= r;) {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else {
                r = m - 1;
                if (nums[m] == target) ansL = m;
            }
        }
        if (ansL == -1) return {-1, -1};
        // right
        int ansR = 0;
        for (int l = 0, r = N - 1; l <= r;) {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
                r = m - 1;
            else {
                l = m + 1;
                if (nums[m] == target) ansR = m;
            }
        }
        return {ansL, ansR};
    }
};

int main() {
    vector<int> n = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int> ans = s.searchRange(n, 8);
    return 0;
}