class Solution:
    def validPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1
        while l < r:
            if s[l] != s[r]:
                one = s[l+1:r+1]
                two = s[l:r]
                return one == one[::-1] or \
                       two == two[::-1]
            l += 1
            r -= 1
        return True
