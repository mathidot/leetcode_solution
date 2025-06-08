#include "util.h"

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const size_t m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (size_t i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + static_cast<int>(s1[i-1]);
        }
        for (size_t j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j-1] + static_cast<int>(s2[j-1]);
        }
        for (size_t i = 1; i <= m; i++) {
            for (size_t j = 1; j <= n; j++) {
                char c1 = s1[i-1], c2 = s2[j-1];
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(
                            dp[i-1][j] + static_cast<int>(c1),
                            dp[i][j-1] + static_cast<int>(c2));
                }
            }
        }
        return dp[m][n];
    }
};