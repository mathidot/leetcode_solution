#include "util.h"

struct Info {
    int index;
    int val1;
    int val2;
    Info(int index_, int val1_, int val2_)
        : index(index_), val1(val1_), val2(val2_) {}
    int sum() const noexcept {
        return val1 + val2;
    }
};

struct cmp {
    bool operator()(const Info &lhs, const Info &rhs) {
        return lhs.sum() < rhs.sum();
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<std::vector<int>> ans;
        std::priority_queue<Info, std::vector<Info>, cmp> min_heap;
        for (int i = 0; i < nums1.size(); i++) {
            min_heap.emplace(Info{0, nums1[i], nums2[0]});
        }

        for (int i = 0; i < k; i++) {
            Info topVal = min_heap.top();
            min_heap.pop();
            ans.push_back({topVal.val1, topVal.val2});
            if (topVal.index < nums2.size() - 1) {
                min_heap.emplace(Info{topVal.index+1, topVal.val1, nums2[topVal.index+1]});
            }
        }
        return ans;
    }
};