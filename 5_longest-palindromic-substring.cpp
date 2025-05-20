//
// Created by 71401 on 2021/7/20.
//

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;


        vector <vector<int>> dp(size, vector<int>(size));
        // dp[i][j]
        for (int i = 0; i < size; ++i) {
            dp[i][i] = 1;
        }

        for (int L = 2; L <= size; ++L) {
            for (int i = 0; i < size; ++i) {
                int j = L + i - 1;
                if (j >= size) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j - i <= 2) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};