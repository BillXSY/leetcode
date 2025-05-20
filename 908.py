class Solution:
    def smallestRangeI(self, nums, k: int) -> int:
        N = len(nums)
        if N == 1:
            return 0
        nums.sort()

        if nums[-1] - nums[0] <= 2 * k:
            return 0
        
        return nums[-1] - nums[0] - 2 * k


print(Solution().smallestRangeI([1], 0))
print(Solution().smallestRangeI([0,10], 2))
print(Solution().smallestRangeI([1,3,6], 3))