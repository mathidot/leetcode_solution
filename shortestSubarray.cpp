#include "util.h"
#include "MonotonicQueue.h"
#include "NumArray.h"

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long> pre_sum(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }

        int left = 0, right = 0;
        int ans = numeric_limits<int>::max();
        MonotonicQueue<long> window;

        while (right <= nums.size()) {
            long right_sum = pre_sum[right];
            right++;
            window.push(right_sum);
            while (left < right && (right_sum - window.min()) >= k) {
                int current_len = right - left - 1; // -1 because right was already incremented
                ans = min(ans, current_len);
                left++;
                window.pop();
            }
        }

        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};
    