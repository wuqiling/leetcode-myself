#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // runtime 4ms 99%
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1, s1 = m - 1, s2 = n - 1; i >= 0; i--) {
            if (s1 >= 0 && s2 >= 0) {
                if (nums1[s1] > nums2[s2])
                    nums1[i] = nums1[s1--];
                else
                    nums1[i] = nums2[s2--];
            } else if (s1 >= 0)
                nums1[i] = nums1[s1--];
            else if (s2 >= 0)
                nums1[i] = nums2[s2--];
        }
    }

    vector<int> nums3;
};

int main() {
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};

    Solution s;
    s.merge(nums1, 3, nums2, 3);
    return 0;
}