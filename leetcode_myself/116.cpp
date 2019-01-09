#include <iostream>
#include <queue>

using std::queue;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
   public:
    void connect(TreeLinkNode *root) {}

   private:
    // queue
    // time O(N) space O(height)
    // Runtime: 16 ms, faster than 47.04%
    void connect_1(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            TreeLinkNode *pre = NULL;
            for (int i = 0; i < sz; i++) {
                if (pre == NULL)
                    pre = q.front();
                else {
                    pre->next = q.front();
                    pre = pre->next;
                }
                q.pop();
                if (pre->left) q.push(pre->left);
                if (pre->right) q.push(pre->right);
            }
            pre->next = NULL;
        }
    }

   private:
    // iteration
    // time O(N) space O(height)
    // Runtime: 16 ms, faster than 47.04%
    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *cur = root;
        while (cur->left) {
            TreeLinkNode *p = cur;
            while (p) {
                p->left->next = p->right;
                if (p->next) p->right->next = p->next->left;
                p = p->next;
            }
            cur = cur->left;
        }
    }

    // recursion
	// time O(N) space O(1)
	//Runtime: 20 ms, faster than 36.80%
    void connect_3(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};