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
    // reursion dfs
    // Runtime: 4 ms, faster than 98.92%
    int maxDepth(TreeNode *root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};