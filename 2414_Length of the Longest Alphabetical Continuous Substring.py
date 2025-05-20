class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        N = len(s)

        rslt = 1
        temp = 1    
        for i in range(1, N):
            if ord(s[i]) - ord(s[i-1]) ==  1:
                temp += 1
            else:
                temp = 1
            rslt = max(rslt, temp)
        return rslt
    
print(Solution().longestContinuousSubstring('abcdefg'))