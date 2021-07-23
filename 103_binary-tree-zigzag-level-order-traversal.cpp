//
// Created by 71401 on 2021/7/23.
//
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<TreeNode *> thisLayer;
        vector<TreeNode *> nextLayer = {root};
        vector<vector<int>> visits;
        bool reverseSubNodes = false;

        while (!nextLayer.empty()) {
            thisLayer = nextLayer;
            nextLayer.clear();
            vector<int> visit;
            while (!thisLayer.empty()) {
                auto currNode = thisLayer.back();
                visit.push_back(currNode->val);
                thisLayer.pop_back();
                if (!reverseSubNodes) {
                    if (currNode->left) {
                        nextLayer.push_back(currNode->left);
                    }
                    if (currNode->right) {
                        nextLayer.push_back(currNode->right);
                    }
                } else {
                    if (currNode->right) {
                        nextLayer.push_back(currNode->right);
                    }
                    if (currNode->left) {
                        nextLayer.push_back(currNode->left);
                    }
                }


            }
            visits.push_back(visit);
            reverseSubNodes = !reverseSubNodes;
        }
        return visits;

    }
};