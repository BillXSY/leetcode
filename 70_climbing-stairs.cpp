class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> mem(n + 1);
        mem[1] = 1;
        mem[2] = 2;
        for (int i = 3; i <= n; ++i) {
            mem[i] = mem[i - 2] + mem[i - 1];
        }
        return mem[n];
    }
};