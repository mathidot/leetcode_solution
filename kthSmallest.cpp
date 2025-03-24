#include "util.h"

struct IndexInfo{
    int val;
    std::pair<int, int> index;
    IndexInfo(int val_, std::pair<int, int> index_):
        val(val_), index(index_) {}
};

struct cmp
{
    bool operator()(const IndexInfo &lhs, const IndexInfo &rhs) {
        return lhs.val < rhs.val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        std::vector<int> pts(matrix.size(), 0);
        std::priority_queue<IndexInfo, std::vector<IndexInfo>, cmp> min_heap;
        for (int i = 0; i < n; i++) {
            min_heap.emplace(IndexInfo{matrix[0][i], {0,i}});
        }
        for (int i = 0; i < k-1; i++) {
            auto [val, index] = min_heap.top();
            min_heap.pop();
            if (index.first < n - 1) {
                min_heap.emplace(IndexInfo{matrix[index.first+1][index.second], {index.first+1, index.second}});
            }
        }
        return min_heap.top().val;
    }
};