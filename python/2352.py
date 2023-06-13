from collections import defaultdict


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        rows = defaultdict(lambda: int())

        total = 0

        for row in grid:
            rows[tuple(row)] += 1

        for i in range(n):
            col = tuple([grid[j][i] for j in range(n)])
            # how many rows match this col?
            total += rows[col]

        return total
