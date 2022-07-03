diffs = [(x, y) for x in range(-1, 2, 1) \
                 for y in range(-1, 2, 1) \
                 if (1 if x==0 else 0) + (1 if y==0 else 0) != 2
                ]
class Solution:
    def inBounds(self, board, r, c) -> bool:
        n = len(board); m = len(board[0])
        if r < 0 or r >= n: return False
        if c < 0 or c >= m: return False
        return True
    
    def neighbours(self, board, r, c) -> int:
        '''
        return the number of neighbours at board[r][c]
        '''
        global diffs
        count = 0
        for (rd, cd) in diffs:
            if self.inBounds(board, r+rd, c+cd) and \
                                board[r+rd][c+cd]: count += 1
        return count
    
    def gameOfLife(self, board: List[List[int]]) -> None:
        staged = {} # pending changes (emulate simul.)
        n = len(board); m = len(board[0])
        for (r, c) in [(x, y) for x in range(n) for y in range(m)]:
            neighbours = self.neighbours(board, r, c)
            # cond. 1, 3 (dies)
            if neighbours < 2 or neighbours > 3: staged[(r, c)] = 0
            # cond 4 (reprod.)
            if not board[r][c] and neighbours == 3: staged[(r, c)] = 1
            # cond 2 handled automatically
        for ((r, c), s) in staged.items():
            board[r][c] = s
        return None

