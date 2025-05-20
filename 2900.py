class Solution:
    def getLongestSubsequence(self, words: list[str], groups: list[int]) -> list[str]:
        n = len(words)

        curr_g = groups[0]
        rslt = [words[0]]
        for i in range(1, n):
            if groups[i] != curr_g:
                rslt.append(words[i])
                curr_g = groups[i]
        return rslt
    

print(Solution().getLongestSubsequence(["d","g"], [0,1]))