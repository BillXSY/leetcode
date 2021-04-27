//
// Created by 71401 on 2021/4/28.
//

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int) sqrt(c);
        while (left <= right) {
            long sq_sum = left*left+right*right;
            if (sq_sum < c) {
                left++;
            }
            if (sq_sum > c) {
                right--;
            }
            if (sq_sum == c) {
                cout << left << ' ' << right << endl;
                return true;
            }
        }
        return false;
    }
};