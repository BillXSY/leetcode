//
// Created by 71401 on 2021/7/2.
//

class Solution {
    const int MAX_SIZE = 100000;
public:
    int maxIceCream(vector<int> &costs, int coins) {
        vector<int> count(MAX_SIZE + 1);
        for (int cost: costs) {
            count[cost]++;
        }

        int rslt = 0;
        for (int i = 0; i < MAX_SIZE + 1; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                coins -= i;
                if (coins < 0) {
                    return rslt;
                }
                rslt++;
            }
        }

        return rslt;

    }
};