class Solution:
    def minOperations(self, nums) -> int:
        N = len(nums)
        cnt = 0
        for i in range(N-2):
            if nums[i] == 0:
                cnt += 1
                for j in range(3):
                    nums[i+j] = (not nums[i+j])
                print(nums)
        if sum(nums[-3:]) == 3:
            return cnt
        else:
            return -1

# print(Solution().minOperations([0,1,1,1,0,0]))
print(Solution().minOperations([0,1,1,1]))