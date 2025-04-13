#include "util.h"

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? prices[i] : prices[i] - s.top();
            s.push(prices[i]);
        }
        return ans;
    }
};