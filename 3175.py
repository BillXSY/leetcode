class Solution:
    def findWinningPlayer(self, skills, k) -> int:
        N = len(skills)
        win_cnt = 0
        i = 0
        last_i = 0
        while i < N:
            j = i + 1
            while j < N and skills[j] < skills[i] and win_cnt < k:
                j += 1
                win_cnt += 1
            if win_cnt == k:
                return i
            last_i = i
            i = j
            win_cnt = 1
        return last_i

        

# print(Solution().findWinningPlayer([4,2,6,3,9], 2)) # 2
# print(Solution().findWinningPlayer([2,5,4], 4)) # 1
print(Solution().findWinningPlayer([4,18,17,20,15,12,8,5], 1 )) # 1
