//
// Created by 71401 on 2021/7/23.
//

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *rslt;

    bool postOrderDFS(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return false;
        }
        bool left = postOrderDFS(root->left, p, q);
        bool right = postOrderDFS(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))) {
            rslt = root;
        }
        return left || right || root->val == p->val || root->val == q->val;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        postOrderDFS(root, p, q);
        return rslt;
    }
};