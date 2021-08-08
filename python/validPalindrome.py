class Solution:
    def isPalindrome(self, s: str) -> bool:
        def isAlphanumeric(c: str) -> bool:
            return (c >= 'a' and c <= 'z') or \
                   (c >= '0' and c <= '9')
        s = filter(isAlphanumeric, s.lower())
        s = ''.join(s)
        return (s == s[::-1])
