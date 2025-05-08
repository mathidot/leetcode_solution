#include "util.h"

class Solution {
private:
    int res = 0;
    int empty = 0;
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int i, int j,
        vector<vector<bool>>& visited, int count) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            // 超出索引边界
            return;
        }

        if (visited[i][j]) {
            // 已遍历过 (i, j)
            return;
        }

        if (grid[i][j] == -1) {
            return;
        }

        // 到达终点
        if (grid[i][j] == 2) {
            if (count == empty) { // 必须走过所有空格子
                res++;
            }
            return;
        }
        
        visited[i][j] = true;
        // 递归遍历上下左右的节点
        for (auto &d : dirs) {
            int next_i = i + d[0];
            int next_j = j + d[1];
            dfs(grid, next_i, next_j, visited, count+1);
        }
        // 离开节点 (i, j)
        visited[i][j] = false;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        res = 0;
        int m = grid.size(), n = grid[0].size();
        int start_x = 0, start_y = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                    empty++;
                }
                if (grid[i][j] == 0) {
                    empty++;
                }
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, start_x, start_y, visited, 0);
        return res;
    }
};