#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    // time:O(N) space:O(N)	runtime 16ms 33%
    int kthSmallest(TreeNode *root, int k) {
        globalK = k;
        res = 0;
        dfs(root);
        return res;
    }

   private:
    // dfs
    // In-order traversal(Preorder traversal Post-order traversal)
    void dfs(TreeNode *root) {
        if (root == NULL) return;
        dfs(root->left);
        globalK--;
        if (globalK == 0) {
            res = root->val;
            return;
        }
        dfs(root->right);
    }

   private:
    int globalK = 0;
    int res;
};
