class Solution:
    def smallestRangeII(self, nums, k: int) -> int:
        Minimum = min(nums)
        Maximum = max(nums)

        for num in nums:
            if num + k > Maximum - k:
                


        