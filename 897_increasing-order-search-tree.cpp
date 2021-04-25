//
// Created by 71401 on 2021/4/25.
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
    void in_order(TreeNode *root, vector<int> &v){
        if (!root) return;
        in_order(root->left, v);
        v.push_back(root->val);
        in_order(root->right, v);
    }

    TreeNode* vec_to_tree(vector<int> &vec) {
        TreeNode* dummy_node = new TreeNode(-1);
        TreeNode* curr_node = dummy_node;
        for (int value : vec) {
            n->right = new TreeNode(value);
            n = n->right;
        }
        return dummy_node->right;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        in_order(root, v);
        return vec_to_tree(v);


    }
};