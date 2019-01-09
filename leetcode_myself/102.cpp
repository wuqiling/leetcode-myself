#include <queue>
#include <vector>

using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        return levelOrder_2(root);
    }

   private:
    // iteration
    // time O(N) space O(max one layer size)
    // Runtime: 4 ms, faster than 98.95%
    vector<vector<int>> levelOrder_1(TreeNode *root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> t(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode *cur = q.front();
                q.pop();
                t[i] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(t);
        }
        return res;
    }

   private:
    // recursion
    // time O(N) space O(max one layer size)
    // Runtime: 4 ms, faster than 98.95%
    vector<vector<int>> levelOrder_2(TreeNode *root) {
        if (!root) return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        vector<int> cur;
        q.push(root);
        recursion(res, cur, q, 1);
        return res;
    }

    void recursion(vector<vector<int>> &res, vector<int> &cur,
                   queue<TreeNode *> &q, int sz) {
        if (sz == 0) {
            if (cur.size() == 0) return;
            res.push_back(cur);
            cur.clear();
            recursion(res, cur, q, q.size());
            return;
        }
        TreeNode *node = q.front();
        q.pop();
        cur.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        recursion(res, cur, q, sz - 1);
    }
};

int main() {
    TreeNode root[] = {3, 9, 20, 15, 7};
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[2].left = &root[3];
    root[2].right = &root[4];

    Solution s;
    vector<vector<int>> ans = s.levelOrder(&root[0]);
    return 0;
}