#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {}

   private:
    // 2 stack + recursion
    // time O(N) space O(N)
    // Runtime: 4 ms, faster than 49.25%
    vector<vector<int>> zigzagLevelOrder_1(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode *> l2r;
        stack<TreeNode *> r2l;
        l2r.push(root);
        vector<int> curVec;
        vector<vector<int>> res;
        zigOrder(l2r, r2l, 1, res, curVec);
        return res;
    }

   private:
    void zigOrder(stack<TreeNode *> &l2r, stack<TreeNode *> &r2l, int cur,
                  vector<vector<int>> &res, vector<int> &curVec) {
        if (l2r.empty() && r2l.empty()) return;
        if (cur == 1) {
            //->->->
            if (l2r.empty()) return;
            curVec.push_back(l2r.top()->val);
            if (l2r.top()->left) r2l.push(l2r.top()->left);
            if (l2r.top()->right) r2l.push(l2r.top()->right);
            l2r.pop();
            if (l2r.empty()) {
                res.push_back(curVec);
                curVec.clear();
            }
            zigOrder(l2r, r2l, l2r.empty() ? -1 : 1, res, curVec);
        } else {
            //<-<-<
            if (r2l.empty()) return;
            curVec.push_back(r2l.top()->val);
            if (r2l.top()->right) l2r.push(r2l.top()->right);
            if (r2l.top()->left) l2r.push(r2l.top()->left);
            r2l.pop();
            if (r2l.empty()) {
                res.push_back(curVec);
                curVec.clear();
            }
            zigOrder(l2r, r2l, r2l.empty() ? 1 : -1, res, curVec);
        }
    }

   private:
    // queue + layerOrder
	// time O(N) space O(N)
    // Runtime: 4 ms, faster than 49.25%
    vector<vector<int>> zigzagLevelOrder_2(TreeNode *root) {
        if (!root) return {};//c++11
        queue<TreeNode *> q;
        vector<vector<int>> res;

        // odd level 0-1-2
        // even n-..2-1
        int level = 0;
		q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> cur(sz);
            for (int i = 0; i < sz; i++) {
                if (level == 0)
                    cur[i] = q.front()->val;
                else
                    cur[sz - i - 1] = q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(cur);
            level = level ? 0 : 1;
        }
        return res;
    }
};

int main() {
    TreeNode root[] = {1, 2, 3, 4, 5};
    root[0].left = &root[1];
    root[0].right = &root[2];
    root[1].left = &root[3];
    root[2].right = &root[4];

    Solution s;
    s.zigzagLevelOrder(root);
    return 0;
}