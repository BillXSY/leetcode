class Solution:
    def differenceOfSum(self, nums) -> int:
        elementSum = 0
        digitSum = 0
        for num in nums:
            elementSum += num
            while num // 10:
                digitSum += num % 10
                num = num // 10
            digitSum += num

        return elementSum - digitSum


print(Solution().differenceOfSum([1,15,6,3]))
print(Solution().differenceOfSum([1,2,3,4]))