class Solution:
    def fib(self, n: int) -> int:
        if n in (0, 1):
            return n

        a, b = 0, 1

        while n > 1:
            a, b = b, a + b
            n -= 1

        return b
