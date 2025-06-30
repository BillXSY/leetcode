class Solution:
    def numSubseq(self, nums, target):
        nums = sorted(nums)
        n = len(nums)
        MOD = 1e9+7

        lft_pt, rht_pt = 0, n-1
        rslt = 0

        powers = [1] + [0] * (n-1)
        for i in range(1, n):
            powers[i] = powers[i-1] * 2 % MOD

        while lft_pt <= rht_pt:

            while nums[lft_pt] + nums[rht_pt] > target and rht_pt >= lft_pt:
                rht_pt -= 1

            if lft_pt > rht_pt:
                break

            # rslt = (rslt + 2 ** (rht_pt - lft_pt) % MOD ) % MOD # 这样写会爆int
            rslt += powers[rht_pt - lft_pt]
            rslt %= MOD
            
            lft_pt += 1

        return int(rslt)
    
print(Solution().numSubseq(nums = [3,5,6,7], target = 9))
print(Solution().numSubseq(nums = [3,3,6,8], target = 10))
print(Solution().numSubseq([2,3,3,4,6,7], 12))

print(Solution().numSubseq(nums = [5,2,4,1,7,6,8],target = 16))