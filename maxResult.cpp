#include "util.h"
#include "MonotonicQueue.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = nums[0];
        if (nums.size() == 1) return ans;
        MonotonicQueue<int> q;
        q.push(nums[0]);
        for (size_t i = 1; i < nums.size(); i++) {
            ans = q.max() + nums[i];
            q.push(ans);
            if (q.size() > k) {
                q.pop();
            }
        }
        return ans;
    }
};