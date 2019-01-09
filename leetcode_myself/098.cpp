#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // recursion
    // time O(N) space O(height) height = log N
    // Runtime: 8 ms, faster than 65.60%
    bool isValidBST(TreeNode *root) { return recursion(root, NULL, NULL); }

   private:
    bool recursion(TreeNode *root, int *rangeLo, int *rangeHi) {
        if (!root) return true;
        if ((rangeLo && root->val <= *rangeLo) ||
            (rangeHi && root->val >= *rangeHi))
            return false;
        return recursion(root->left, rangeLo, &root->val) &&
               recursion(root->right, &root->val, rangeHi);
    }
};

int main() {
    TreeNode root[] = {1, 2, 4};
    root[1].left = &root[0];
    root[1].right = &root[2];

    Solution s;
    bool ans = s.isValidBST(&root[1]);
    return 0;
}