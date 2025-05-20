//
// Created by 71401 on 2021/4/26.
//

class Solution {
private:
    int countdays(vector<int> &weights, int capacity) {
        int actu_days = 1;
        int load = 0;
        for (int w : weights) {
            load += w;
            if (load > capacity) {
                actu_days++;
                load = w;
            }
        }
        cout << "actu_days: " << actu_days << endl;
        return actu_days;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
// possible range of D is (1, weights.size()),
// possible range of capacity, x, is (max(weights), sum(weights))
        int tot_weight = 0, max_weight = 0;
        for (int weight : weights) {
            tot_weight += weight;
            max_weight = max_weight > weight ? max_weight : weight;
        }
        int l_it = max_weight, r_it = tot_weight;
        int actu_days, cap;
        while (l_it < r_it) {
            cap = (l_it + r_it) / 2;
            cout << "cap: " << cap << ' ';
            actu_days = countdays(weights,cap);

            if (actu_days > D) {
                l_it = cap+1;
            }
            else{
                r_it = cap;
            }
        }
        return l_it;


    }
};