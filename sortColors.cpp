#include "util.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // [0, p0)是元素0的区间，(p2, nums.length-1]是2的区间
        int p0 = 0, p2 = nums.size() - 1;
        int p = 0;

        while (p <= p2) {
            if (nums[p] == 0) {
                printf("nums[%d] is 0\n", p);
                printf("swap %d and %d\n", nums[p0], nums[p]);
                std::swap(nums[p0], nums[p]);
                p0++;
            } 
            if (nums[p] == 2) {
                printf("nums[%d] is 2\n", p);
                printf("swap %d and %d\n", nums[p2], nums[p]);
                std::swap(nums[p2], nums[p]);
                p2--;
            } else {
                p++;
            }
        }
    }
};