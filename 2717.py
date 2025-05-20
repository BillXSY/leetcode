class Solution:
    def semiOrderedPermutation(self, nums) -> int:
        n = len(nums)
        
        if nums[0] == 1 and nums[-1] == n:
            return 0
        
        idx_1, idx_n = nums.index(1), nums.index(n)

        if idx_1 < idx_n:
            return idx_1 + (n - idx_n - 1)
        else:
            return idx_1 + (n - idx_n - 1) - 1
        
print(Solution().semiOrderedPermutation([2,1,4,3]))
print(Solution().semiOrderedPermutation([2,4,1,3]))
print(Solution().semiOrderedPermutation([1,3,4,2,5]))