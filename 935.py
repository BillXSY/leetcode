class Solution:
    def knightDialer(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        move = [
            [4, 6],
            [6, 8],
            [7, 9],
            [4, 8],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4],
        ]

        dp = [[0 for _ in range(10)], [1 for _ in range(10)]]

        for i in range(2, n+1):
            x = i & 1
            for j in range(10):
                dp[x][j] = 0
                for k in move[j]:
                    dp[x][j] = (dp[x][j] + dp[x^1][k]) % MOD

        return sum(dp[n % 2]) % MOD

        
