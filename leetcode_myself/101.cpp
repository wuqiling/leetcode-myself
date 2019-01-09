#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    bool isSymmetric(TreeNode *root) {
		return isSymmetric_1(root);
	}

   private:
    // dfs
    // time O(N) space O(1)
    // Runtime: 8 ms, faster than 25.49%
    bool isSymmetric_1(TreeNode *root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(const TreeNode *l, const TreeNode *r) {
        if (!l || !r) return !l && !r;
        if (l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }

    // bfs
    // Runtime: 8 ms, faster than 25.49%
    bool isSymmetric_2(TreeNode *root) {
        if (!root) return true;
        stack<std::pair<TreeNode *, TreeNode *>> st;  // first left second right
        st.push({root->left, root->right});
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            if (p.first == NULL && p.second == NULL) continue;
            if (p.first == NULL || p.second == NULL) return false;
            if (p.first->val != p.second->val) return false;
            st.push({p.first->left, p.second->right});
            st.push({p.first->right, p.second->left});
        }
        return true;
    }
};