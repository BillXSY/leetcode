//
// Created by 71401 on 2021/7/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size - 1;
        int count = 0;

        int leftMax = -999, rightMax = -999;

        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                count += leftMax - height[left];
                left++;
            } else if (height[left] >= height[right]) {
                count += rightMax - height[right];
                right--;
            }
        }
        return count;
    }
};


int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    solution.trap(height);
}