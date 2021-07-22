//
// Created by 71401 on 2021/7/23.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        int prev = 0;
        int maxAns = nums[0];
        for (int i = 0; i < size; ++i) {
            prev = max(prev+nums[i], nums[i]);  // local maximum
            maxAns = max(maxAns, prev);         // global maximum
        }

        return maxAns;

    }
};