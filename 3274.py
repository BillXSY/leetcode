class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:

        return not ((ord(coordinate1[0]) - ord(coordinate2[0])) % 2 + (int(coordinate1[1]) - int(coordinate2[1])) % 2) % 2

print(Solution().checkTwoChessboards('a1', 'c3'))
print(Solution().checkTwoChessboards('a1', 'h3'))