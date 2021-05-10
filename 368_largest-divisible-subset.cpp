//
// Created by 71401 on 2021/4/23.
//
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(),1);
        int dp_max = -INT_MAX - 1;
        int dp_max_index = -INT_MAX - 1;
        vector<vector<int>> answer(nums.size());
        answer[0].push_back(nums[0]);
        /*for (int i = 0; i < nums.size(); ++i) {
            answer[i].push_back(nums[i]);
            int local_max = 0;
            for (int j = i-1; j >= 0 ; --j) {
                if (nums[i] % nums[j] == 0) {
                    local_max = nums[j] > local_max ? nums[j] : local_max;
                    dp[i]++;
                    answer[i].push_back(nums[j]);
                }
            }
            dp[i] = 1 + local_max;

        }

        vector<int> res;
        for (int i = answer[dp_max_index].size() - 1; i >= 0; --i) {
            res.push_back(answer[dp_max_index][i]);
        }
        return dp; */
        for (int i = 1; i < nums.size(); ++i) {
            int local_max_index = -1;
            for (int j = i - 1; j >= 0 ; --j) {
                if (nums[i] % nums[j] == 0) {
                    local_max_index = max(local_max_index, j);
//                    local_max = max(local_max, dp[j]);
                }
            }
            answer[i] = vector(answer[local_max_index]);
            answer[i].push_back(nums[i]);
//            dp[i] = local_max + 1;

        }
        for (int i = 0; i < answer.size(); ++i) {
            for (int j = 0; j < answer[i].size(); ++j) {
                cout << answer[i][j] << ' ';
            }
            cout << ',';
        }
        return dp;
    }
};
