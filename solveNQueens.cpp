#include "util.h"

class Solution {
private:
    vector<vector<string>> res;

    bool isValid(vector<string> &board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string> &board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col)) {
                continue;
            }

            board[row][col] = 'Q';
            backtrack(board, row+1);
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};