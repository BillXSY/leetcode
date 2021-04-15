//
// Created by 71401 on 2021/4/15.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        int size = nums.size();
        if (size == 1) return nums[0];

        vector<int> dp_1 = vector<int>(size,0);
        dp_1[0] = nums[0];
        dp_1[1] = nums[0];
        for (int i = 2; i < size - 1 ; ++i) {
            dp_1[i] = max(dp_1[i-2]+nums[i], dp_1[i-1]);
        }
//        dp_1[size-1] = dp_1[size-2];

        vector<int> dp_1_not = vector<int>(size,0);
        dp_1_not[0] = 0;
        dp_1_not[1] = nums[1];
        for (int i = 2; i < size; ++i) {
            dp_1_not[i] = max(dp_1_not[i-2]+nums[i], dp_1_not[i-1]);
        }

        return dp_1[size-2] > dp_1_not[size-1] ? dp_1[size-2] : dp_1_not[size-1];
    }
};