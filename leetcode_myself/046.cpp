#include <iostream>
#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) { return permute_2(nums); }

   private:
    // dfs
    // time O(N! * N) space O(N)
    // runtime 8ms 99%
    vector<vector<int>> permute_1(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return {};
        vector<int> state(n, 0);
        vector<vector<int>> res;
        // vector<int> cur;
        dfs(res, vector<int>(), state, nums);
        return res;
    }

   private:
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& state,
             const vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0, left = nums.size() - cur.size();
             i < nums.size() && left > 0; i++) {
            if (!state[i]) {
                left--;
                state[i] = 1;
                cur.push_back(nums[i]);
                dfs(res, cur, state, nums);
                cur.pop_back();
                state[i] = 0;
            }
        }
    }

   private:
    // optimize time
    // time O(N!) space O(N)
    // runtime 8ms 99%
    vector<vector<int>> permute_2(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<vector<int>> res;
        dfs_2(res, 0, nums);
        return res;
    }

   private:
    void dfs_2(vector<vector<int>>& res, int cidx, vector<int>& nums) {
        if (cidx == nums.size()) {
            res.push_back(nums);
            return;
        }
        dfs_2(res, cidx + 1, nums);  // swap(nums[cidx], nums[cidx]);
        for (int i = cidx + 1; i < nums.size(); i++) {
            swap(nums[cidx], nums[i]);
            dfs_2(res, cidx + 1, nums);
            swap(nums[cidx], nums[i]);
        }
    }
};

int main() {
    vector<int> nums{1, 2, 3};

    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    return 0;
}