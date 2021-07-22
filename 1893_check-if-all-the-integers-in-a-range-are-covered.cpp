//
// Created by 71401 on 2021/7/23.
//

class Solution {
public:
    bool isCovered(vector <vector<int>> &ranges, int left, int right) {
        unordered_set<int> cover;
        for (vector<int> range : ranges) {
            for (int i = range[0]; i <= range[1]; ++i) {
                cover.insert(i);
            }
        }
        for (int i = left; i <= right; ++i) {
            if (!cover.count(i)) {
                return false;
            }
        }
        return true;
    }
};