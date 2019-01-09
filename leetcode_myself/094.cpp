#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // Runtime: 0 ms, faster than 100.00%
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderRecursion(res, root);
        return res;
    }

   private:
    void inorderRecursion(vector<int> &res, TreeNode *root) {
        if (!root) return;
        if (root->left) inorderRecursion(res, root->left);
        res.push_back(root->val);
        if (root->right) inorderRecursion(res, root->right);
    }
};

int main() {
    TreeNode root[] = {1, 2, 3};
    root[0].right = &root[1];
    root[1].left = &root[2];

    Solution s;
    vector<int> ans = s.inorderTraversal(root);
    return 0;
}