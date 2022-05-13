# link = https://leetcode.com/problems/integer-to-roman
roman_lookup = {
    1: 'I',
    5: 'V',
    10: 'X',
    50: 'L',
    100: 'C',
    500: 'D',
    1000: 'M',
}
class Solution:
    def intToRoman(self, num: int) -> str:
        ans = ''
        while num > 0:
            largest = [x for x in roman_lookup.keys() if x <= num][-1]
            num -= largest
            ans += roman_lookup[largest]
        # replace primitives with shorthand
        # IIII -> IV
        # VIIII -> IX
        # XXXX -> XL
        # LXXXX -> XC
        # CCCC -> CD
        # DCCCC -> CM
        ans = ans.replace('DCCCC', 'CM').replace('CCCC', 'CD').\
            replace('LXXXX', 'XC').replace('XXXX', 'XL').\
            replace('VIIII', 'IX').replace('IIII', 'IV')  
        return ans

