#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // recursion
    // time O(N) space O(1)
    // Runtime: 12 ms, faster than 56.10%
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, (int)nums.size() - 1);
    }

   private:
    TreeNode* dfs(const vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(nums[l]);
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = dfs(nums, l, m - 1);
        node->right = dfs(nums, m + 1, r);
        return node;
    }
};

int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9,10};
    Solution s;
    TreeNode* ans = s.sortedArrayToBST(nums);
    return 0;
}