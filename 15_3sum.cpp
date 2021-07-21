//
// Created by 71401 on 2021/5/18.
//

#include <unordered_set>
#include <algorithm>

class Solution {
public:
    vector <vector<int>> threeSum(vector<int> &nums) {
        int size = nums.size();
        if (size < 3) {
            return {};
        }
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());


        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int right = size - 1;
            for (int left = i+1; left < size; ++left) {
                if (left > i+1 && nums[left] == nums[left - 1]) {
                    continue;
                }

                while (left < right && nums[left] + nums[right] > target) {
                    right--;
                }
                if (left == right) {
                    break;
                }
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }

        return ans;

    }
};