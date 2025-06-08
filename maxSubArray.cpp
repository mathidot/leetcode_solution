#include "util.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int ans = std::numeric_limits<int>::min();
        dp[0] = nums.front();
        ans = std::max(ans, dp[0]);
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};