#include "util.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int p = n-1;
        vector<int> res(n);
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[p--] = nums[left] * nums[left];
                left++;
            } else {
                res[p--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};