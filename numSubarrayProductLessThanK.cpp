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
                printf("left: %d, right: %d\n", left, right);
                ans++;
            }
            while (left < right && window >= k) {
                window /= nums[left];
                left++;
            }
            ans += (right - left);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums{10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    auto res = solution.numSubarrayProductLessThanK(nums, 19);
}