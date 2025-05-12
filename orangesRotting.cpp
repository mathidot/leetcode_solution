#include "util.h"

using Point = std::pair<int, int>;
class Solution {
private:
    std::array<std::array<int, 2>, 4> dirs{{{0,1}, {1,0}, {-1,0}, {0,-1}}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        bool* visited = new bool[m * n]{false};
        int ans = 0;
        bool has_fresh = false;

        // 先统计是否有新鲜橘子，并初始化队列
        queue<Point> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) has_fresh = true;
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    visited[i * n + j] = true;
                }
            }
        }

        if (!has_fresh) return 0;  // 没有新鲜橘子，直接返回 0

        // 多源 BFS
        int step = -1;  // 初始化为 -1，因为第一层是已经腐烂的
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || 
                        visited[nx * n + ny] || grid[nx][ny] != 1) {
                        continue;
                    }
                    visited[nx * n + ny] = true;
                    grid[nx][ny] = 2;  // 标记为腐烂
                    q.emplace(nx, ny);
                }
            }
            step++;
        }

        // 检查是否还有未腐烂的橘子
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    delete[] visited;
                    return -1;
                }
            }
        }

        delete[] visited;
        return step;
    }
};