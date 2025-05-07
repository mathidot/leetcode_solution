#include "util.h"

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1 && !visited[i][j]) {
                    dfs(grid2, i, j, visited);
                }
            }
        }

        int ans = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    ans++;
                    dfs(grid2, i, j, visited);
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return;
        }

        if (visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        for (auto &d : dirs) {
            int next_i = i + d[0];
            int next_j = j + d[1];
            dfs(grid, next_i, next_j, visited);
        }
    }
};