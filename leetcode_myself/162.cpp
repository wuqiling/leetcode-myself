#include <vector>
using std::vector;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement_method1_1(nums);
    }

   private:
    // binary search time:O(logN) space:O(1)
    // run time: 4ms 99%
    int findPeakElement_method1(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return 0;
        if (N == 2) return nums[0] < nums[1] ? 1 : 0;
        int res = 0;
        for (int l = 0, r = N - 1; l <= r;) {
            int m = l + (r - l) / 2;
            if (m - 1 >= 0 && m + 1 <= N - 1) {
                if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1])
                    return m;
                else if (nums[m - 1] > nums[m]) {
                    res = m - 1;
                    r = m - 1;
                } else {
                    res = m;
                    l = m + 1;
                }
            } else if (m == 0)
                // peak in n[0] n[1]
                return nums[0] > nums[1] ? 0 : 1;
            else  // m == N - 1
                // peak in n[N-2] n[N-1]
                return nums[m - 1] > nums[m] ? m - 1 : m;
        }
        return res;
    }
    // binary search time:O(logN) space:O(1)
    // run time: 4ms 99%
    int findPeakElement_method1_1(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid1 = (l + r) / 2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2])
                l = mid2;
            else
                r = mid1;
        }
        return l;
    }
};

int main() {
    vector<int> n = {10, 2, 1};
    Solution s;
    int ans = s.findPeakElement(n);
    return 0;
}