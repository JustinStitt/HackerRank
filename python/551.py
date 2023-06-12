class Solution:
    def checkRecord(self, s: str) -> bool:
        cond1 = s.count("A") < 2
        cond2 = s.count("LLL") == 0
        return cond1 and cond2
