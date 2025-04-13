#include "util.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        stack<int> incrSt;
        for (int i = 0; i < nums.size(); i++) {
            while (!incrSt.empty() && nums[incrSt.top()] > nums[i]) {
                left = std::min(left, incrSt.top());
                incrSt.pop();
            }
            incrSt.push(i);
        }
        stack<int> decrSt;
        for (int i = n-1; i >= 0; i--) {
            while (!decrSt.empty() && nums[decrSt.top()] < nums[i]) {
                right = std::max(right, decrSt.top());
                decrSt.pop();
            }
            decrSt.push(i);
        }
        if (left == std::numeric_limits<int>::max() &&
            right == std::numeric_limits<int>::min())
        {
            return 0;
        }
        return right - left + 1;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy_nums(nums);
        std::sort(copy_nums.begin(), copy_nums.end());
        int left = -1, right = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy_nums[i]) {
                left = i;
                break;
            }
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] != copy_nums[i]) {
                right = i;
                break;
            }
        }
        if (left == -1 && right == -1) return 0;
        return right - left + 1;
    }
};
