//
// Created by 71401 on 2021/4/27.
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
    void in_order(TreeNode *node, vector<int> &v){
        if (!node) return;
        in_order(node->left, v);
        v.push_back(node->val);
        in_order(node->right, v);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> vec;
        in_order(root, vec);
        int sum = 0;
        for (int value : vec) {
            if (value >= low && value <= high) sum += value;
        }
        return sum;
    }
};