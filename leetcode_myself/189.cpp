#include <vector>
using std::swap;
using std::vector;

class Solution {
   public:
    // time O(N) space O(1)
    // runtime 12ms 100%
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n < 2 || k < 1 || !(k % n)) return;
        if (k > n) k = k % n;
        int rest = n - k;
        for (int i = 0; i < rest / 2; i++) swap(nums[i], nums[rest - i - 1]);
        for (int i = 0; i < k / 2; i++) swap(nums[rest + i], nums[n - i - 1]);
        for (int i = 0; i < n / 2; i++) swap(nums[i], nums[n - i - 1]);
    }
};

int main() {
    vector<int> nums{1, 2};

    Solution s;
    s.rotate(nums, 2);
    return 0;
}