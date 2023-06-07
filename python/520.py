class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        case1 = word.upper() == word
        case2 = word.lower() == word
        case3 = word[1:].lower() == word[1:]

        return case1 or case2 or case3
