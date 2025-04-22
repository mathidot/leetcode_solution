#include "util.h"

class Solution {
private:
    vector<vector<int>> memo;
    int count(int lo, int hi) {
        if (lo > hi) return 1;
        if (memo[lo][hi] != 0) {
            return memo[lo][hi];
        }
        int res = 0;
        for (int mid = lo; mid <= hi; mid++) {
            int left = count(lo, mid-1);
            int right = count(mid+1, hi);
            res += left * right;
        }
        memo[lo][hi] = res;
        return res;
    }
public:
    int numTrees(int n) {
        memo = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return count(1, n);
    }
};