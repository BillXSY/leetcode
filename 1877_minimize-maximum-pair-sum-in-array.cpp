//
// Created by Bill on 2021/7/20.
//


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxVal = -9999;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; ++i) {
            maxVal = max(maxVal, nums[i] + nums[n - 1 - i]);
        }
        return maxVal;
    }
};