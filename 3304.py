class Solution:
    def kthCharacter(self, k: int):
        import math
        char = 0

        while k > 1:
            op_cnt = int(math.log2(k))
            temp = k % (2 ** op_cnt)
            if temp == 0:
                k //= 2
                
            else:
                k = temp

            # print(k)
            char += 1

        return chr(ord('a')+char)

# abbcbccd
for i in range(1,20):
    print(Solution().kthCharacter(i))