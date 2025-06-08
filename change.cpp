#include "util.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const size_t n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount+1, 0));
        for (size_t i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (size_t i = 0; i <= amount; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i-1] >= 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};