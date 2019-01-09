#include <algorithm>
#include <vector>

using std::vector;

class Solution {
   public:
    // backtracking recursion
    // time: O(2^N) space: O(N)
    // runtime 4ms 100%
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, vector<int>(), 0, nums);
        return res;
    }

   private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int cidx,
             const vector<int>& nums) {
        if (cidx == nums.size()) {
            res.push_back(cur);
            return;
        }
        dfs(res, cur, cidx + 1, nums);
        cur.push_back(nums[cidx]);
        dfs(res, cur, cidx + 1, nums);
        cur.pop_back();
    }
};

int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};

    Solution s;
    vector<vector<int>> ans = s.subsets(nums);
    return 0;
}