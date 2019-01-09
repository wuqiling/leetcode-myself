#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   public:
    int singleNumber(vector<int> &nums) { return singleNumber_2(nums); }

   private:
    // hash map
    // time O(N) space O(N)
    // Runtime: 16 ms 35%
    int singleNumber_1(vector<int> &nums) {
        unordered_map<int, int> h;
        for (int &n : nums) ++h[n];
        for (auto &kv : h)
            if (kv.second == 1) return kv.first;
        return 0;
    }

    // time O(N) space O(1)
    // Runtime: 8 ms, faster than 98.70%
    int singleNumber_2(vector<int> &nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int res = nums[0];
        for (int i = 1; i < n; i++) res ^= nums[i];
        return res;
    }
};

int main() {
    vector<int> nums{4, 1, 2, 1, 2};

    Solution s;
    int ans = s.singleNumber(nums);
    return 0;
}