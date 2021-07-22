//
// Created by 71401 on 2021/7/23.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int curr_min = prices[0];
        int curr_profit = 0;
        for (int price : prices) {
            curr_min = min(price, curr_min);
            curr_profit = max(curr_profit, price - curr_min);
        }
        return curr_profit;
    }
};