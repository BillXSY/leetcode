//
// Created by 71401 on 2021/5/11.
//
/*
 XOR 满足交换律 结合律
 (A xor B) xor B = A xor (B xor B) = A xor 0 = A

 有题意可知perm是前奇数个正整数的排列
 通过encoded.size()可得perm是哪些正整数构成的
 还原出首项之后 依次xor得出全部
 */
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int perm_size = encoded.size() + 1;
        int XOR_all = 0;
        for (int i = 1; i <= perm_size; ++i) {
            XOR_all ^= i;
        }
        for (int i = 1; i < perm_size - 1; i += 2) {
            XOR_all ^= encoded[i];
        }
        int curr = XOR_all;
        vector<int> rslt;
        for (int i = 0; i < perm_size - 1; ++i) {
            rslt.push_back(curr);
            curr ^= encoded[i];
        }
        rslt.push_back(curr);
        return rslt;
    }
};