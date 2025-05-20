//
// Created by 71401 on 2021/5/13.
//

class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, 251);
        vector<int> dp(arrLen + 2);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 1; i < steps; ++i) {
            vector<int> temp(arrLen + 2);
            for (int j = 1; j < arrLen + 1; ++j) {
                temp[j] = ((dp[j - 1] + dp[j]) % int(1e9 + 7) + dp[j + 1]) % int(1e9 + 7);
            }
            dp = temp;
        }
        return dp[1];
    }
};