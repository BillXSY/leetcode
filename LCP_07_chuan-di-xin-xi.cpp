//
// Created by 71401 on 2021/7/1.
//

class Solution {
public:
    int numWays(int n, vector <vector<int>> &relation, int k) {
        vector <vector<int>> edges(n);
        for (auto edge : relation) {
            int src = edge[0];
            int dst = edge[1];
            edges[src].push_back(dst);
        }

        int count = 0;
        function<void(int, int)> dfs = [&](int index, int steps) {
            if (steps == k) {
                if (index == n - 1) {
                    ++count;
                }
                return;
            }
            for (int to : edges[index]) {
                dfs(to, steps + 1);
            }
        };

        dfs(0, 0);
        return count;
    }
};