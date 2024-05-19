# https://leetcode.com/problems/number-of-lines-to-write-string/
class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        PIXELS_PER_LINE = 100
        run = 0
        lines = 0

        for c in s:
            width = widths[ord(c) - ord("a")]
            if run + width > PIXELS_PER_LINE:
                run = 0
                lines += 1

            run += width

        return [lines + 1, run]
