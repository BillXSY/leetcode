//
// Created by 71401 on 2021/7/22.
//
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
    void swap(int left, int right, vector<int> &nums) {
        auto temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }

    int Rselect(int start, int end, int K, vector<int> &nums) {
        int length = end - start;
        if (length <= 0) {
            return -9999;
        } else if (length == 1) {
            return nums[start];
        }

        int pivot = (rand() % length) + start;
        swap(start, pivot, nums);

        int left = start + 1, right = end - 1;
        while (left < right) {
            while (nums[left] < nums[start] && left < right) {
                left++;
            }
            while (nums[right] >= nums[start] && left <= right) {
                right--;
            }
            if (left < right) {
                swap(left, right, nums);
            } else {
                swap(start, right, nums);
            }
        }
        if (left == right && nums[start] >= nums[right]) {
            swap(start, right, nums);
            return nums[start + K];
        }

        if (start + K == right) {
            return nums[right];
        } else if (right > start + K) {//go to left
            return Rselect(start, right + 1, K, nums);
        } else if (right < start + K) {
            return Rselect(right + 1, end, K - (right - start) - 1, nums);
        }
        return -666;

    }

    int findKthLargest(vector<int> &nums, int k) {
        srand((unsigned) time(NULL));
        return Rselect(0, nums.size(), nums.size() - k, nums);
    }
};