#include "util.h"

class Solution {
public:
    int slidingPuzzleI(std::vector<std::vector<int>>& board) {
        constexpr std::string_view target = "123450";
        
        // 使用std::array固定大小，避免动态分配
        std::array<char, 6> start{};
        for (int i = 0, k = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                start[k++] = '0' + board[i][j];
            }
        }

        // 使用string_view减少字符串拷贝
        const std::string_view start_view(start.data(), start.size());

        // BFS初始化
        std::queue<std::string> q;
        std::unordered_set<std::string> visited;
        q.emplace(start_view);
        visited.emplace(start_view);

        // 预定义相邻位置关系
        static constexpr std::array<std::array<int, 3>, 6> neighbors = {{
            {1, 3, -1},  // 0的邻居
            {0, 2, 4},    // 1的邻居
            {1, 5, -1},   // 2的邻居
            {0, 4, -1},   // 3的邻居
            {1, 3, 5},    // 4的邻居
            {2, 4, -1}    // 5的邻居
        }};

        for (int step = 0; !q.empty(); ++step) {
            for (int sz = q.size(); sz > 0; --sz) {
                auto current = std::move(q.front());
                q.pop();

                if (current == target) {
                    return step;
                }

                const auto zero_pos = current.find('0');
                for (int adj : neighbors[zero_pos]) {
                    if (adj == -1) break;  // 无效邻居
                    
                    auto next = current;
                    std::swap(next[zero_pos], next[adj]);
                    
                    if (visited.emplace(next).second) {
                        q.push(std::move(next));
                    }
                }
            }
        }

        return -1;
    }
public:
    struct ArrayHash {
        size_t operator()(const std::array<char, 6>& arr) const {
            size_t hash = 0;
            for (char c : arr) hash = (hash * 31) + c;
            return hash;
        }
    };

    int slidingPuzzleII(std::vector<std::vector<int>>& board) {
        constexpr std::array<char, 6> target = {'1','2','3','4','5','0'};
        // 预定义的邻居关系（硬编码）
        static constexpr std::array<std::array<int, 3>, 6> neighbors = {{
            {1, 3, -1},     // 位置0的邻居是1和3
            {0, 2, 4},      // 位置1的邻居是0、2、4
            {1, 5, -1},     // 位置2的邻居是1和5
            {0, 4, -1},     // 位置3的邻居是0和4
            {1, 3, 5},      // 位置4的邻居是1、3、5
            {2, 4, -1}      // 位置5的邻居是2和4
        }};

        std::array<char, 6> start{};
        for (int i = 0, k = 0; i < 2; ++i) 
            for (int j = 0; j < 3; ++j) 
                start[k++] = '0' + board[i][j];

        std::unordered_set<std::array<char, 6>, ArrayHash> visited;
        visited.reserve(1000);
        std::queue<std::array<char, 6>> q;

        q.push(start);
        visited.insert(start);

        for (int step = 0; !q.empty(); ++step) {
            const size_t level_size = q.size();  // 当前层的节点数
            for (size_t i = 0; i < level_size; ++i) {
                auto current = q.front();
                q.pop();

                if (current == target) return step;

                const size_t zero_pos = std::distance(
                    current.begin(),
                    std::find(current.begin(), current.end(), '0')
                );

                for (int adj : neighbors[zero_pos]) {
                    if (adj == -1) break;
                    auto next = current;
                    std::swap(next[zero_pos], next[adj]);
                    if (visited.insert(next).second) {
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};