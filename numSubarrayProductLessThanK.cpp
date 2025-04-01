#include "util.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int window = 1;
        int ans = 0;

        while (right < nums.size()) {
            window *= nums[right];
            right++;
            if (window < k) {
                ans++;
            }
            while (left < right && window < k) {
                window /= nums[left];
                left++;
                if (window < k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};