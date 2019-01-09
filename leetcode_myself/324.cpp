#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // Runtime: 124 ms, faster than 11.24%
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = kthElement(nums, n / 2);

        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[newIndex(i, n)] > mid)
                swap(nums[newIndex(left++, n)], nums[newIndex(i++, n)]);
            else if (nums[newIndex(i, n)] < mid)
                swap(nums[newIndex(right--, n)], nums[newIndex(i, n)]);
            else
                i++;
        }
    }

   private:
    int newIndex(int index, int n) { return (1 + 2 * index) % (n | 1); }
    int kthElement(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = n - 1;
        if (k < start || k > end) return -1;
        while (1) {
            int kth = partion(nums, start, end);
            if (kth == k)
                return nums[kth];
            else if (kth > k)
                end = kth - 1;
            else
                start = kth + 1;
        }
    }
    int partion(vector<int>& nums, int start, int end) {
        int pivote = nums[end];
        int l = start, r = end - 1;
        while (l <= r) {
            if (nums[l] >= pivote)
                ++l;
            else if (nums[r] <= pivote)
                --r;
            else
                swap(nums[l++], nums[r--]);
        }
        swap(nums[end], nums[l]);
        return l;
    }
};

int main() {
    vector<int> nums{2, 4, 6, 1, 7};
    Solution().wiggleSort(nums);
    return 0;
}