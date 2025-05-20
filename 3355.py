class Solution:
    def isZeroArray(self, nums: list[int], queries: list[list[int]]) -> bool:
        if max(nums) > len(queries):
            return False
        
        n = len(nums)
        
        deltaArray = [0 for _ in range(n + 1)]

        for l, r in queries:
            deltaArray[l] += 1
            deltaArray[r + 1] -= 1

        preflix_sum = 0
        for i in range(n):
            preflix_sum += deltaArray[i]

            if nums[i] > preflix_sum:
                return False


        return True