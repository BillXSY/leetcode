class Solution:
    def maxScoreSightseeingPair(self, values ) -> int:
        N = len(values)
        rslt = -1
        for i in range(0, N - 1):
            for j in range(i+1, N):
                rslt = max(rslt, values[i] + values[j] + i - j)
        return rslt


print(Solution().maxScoreSightseeingPair([8,1,5,2,6])) # 11
print(Solution().maxScoreSightseeingPair([1,2])) # 2


    