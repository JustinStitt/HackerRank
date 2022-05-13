# link = https://leetcode.com/problems/integer-to-english-words/
lookup = {
    1: 'One',
    2: 'Two',
    3: 'Three',
    4: 'Four',
    5: 'Five',
    6: 'Six',
    7: 'Seven',
    8: 'Eight',
    9: 'Nine',
    10: 'Ten',
    11: 'Eleven',
    12: 'Twelve',
    13: 'Thirteen',
    14: 'Fourteen',
    15: 'Fifteen',
    16: 'Sixteen',
    17: 'Seventeen',
    18: 'Eighteen',
    19: 'Nineteen',
    20: 'Twenty',
    30: 'Thirty',
    40: 'Forty',
    50: 'Fifty',
    60: 'Sixty',
    70: 'Seventy',
    80: 'Eighty',
    90: 'Ninety',
}

places = {
    0: '', # Hundred
    1: 'Thousand',
    2: 'Million',
    3: 'Billion',
    4: 'Trillion',
}
# 567 345 12
# 167 
# 67
class Solution:
    def getGroupsOfThree(self, num: int) -> list[str]:
        s = str(num)[::-1]
        return [s[i:i+3][::-1] for i in range(0, len(s), 3)]
        
    def numberToWords(self, num: int) -> str:
        if num == 0: return 'Zero'
        res = []
        groups = self.getGroupsOfThree(num)
        tag = ''
        for (place, group) in enumerate(groups):
            cpy = group + '0'
            res.append('')
            full = len(group) == 3
            if full:
                if int(group[0]) != 0:
                    res[place] += lookup[int(group[0])] + ' Hundred '
                group = group[1::] # remove first
            # go through group and append digit by digit
            while len(group):
                # check if entire group in lookup
                if lookup.get(int(group), None) is not None:
                    res[place] += lookup[int(group)] + ' '
                    break
                num = group[0] + '0'*(0 if len(group) == 1 else 1)
                if int(num) != 0:
                    res[place] += lookup[int(num)] + ' '
                group = group[1::]
            if int(cpy) != 0:
                res[place] += places[place]
        ans = ' '.join(res[::-1]).strip()
        return re.sub(r'\W{2,}', ' ', ans) # janky hack to remove excess whitespace

