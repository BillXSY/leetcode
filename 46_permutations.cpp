//
// Created by 71401 on 2021/7/22.
//
#include <vector>

using namespace std;

class Solution {
public:
    void backTrack(int first, int length, vector<vector<int>>& ans, vector<int>& nums ) {
        if (first == length) {
            ans.push_back(nums);
        }
        for (int i = first; i < length; ++i) {
            swap(nums[i], nums[first]);
            backTrack(first+1, length, ans, nums);
            swap(nums[i], nums[first]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backTrack(0, nums.size(), ans, nums);
        return ans;
    }
};
