#include "util.h"

class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int> &coins, int amount) {
        vector<int> memo(amount+1, -666);
        return dp(coins, amount);
    }

    int dp(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo[amount] != -666) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (int coin : coins) {
            // 计算子问题的结果
            int subProblem = dp(coins, amount - coin);

            // 子问题无解则跳过
            if (subProblem == -1) continue;
            // 在子问题中选择最优解，然后加一
            res = min(res, subProblem + 1);
        }
        // 把计算结果存入备忘录
        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }
};