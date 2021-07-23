//
// Created by 71401 on 2021/7/23.
//

class Solution {
private:
    void dfs(vector <vector<char>> &grid, int i, int j){
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int height = grid.size(), length = grid[0].size();

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < length; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};