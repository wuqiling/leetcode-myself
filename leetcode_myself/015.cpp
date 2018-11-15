#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int low = i + 1, high = N - 1, sum = -nums[i];
            while (low < high) {
                if (nums[low] + nums[high] == sum) {
                    result.push_back({nums[i], nums[low], nums[high]});
					//
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    while (low < high && nums[high] == nums[high - 1]) high--;
                    low++;
                    high--;
                } else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = s.threeSum(num);
    return 0;
}