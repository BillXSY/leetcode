class Solution:
    def triangleType(self, nums: list[int]) -> str:
        a, b, c = nums
        if a + b <= c or b + c <= a or c + a <= b:
            return "none"
        if len(set(nums)) == 1:
            return "equilateral"
        if len(set(nums)) == 2:
            return "isosceles"
        return "scalene"