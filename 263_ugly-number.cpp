//
// Created by 71401 on 2021/4/10.
//

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        vector<int> factors = {2,3,5};
        for (int factor : factors){
            while (n % factor == 0){
                n/=factor;
            }
        }
        return n == 1;
    }
};