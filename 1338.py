class Solution:
    def minSetSize(self, arr ) -> int:
        import collections
        freq = collections.Counter(arr)

        n = len(arr)

        cnt, ans = 0, 0

        for num, f in freq.most_common():
            cnt += f
            ans += 1
            if cnt * 2 >= n:
                break

        return ans
        

