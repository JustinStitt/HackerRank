class Solution:
    def generate(self, n: int, final: set[str], s="", lc=0, rc=0):
        if len(s) == n:
            final.add(s)

        if lc < n // 2:
            # can add open paren
            self.generate(n, final, s + "(", lc + 1, rc)

        if rc < lc:
            # can add right paren
            self.generate(n, final, s + ")", lc, rc + 1)

    def generateParenthesis(self, n: int) -> List[str]:
        final = set()

        self.generate(2 * n, final)

        return list(final)
