//
// Created by 71401 on 2021/5/12.
//

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre;
        vector<int> rslt;
        int XOR = 0;

        for (int i = 0; i < arr.size(); ++i) {
            XOR ^= arr[i];
            pre.push_back(XOR);
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (!queries[i][0]) {
                rslt.push_back(pre[queries[i][1]]);
            }
            else {
                rslt.push_back(pre[queries[i][1]] ^ pre[queries[i][0] - 1]);
            }

        }
        return rslt;
    }
};