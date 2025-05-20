class Solution:
    def maxSpending(self, values) -> int:
        sorted_vals = sorted([val for shop in values for val in shop ])

        maxSpending = 0

        for i, val in enumerate(sorted_vals):
            maxSpending += (i + 1) * val

        return maxSpending
    
print(Solution().maxSpending([[8,5,2],[6,4,1],[9,7,3]]))