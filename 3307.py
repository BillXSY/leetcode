class Solution:
    def kthCharacter(self, k: int, operations ):
        import math
        char = 0

        while k > 1:
            op_cnt = math.ceil(math.log2(k)) - 1
            temp = k % (2 ** (op_cnt))

            if temp == 0:
                k //= 2
            else:
                k = temp

            char += operations[op_cnt]
            char %= 26

        return chr(ord('a')+char)
    
for i in range(1, 9):
    print(Solution().kthCharacter(k = i, operations = [1,1,1]), end = ' ')
print('')

for i in range(1, 17):
    print(Solution().kthCharacter(k = i, operations = [0,1,0,1]), end = ' ' )