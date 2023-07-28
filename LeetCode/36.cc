/*
    Problem: 36. Valid Sudoku
    Difficulty: Medium
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int row[9];
    int col[9];
    int square[9];
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int v = 0; v < 9; ++v) {
                if (board[i][v] != '.') {
                    int num = board[i][v] - '1';
                    int idx = (i/3) * 3 + v/3;
                    if (((1 << num) & row[i]) == 0) row[i] |= 1 << num;
                    else return false;
                    if (((1 << num) & col[v]) == 0) col[v] |= 1 << num;
                    else return false;
                    if (((1 << num) & square[idx]) == 0) square[idx] |= 1 << num;
                    else return false;
                }
            }
        }

        return true;
    }
};
