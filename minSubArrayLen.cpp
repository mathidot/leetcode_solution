#include "util.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = std::numeric_limits<int>::max();
        int left = 0, right = 0;
        int window = 0;

        while (right < nums.size()) {
            int right_num = nums[right];
            right++;
            window += right_num;
            while (left < right && window-nums[left] >= target) {
                window -= nums[left];
                left++;
            }
            if (window >= target) {
                ans = std::min(ans, right - left);
            }
        }
        return ans;
    }
};