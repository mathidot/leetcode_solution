#include "util.h"

class Solution {
private:
    std::array<std::array<char, 2>, 10> buildNeighbors() {
        std::array<std::array<char, 2>, 10> neighbors;
        for (int i = 0; i <= 9; i++) {
            if (i == 0) {
                neighbors[i] = {'9', '1'};
            } else if (i == 9) {
                neighbors[i] = {'8', '0'};
            } else {
                neighbors[i] = {static_cast<char>((i-1)+'0'), static_cast<char>((i+1)+'0')};
            }
        }
        return neighbors;
    }

    struct ArrayHash {
        size_t operator()(const std::array<char, 4> &arr) const {
            size_t hash = 0;
            for (char c : arr) hash = (hash * 31) + c;
            return hash;
        }
    };

    std::unordered_set<std::array<char, 4>, ArrayHash> buildDeadlocks(vector<string> &deadlocks) { 
        std::unordered_set<std::array<char, 4>, ArrayHash> ret;
        for (const string &deadlock: deadlocks) {
            std::array<char, 4> tmp;
            std::copy(deadlock.begin(), deadlock.end(), tmp.begin());
            ret.insert(tmp);
        }
        return ret;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        std::array<char, 4> start{'0', '0', '0', '0'};
        std::array<char, 4> end = {target[0], target[1], target[2], target[3]};
        auto neighbors = buildNeighbors();
        auto deadlocks = buildDeadlocks(deadends);

        if (deadlocks.count(start) != 0) return -1;

        std::unordered_set<std::array<char, 4>, ArrayHash> visited1, visited2;
        visited1.reserve(100);
        visited2.reserve(100);
        std::queue<std::array<char, 4>> q1, q2;
        q1.push(start);
        q2.push(end);
        visited1.insert(start);
        visited2.insert(end);
        int steps = 0;

        while (!q1.empty() && !q2.empty()) {
            // 总是扩展较小的队列
            if (q1.size() > q2.size()) {
                swap(q1, q2);
                swap(visited1, visited2);
            }
            const size_t level_size = q1.size();
            for (size_t i = 0; i < level_size; i++) {
                auto current = q1.front();
                q1.pop();

                if (visited2.count(current)) {
                    return steps;
                }

                for (int i = 0; i < 4; i++) {
                    for (const char c: neighbors[current[i] - '0']) {
                        auto next = current;
                        next[i] = c;
                        if (!deadlocks.count(next) && !visited1.count(next)) {
                            visited1.insert(next);
                            q1.push(next);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};