#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // dfs
    // time O(N) space O(1)
    // Runtime: 12 ms, faster than 58.71%
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode* parent1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* parent2 = lowestCommonAncestor(root->right, p, q);
        if (parent1 && parent2)
            return root;
        else
            return parent1 ? parent1 : parent2;
    }
};