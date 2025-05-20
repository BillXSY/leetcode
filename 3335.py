class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        MOD = 1E9 + 7

        counter = [0 for _ in range(26)]

        for c in s:
            counter[ord(c) - 97] += 1

        for _ in range(t):

            z_cnt = counter[-1] % MOD

            for pos in range(25):
                counter[25 - pos] = counter[24 - pos] % MOD

            counter[0] = z_cnt
            counter[1] += z_cnt


        return int(sum(counter) % MOD)


print(Solution().lengthAfterTransformations('abcyy', 2))
print(Solution().lengthAfterTransformations('azbk', 1))