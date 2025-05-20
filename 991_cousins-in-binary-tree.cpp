//
// Created by 71401 on 2021/5/17.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
//    information of X
    int x;
    TreeNode *x_parent;
    int x_depth;
    bool x_found = false;
//    information of X
    int y;
    TreeNode *y_parent;
    int y_depth;
    bool y_found = false;
public:
    void dfs(TreeNode *root, int depth, TreeNode *parent){
        if (!root) return;
        if (root->val == x) {
//            tie(x_parent, x_depth, x_found) = tuple{parent, depth, true};
            x_parent = parent;
            x_depth = depth;
            x_found = true;
        }
        if (root->val == y) {
//            tie(y_parent, y_depth, y_found) = tuple{parent, depth, true};
            y_parent = parent;
            y_depth = depth;
            y_found = true;
        }
        dfs(root->left, depth + 1, root);
        if (x_found && y_found) return;
        dfs(root->right, depth + 1, root);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 1, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
};