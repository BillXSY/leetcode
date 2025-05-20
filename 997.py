class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        inDegrees = Counter(y for _, y in trust)
        outDegrees = Counter(x for x, _ in trust)
        return next((i for i in range(1, n + 1) if inDegrees[i] == n - 1 and outDegrees[i] == 0), -1)


print(Solution().findJudge(n = 3, trust = [[1,3],[2,3],[3,1]]))
print(Solution().findJudge(n = 3, trust = [[1,3],[2,3]]))
print(Solution().findJudge(n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]))