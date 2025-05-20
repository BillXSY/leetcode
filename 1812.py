class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        c, r = ord(coordinates[0]) - ord('a'), int(coordinates[1]) - 1

        return bool((c + r) % 2)



print(Solution().squareIsWhite('a1'))
print(Solution().squareIsWhite('c7'))