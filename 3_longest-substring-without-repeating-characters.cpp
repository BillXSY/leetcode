//
// Created by 71401 on 2021/7/20.
//
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // if the length of s is 0 / 1
        // return s.size()
        if (n <= 1) {
            return n;
        }

        unordered_set<char> occ;
        int ans = 0;
        int right = -1;
        for (int i = 0; i < n; ++i) {
            // if left pointer is not 0, remove the left most element
            if (i != 0) {
                occ.erase(s[i - 1]);
            }

            // while the right pointer has not reached the end of s
            //      && there's no repeated elements within the range
            // we increase the size of range
            while (right + 1 < n && !occ.count(s[right + 1])) {
                occ.insert(s[right + 1]);
                right++;
            }

            //update the max range's size
            ans = max(ans, right - i + 1);
        }
        return ans;

    }
};

int main() {
    string input;
    cin >> input;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(input);

}