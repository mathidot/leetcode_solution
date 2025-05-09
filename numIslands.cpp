#include "util.h"

class Solution {
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            // 超出索引边界
            return;
        }
        if (visited[i][j]) {
            // 已遍历过 (i, j)
            return;
        }

        // 进入节点 (i, j)
        visited[i][j] = true;
        // 递归遍历上下左右的节点
        for (auto &d : dirs) {
            int next_i = i + d[0];
            int next_j = j + d[1];
            dfs(grid, next_i, next_j, visited);
        }
        // 离开节点 (i, j)
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int height = grid.size(), width = grid[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(grid, i, j, visited);
                }
            }
        }

       return ans;
    }
};