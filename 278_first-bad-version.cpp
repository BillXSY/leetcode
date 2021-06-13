//
// Created by 71401 on 2021/6/13.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while(i < j){
            int ck_pt = i + (j - i) / 2;
            if (isBadVersion(ck_pt)) {
                j = ck_pt;
            } else {
                i = ck_pt + 1;
            }
        }
        return i;
    }
};