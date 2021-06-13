//
// Created by 71401 on 2021/6/14.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int fdbk = guess(mid);
            switch (fdbk) {
                case -1:
                    right = mid;
                    break;
                case 1:
                    left = mid + 1;
                    break;
                case 0:
                    return mid;
                    break;
            }
        }
        return left;
    }
};