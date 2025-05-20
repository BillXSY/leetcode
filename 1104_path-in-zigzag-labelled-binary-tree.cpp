//
// Created by 71401 on 2021/7/29.
//
#include <vector>

using namespace std;

class Solution {
public:
    int getReverse(int label, int row) {
        if (row % 2 == 0) {
            return (1 << (row - 1)) + (1 << row) - 1 - label;
        }
        return label;
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int rowStart  = 1, row = 1;
        // get the row_num of the given label
        while (rowStart * 2 <= label) {
            rowStart *= 2;
            row++;
        }

        label = getReverse(label, row);
        while (row > 0) {
            ans.push_back(getReverse(label, row));
            row--;
            label >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};