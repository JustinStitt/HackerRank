# https://leetcode.com/problems/reshape-the-matrix/description/
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        cr = len(mat)
        cc = len(mat[0])

        if 0 in (cr, cc, r, c):
            return mat

        if (cr * cc) != (r * c):
            return mat

        new_mat = [[]]

        for i, row in enumerate(mat):
            for j, item in enumerate(row):
                if len(new_mat[-1]) == c:
                    new_mat.append([])
                new_mat[-1].append(item)
        
        return new_mat
