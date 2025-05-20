class Solution:
    def minMovesToCaptureTheQueen(
        self, a: int, b: int, c: int, d: int, e: int, f: int
    ) -> int:
        if a == e and not (c == a and (b - d) * (f - d) < 0):
            return 1

        if b == f and not (d == b and (a - c) * (e - c) < 0):
            return 1

        if abs(c - e) == abs(d - f) and not ((d - b) * (e - a) == (f - b) * (c - a) and (c - a) * (e - a) < 0):
            return 1

        return 2
