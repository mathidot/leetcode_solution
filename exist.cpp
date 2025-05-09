#include "util.h"

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<char>>& grid, int i, int j,
    	vector<vector<bool>>& visited, string word, int index) {
        if (index == word.size()) return true;
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            // 超出索引边界
            return false;
        }
        if (visited[i][j]) {
            // 已遍历过 (i, j)
            return false;
        }
        

        if (word[index] != grid[i][j]) {
            return false;
        }

        // 进入节点 (i, j)
        visited[i][j] = true;
        // 递归遍历上下左右的节点
        for (auto &d : dirs) {
            int next_i = i + d[0];
            int next_j = j + d[1];
            if (dfs(grid, next_i, next_j, visited, word, index+1)) {
                return true;
            } 
        }
        visited[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (board[i][j] == word.front()) {
                    if (dfs(board, i, j, visited, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};