#include "util.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> s;
        const int n = temperatures.size();
        for (int i = n - 1; i >= 0; i--) {
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);           
        }
        return res;
    }
};