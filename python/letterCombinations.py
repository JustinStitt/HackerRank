dtol = { # note: not all are length 3
    2: 'abc',
    3: 'def',
    4: 'ghi',
    5: 'jkl',
    6: 'mno',
    7: 'pqrs', # len 4
    8: 'tuv',
    9: 'wxyz', # len 4
}

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ret: list[str] = []
        self.letterCombinationsHelper(digits, "", ret)
        return ret
            
    def letterCombinationsHelper(self, digits: str, path, ret_ref):
        if len(digits) < 1:
            if not len(path): return
            ret_ref.append(path)
            return
        # still have some digits left over
        # concern ourselves with the left-most digit
        digit = digits[0]
        # create the 3 or 4 (necessary for 7&9) paths for each char
        for c in dtol[int(digit)]:
            new_path = path + c
            self.letterCombinationsHelper(digits[1:], new_path, ret_ref)

