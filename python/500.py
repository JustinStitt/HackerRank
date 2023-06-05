ROWS = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]


class Solution:
    LETTER_TO_ROW = {row[i]: ROWS.index(row) for row in ROWS for i in range(len(row))}

    def number_of_rows_required(self, word: str) -> int:
        used = set()
        for c in word:
            c = c.lower()
            used.add(Solution.LETTER_TO_ROW[c])
        return len(used)

    def findWords(self, words: List[str]) -> List[str]:
        ans = []

        for word in words:
            if self.number_of_rows_required(word) == 1:
                ans.append(word)

        return ans
