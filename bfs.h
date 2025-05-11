#include "util.h"

using Point = std::pair<int, int>;
using Graph = std::unordered_map<Point, std::vector<Point>, PointHash>;

// 1. 定义哈希函数
struct PointHash {
    size_t operator()(const Point& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

// 2. 定义比较函数（全局operator==）
bool operator==(const Point& a, const Point& b) {
    return a.first == b.first && a.second == b.second;
}


int bfs(const Graph &graph, const Point &start, const Point &target) {
    std::queue<Point> q;
/*
    auto point_hash = [](const Point& p) {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    };

    auto point_equal = [](const Point& a, const Point& b) {
        return a.first == b.first && a.second == b.second;
    };
*/
    std::unordered_set<Point, PointHash> visited(8);  // 8是初始桶数
    std::queue<Point> q;

    q.push(start);
    visited.insert(start);

    for (size_t step = 0; !q.empty(); ++step) {
        const size_t level_size = q.size();

        for (size_t i = 0; i < level_size; i++) {
            const Point current = q.front();
            q.pop();

            if (current == target) {
                return step;
            }

            if (graph.count(current)) {
                for (const Point &neighbor : graph.at(current)) {
                    if (visited.insert(neighbor).second) {
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    return -1;
}