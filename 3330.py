class Solution:
    def possibleStringCount(self, word: str) -> int:
        rslt = 1
        n = len(word)
        prev_char = word[0]
        
        for i in range(1, n):
            if word[i] == prev_char:
                rslt += 1
            else:
                prev_char = word[i]
        
        return rslt