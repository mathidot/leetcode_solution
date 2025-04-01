#include "util.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // find longest window sum = sum(nums) - k
        int max_len = 0;
        bool is_existed = false;
        int left = 0, right = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int target = sum - x;
        int window = 0;
        while (right < nums.size()) {
            window += nums[right];
            right++;
            while (left < right && window > target) {
                window -= nums[left];
                left++;
            }
            if (window == target) {
                max_len = std::max(max_len, right - left);
                is_existed = true;
            }
        }

        return is_existed ? nums.size() - max_len : -1;
    }
};

int main() {
    vector<int> nums = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    Solution solution;
    auto res = solution.minOperations(nums, 134365);
    return 0;
}