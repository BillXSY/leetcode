//
// Created by 71401 on 2021/5/18.
//
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pre;
        pre.push_back(0);
        int XOR = 0;
        for (int num : arr){
            XOR ^= num;
            pre.push_back(XOR);
        }
        //    for (int i : pre) {
        //        cout << i << ' ';
        //    }
        int ans = 0;
        int size = pre.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (pre[i] == pre[j]){
                    ans += (j - i - 1);
                }
            }
        }
        return ans;
    }
};