#include "util.h"
#include "MonotonicQueue.h"

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = std::numeric_limits<int>::min();
        if (nums.size() == 1) return nums.front();
        MonotonicQueue<int> q;
        q.push(nums[0]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = max(q.max() + nums[i], nums[i]);
            q.push(dp[i]);
            if (q.size() > k) q.pop();
        }
        for (size_t i = 0; i < nums.size(); i++) {
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};