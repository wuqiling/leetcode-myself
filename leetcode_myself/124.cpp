#include <algorithm>
#include <iostream>

using std::max;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // recursion
    // time O(N) space O(height of tree)
    // Runtime: 20 ms, faster than 44.10%
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int ans = INT_MIN;
        recursion(root, ans);
        return ans;
    }

   private:
    int recursion(TreeNode *root, int &ans) {
        if (!root) return 0;
        int l = max(0, recursion(root->left, ans));
        int r = max(0, recursion(root->right, ans));
        ans = max(ans, l + r + root->val);
        return max(l, r) + root->val;
    }
};