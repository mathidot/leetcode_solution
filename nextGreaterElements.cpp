#include "util.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        stack<int> s;
        const int n = nums.size();

        for (int i = 2*n-1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                s.pop();
            }
            ans[i % n] = s.empty() ? -1 : s.top();
            s.push(nums[i%n]);
        }
        return ans;
    }
};