#include "util.h"

class Solution {
private:
    const int width = 9;
    const int height = 9;
    const int matrix_num = 9;
    std::vector<std::pair<int, int>> dirs = 
        {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    std::vector<std::pair<int, int>>
    getPoints(int x, int y, int height, int weight) {
        std::vector<std::pair<int, int>> points;
        for (auto dir: dirs) {
            int new_x = x + dir.first;
            int new_y = y + dir.second;
            if (new_x>=0 && new_x<height && new_y>=0 && new_y<weight) {
                points.emplace_back(new_x, new_y);
            }
        } 
        return points;
    }


    // 打印当前数独状态
    void printBoard(const vector<vector<char>>& board) {
        cout << "Current Board:" << endl;
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0) {
                cout << "------+-------+------" << endl;
            }
            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0) {
                    cout << "| ";
                }
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    bool backtrack(vector<vector<char>>& board, 
                 vector<vector<int>>& rows,
                 vector<vector<int>>& cols,
                 vector<vector<int>>& boxes) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int box_index = (i / 3) * 3 + j / 3;
                    for (int num = 1; num <= 9; num++) {
                        if (!rows[i][num] && !cols[j][num] && !boxes[box_index][num]) {
                            // 尝试填入数字
                            board[i][j] = num + '0';
                            rows[i][num] = cols[j][num] = boxes[box_index][num] = 1;
                            
                            if (backtrack(board, rows, cols, boxes)) {
                                return true;
                            }
                            
                            // 回溯
                            board[i][j] = '.';
                            rows[i][num] = cols[j][num] = boxes[box_index][num] = 0;
                        }
                    }
                    return false; // 当前格子无解
                }
            }
        }
        return true; // 所有格子已填满
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(height, vector<int>(10, 0));
        vector<vector<int>> cols(width, vector<int>(10, 0));
        vector<vector<int>> boxes(matrix_num, vector<int>(10, 0));
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int box_index = (i / 3) * 3 + j / 3;
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    boxes[box_index][num] = 1;
                }
            }
        }

        backtrack(board, rows, cols, boxes);
        printBoard(board);
        return;
    }
};