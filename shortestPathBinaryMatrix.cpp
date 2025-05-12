#include "util.h"

using Point = std::pair<int, int>;
struct PointHash {
    size_t operator()(const Point &p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
private:
    std::array<std::array<int, 2>, 8> dirs{{{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1, -1}, {-1, 1}, {-1, -1}}};
    std::vector<Point> getPts(vector<vector<int>> &grid, Point p) const {
        const int height = grid.size();
        const int width = grid[0].size();
        std::vector<Point> ans;
        for (auto &dir: dirs) {
            int next_x = p.first + dir[0];
            int next_y = p.second + dir[1];
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width || grid[next_x][next_y] == 1) {
                continue;
            }
            ans.push_back({next_x, next_y});
        }
        return ans;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        Point start{0, 0};
        Point end{m-1, n-1};
        std::unordered_set<Point, PointHash> visited1, visited2;
        visited1.reserve(100);
        visited2.reserve(100);
        visited1.insert(start);
        visited2.insert(end);

        std::queue<Point> q1;
        q1.push(start);
        std::queue<Point> q2;
        q2.push(end);

        int step = 0;

        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(visited1, visited2);
            }
            const size_t level_size = q1.size();
            for (size_t i = 0; i < level_size; i++) {
                auto current = q1.front();
                q1.pop();
                
                if (current == end) return step;

                for (auto neighbor: getPts(grid, current)) {
                    if (visited1.insert(neighbor).second) {
                        q1.push(neighbor);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};