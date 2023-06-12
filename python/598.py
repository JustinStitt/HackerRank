from itertools import product
from collections import defaultdict


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if len(ops) == 0:
            return m * n

        mm, mn = m, n

        for op in ops:
            a, b = op
            mm, mn = min(mm, a), min(mn, b)
        return mm * mn
