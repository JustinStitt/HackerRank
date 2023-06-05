from numpy import base_repr


class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        sign = 1 if num >= 0 else -1

        ans = []
        num = abs(num)

        while num > 0:
            ans.append(num % 7)
            num //= 7

        return ("-" if sign == -1 else "") + "".join([str(x) for x in ans][::-1])
