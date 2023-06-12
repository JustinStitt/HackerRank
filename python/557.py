class Solution:
    def reverseWords(self, s: str) -> str:
        tokens = s.split(" ")

        out = ""

        for token in tokens:  # ["Let's", 'take', 'LeetCode', 'contest']
            rev = token[::-1]  # ekat
            out += rev + " "

        return out.rstrip()
