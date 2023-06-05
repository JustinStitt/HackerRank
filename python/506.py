class Solution:
    def findRelativeRanks(self, score: list[int]) -> list[str]:
        RANKS = ("Gold Medal", "Silver Medal", "Bronze Medal")
        lookup = dict()
        for idx, item in enumerate(score):
            lookup[item] = idx

        out = [None] * len(score)
        # now sort
        ordered = sorted(score, reverse=True)

        for idx, rank in enumerate(ordered):
            adj_idx = lookup[rank]
            if idx in (0, 1, 2):
                out[adj_idx] = RANKS[idx]
                continue
            out[adj_idx] = str(idx + 1)

        return out


"""
10 3 8 9 4

10 9 8 4 3

gold, silver, bronze, 4, 5
"""


def main():
    scores = [10, 3, 8, 9, 4]
    out = Solution().findRelativeRanks(scores)
    print(out)


if __name__ == "__main__":
    main()
