//
// Created by 71401 on 2021/7/29.
//
#include <vector>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int size = nums.size();
        int i, j;
        // from right to left, find the first non-increasing num
        for (i = size - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        // if the first non-increasing num is not nums[0]
        // from right most to nums[i] find the first number larger than nums[i]
        // since nums[i]+1 to nums[size-1] are guaranteed to be descending
        // the first number larger than nums[i] is guaranteed to be the minimum largest num
        if (i>=0) {
            for (j = size - 1; j >= i; --j) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            // swap nums[i] with nums[j]
            swap(nums[i], nums[j]);
        }
        // reverse the interval nums[i]+1 to nums[size-1]
        reverse(nums.begin() + i + 1, nums.end());

    }
};