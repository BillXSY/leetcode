//
// Created by 71401 on 2021/4/13.
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
public:
    void DFS(TreeNode* root, vector<int>& rslt){
        if(!root) return;
        DFS(root->left, rslt);
        rslt.push_back(root->val);
        DFS(root->right, rslt);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> rslt;
        DFS(root,rslt);
        int min_diff =  rslt[1] - rslt[0];
        for(int i = 2; i < rslt.size();i++){
            min_diff = min_diff < rslt[i] - rslt[i - 1] ? min_diff : rslt[i] - rslt[i - 1];
        }
        return min_diff;
    }


};

