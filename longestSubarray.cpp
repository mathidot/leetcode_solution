#include "util.h"
#include "MonotonicQueue.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        MonotonicQueue<int> q;
        int left = 0, right = 0;
        int ans = 0;
        while (right < nums.size()) {
            int right_num = nums[right];
            right++;
            q.push(right_num);
            while (left < right && (q.max() - q.min()) > limit) {
                left++;
                q.pop();
            }
            ans = std::max(ans, right - left);
        }
        return ans;
    }
};