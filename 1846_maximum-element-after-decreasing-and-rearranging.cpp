//
// Created by 71401 on 2021/7/15.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] + 1 >= arr[i+1]) {
                continue;
            } else {
                arr[i + 1] = arr[i] + 1;
            }
        }

        if (arr.size() >= arr[arr.size() - 1]) {
            return arr[arr.size() - 1];
        }
        return arr.size();
    }
};