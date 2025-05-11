#include "util.h"

class Solution {
private:
    static constexpr array<char, 4> nucleotides{'A', 'C', 'G', 'T'};
    
    struct StringHash {
        size_t operator()(const string& s) const {
            size_t hash = 0;
            for (char c : s) {
                hash = (hash * 131) + c;  // 使用更大的质数减少冲突
            }
            return hash;
        }
    };

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 快速检查
        if (startGene == endGene) return 0;
        
        unordered_set<string, StringHash> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;

        // 使用更高效的哈希容器
        unordered_set<string, StringHash> visited;
        visited.reserve(bank.size() + 1);
        queue<string> q;
        
        q.push(startGene);
        visited.insert(startGene);

        for (int steps = 0; !q.empty(); ++steps) {
            const size_t levelSize = q.size();
            for (size_t i = 0; i < levelSize; ++i) {
                string current = move(q.front());
                q.pop();

                // 生成所有可能的突变
                for (size_t j = 0; j < current.size(); ++j) {
                    const char original = current[j];
                    for (const char c : nucleotides) {
                        if (c == original) continue;
                        
                        current[j] = c;
                        if (bankSet.count(current) && visited.insert(current).second) {
                            if (current == endGene) return steps + 1;
                            q.push(current);
                        }
                    }
                    current[j] = original;  // 恢复原字符
                }
            }
        }

        return -1;
    }
};