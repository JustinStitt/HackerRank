# https://leetcode.com/problems/custom-sort-string/submissions/1200112366/?envType=daily-question&envId=2024-03-11
class SpecialSort:
    def __init__(self, c, comes_before, comes_after):
        self.c = c
        self.comes_before = comes_before
        self.comes_after = comes_after

    def __lt__(self, other):
        after = self.comes_after[self.c]
        return other.c in after

    def __gt__(self, other):
        before = self.comes_before[self.c]
        return other.c in before

    def __eq__(self, other):
        return False


class Solution:
    def customSortString(self, order: str, s: str) -> str:
        common = set(order) & set(s)
        uncommon = list()
        for c in s:
            if c not in common:
                uncommon.append(c)
        comes_before = dict()
        comes_after = dict()

        lst = []
        for i, c in enumerate(order):
            if c not in common:
                continue
            before = order[:i]
            if i != len(order) - 1:
                after = order[i + 1 :]
            else:
                after = []

            comes_before[c] = set(before)
            comes_after[c] = set(after)

        for c in s:
            if c not in common:
                continue
            ss = SpecialSort(c, comes_before, comes_after)
            lst.append(ss)

        lst.sort()
        return "".join([x.c for x in lst]) + "".join([x for x in uncommon])
