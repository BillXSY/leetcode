class Solution:
    def minimumDifference(self, nums, k: int) -> int:
        '''
            OR操作只会使得值变大（？
            维护lft, rht两个指针, 
            如果右移rht之后窗口内值了, 可以进一步右移
            如果右移rht之后窗口值变大了, 不断右移lft直到
        '''
        rslt = 1e9
        lft, rht = 0, 0
        N = len(nums)

        while rht <= N - 1:

            if rht > 0 and nums[rht] == nums[rht-1]:
                rht += 1
                continue

            tempOR = 0
            for i in range(lft, rht + 1):
                tempOR |= nums[i]

            print(lft, rht, tempOR, abs(tempOR - k))

            if tempOR > k:
                lft += 1
            elif tempOR == k:
                return 0
            else:
                rht += 1

            if lft > rht :
                rht = lft

            rslt = min(rslt, abs(tempOR - k))

        return rslt

print(Solution().minimumDifference(nums = [1,2,4,5], k = 3)) # 0
print(Solution().minimumDifference(nums = [1,3,1,3], k = 2)) # 1
print(Solution().minimumDifference(nums = [1], k = 10)) # 9
print(Solution().minimumDifference(nums = [1, 10], k = 6)) # 4
print(Solution().minimumDifference(nums = [1, 8, 9], k = 7)) # 1
print(Solution().minimumDifference(nums = [7, 4], k = 2)) # 2
print(Solution().minimumDifference(nums = [6], k = 2)) # 4
print(Solution().minimumDifference(nums = [8,89,23,12,13], k = 59)) # 28

print(Solution().minimumDifference(nums = [4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4], k = 59)) # 28







      