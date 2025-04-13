#include "util.h"

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        const int n = heights.size();
        stack<int> s;
        vector<int> counts(n, 0);
        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            while (!s.empty() && s.top() < heights[i]) {
                s.pop();
                count += 1;
            }
            counts[i] = s.empty() ? count : count+1;
            s.push(heights[i]);
        }
        return counts;
    }
};