class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        ans = list(s)

        for i in range(0, len(s), 2 * k):
            ans[i : i + k] = ans[i : i + k][::-1]
        return "".join(ans)
