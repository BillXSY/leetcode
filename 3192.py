class Solution:
    def minOperations(self, nums) -> int:
        curr_targ = 0
        cnt = 0
        for num in nums:
            if num == curr_targ:
                cnt += 1
                curr_targ = (not curr_targ)
        
        return cnt
    

print(Solution().minOperations([0,1,1,0,1]))
print(Solution().minOperations([1,0,0,0]))
