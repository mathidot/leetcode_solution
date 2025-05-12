#include "util.h"


using Point = std::pair<int, int>;
struct PointHash
{
    size_t operator()(const Point &p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Solution {
private:
    std::array<std::array<int, 2>, 4> dirs{{{0,1}, {1,0}, {-1,0}, {0,-1}}};
    std::vector<Point> getPts(vector<vector<char>> &maze, Point p) const {
        const int height = maze.size();
        const int width = maze[0].size();
        std::vector<Point> ans;
        for (auto &dir: dirs) {
            int next_x = p.first + dir[0];
            int next_y = p.second + dir[1];
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width || maze[next_x][next_y] == '+') {
                continue;
            }
            ans.push_back({next_x, next_y});
        }
        return ans;
    }

    bool isExit(Point p, int height, int width) {
        if (p.first == 0 || p.first == height-1 || p.second == 0 || p.second == width-1) {
            return true;
        }
        return false;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        std::unordered_set<Point, PointHash> visited(100);
        std::queue<Point> q;
        const int height = maze.size(), width = maze[0].size();
        Point start{entrance[0], entrance[1]};
        q.push(start);
        visited.insert(start);

        for (int step = 0; !q.empty(); step++) {
            const size_t level_size = q.size();

            for (size_t i = 0; i < level_size; i++) {
                const Point current = q.front();
                q.pop();

                if (current != start && isExit(current, height, width)) return step;

                for (auto neighbor: getPts(maze, current)) {
                    if (visited.insert(neighbor).second) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return -1;
    }
};