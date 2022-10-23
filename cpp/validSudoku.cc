#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
  using Grid = vector<vector<char>>&;

  void zero(array<array<bool, 9>, 9>& arr) {
    for (array<bool, 9>& row : arr) {
      for (bool& a : row) {
        a = false;
      }
    }
  }

 public:
  bool isValidSudoku(Grid board) {
    /* no duplicates allowed in row, col or local square */
    array<array<bool, 9>, 9> row_seen;
    array<array<bool, 9>, 9> col_seen;
    array<array<bool, 9>, 9> sq_seen;
    zero(row_seen);
    zero(col_seen);
    zero(sq_seen);

    for (int r{}; r < 9; ++r) {
      for (int c{}; c < 9; ++c) {
        if (board[r][c] == '.') continue;
        unsigned idx = board[r][c] - '0' - 1;
        if (row_seen[r][idx]) return false;
        row_seen[r][idx] = true;
        if (col_seen[c][idx]) {
          return false;
        }

        col_seen[c][idx] = true;
        unsigned sq_idx = (r / 3) + (c / 3) * 3;
        if (sq_seen[sq_idx][idx]) return false;
        sq_seen[sq_idx][idx] = true;
      }
    }
    return true;
  }
};
// @lc code=end
