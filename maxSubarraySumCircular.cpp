#include "util.h"
#include "MonotonicQueue.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> pre_sum(2*n+1, 0);
        for (size_t i = 1; i < pre_sum.size(); i++) {
            pre_sum[i] = pre_sum[i-1] + nums[(i-1)% n];
        }
        int ans = std::numeric_limits<int>::min();
        MonotonicQueue<int> q;
        q.push(pre_sum.front());
        for (size_t i = 1; i < pre_sum.size(); i++) {
            ans = std::max(ans, pre_sum[i] - q.min());
            q.push(pre_sum[i]);
            if (q.size() == n) {
                q.pop();
            }
        }
        return ans;
    }
};