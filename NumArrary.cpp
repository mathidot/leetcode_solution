#include "util.h"

class NumArray {
private:
    std::vector<int> pre_sum;
public:
    NumArray(vector<int>& nums) {
        pre_sum.resize(nums.size() + 1);
        for (int i = 1; i < pre_sum.size(); i++) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right+1] - pre_sum[left];
    }
};