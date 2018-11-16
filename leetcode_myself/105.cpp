#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
重建二叉树
根据前序和中序，重建二叉树
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
                                  int inorderSize) {
    if (preorderSize != 0) {
        /*建立根节点*/
        struct TreeNode *root =
            (struct TreeNode *)malloc(sizeof(struct TreeNode));
        if (!root) return NULL;

        root->val = *preorder;

        if (preorderSize == 1) {
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        /*计算左子数节点个数*/
        int i = 0;
        for (i = 0; i < preorderSize - 1; i++) {
            if (inorder[i] == preorder[0]) break;
        }

        root->left = buildTree(preorder + 1, i, inorder, i);
        root->right = buildTree(preorder + 1 + i, preorderSize - i - 1,
                                inorder + 1 + i, inorderSize - i - 1);
        return root;
    } else {
        return NULL;
    }
}