#include "util.h"

using Point = std::pair<int, int>;
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // 边界条件检查
        if (target < 0 || target > x + y) {
            return false;
        }
        if (target == 0 || target == x + y) {
            return true;
        }

        // 使用更优的哈希函数
        auto hash_function = [](const Point& p) {
            return static_cast<size_t>(p.first) * 1000003 + p.second;
        };
        
        std::unordered_set<Point, decltype(hash_function)> visited(0, hash_function);
        std::queue<Point> q;
        
        // 初始状态
        q.emplace(0, 0);
        visited.emplace(0, 0);

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            // 检查是否达到目标
            if (a == target || b == target || a + b == target) {
                return true;
            }

            // 预计算常用值
            int pour_x_to_y = std::min(a, y - b);
            int pour_y_to_x = std::min(b, x - a);

            // 生成所有可能的下一个状态
            const Point new_states[] = {
                {x, b},       // 填满X
                {a, y},       // 填满Y
                {0, b},       // 倒空X
                {a, 0},       // 倒空Y
                {a - pour_x_to_y, b + pour_x_to_y},  // X倒入Y
                {a + pour_y_to_x, b - pour_y_to_x}   // Y倒入X
            };

            // 处理每个可能的状态
            for (const auto& state : new_states) {
                if (visited.find(state) == visited.end()) {
                    visited.insert(state);
                    q.push(state);
                }
            }
        }

        return false;
    }
};