//
// Created by 71401 on 2021/5/27.
//

class Solution {
private:

public:
    int hammingDistance(int x, int y) {

//        method 1: build_in function
//        return __builtin_popcount(x ^ y);

//        method 2:
        int ans = 0;
        int XOR = x^y;
        while (XOR) {
            if (XOR % 2) { ans++; }
            XOR /= 2;
        }
        return ans;
    }
};