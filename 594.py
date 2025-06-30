from collections import Counter
class Solution:
    def findLHS(self, nums ) :
        cnt = Counter(nums)

        return max([val + cnt[key + 1] for key, val in cnt.items() if key + 1 in cnt], default=0)
    

print(Solution().findLHS([1,2,3,4,5,6,6]))
print(Solution().findLHS([1,1,1,1,1]))