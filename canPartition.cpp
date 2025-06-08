#include "util.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;

        vector<int> dp(sum+1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = sum; j >= num; j--) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[sum];
    }
};


// dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];