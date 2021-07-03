//
// Created by 71401 on 2021/7/4.
//
#include <vector>

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int size = nums.size();
        vector<int> buckets(size + 1);
        for (int i:nums) {
            buckets[i]++;
        }
        int repeat, miss;
        for (int i = 0; i < size + 1; ++i) {
            if (buckets[i] == 2) {
                repeat = i;
                continue;
            }
            if (buckets[i] == 0) {
                miss = i;
                continue;
            }

        }
        return {repeat,miss};
    }
};
