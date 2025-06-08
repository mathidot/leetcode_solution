#include "util.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const size_t len1 = text1.size(), len2 = text2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for (size_t i = 1; i <= len1; i++) {
            for (size_t j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = std::max(dp[i-1][j-1]+1, std::max(dp[i-1][j], dp[i][j-1]));
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
