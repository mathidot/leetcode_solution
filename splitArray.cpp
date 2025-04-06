#include "util.h"

class Solution {
public:
    int calcArrays(vector<int> &nums, int s) {
        int n = 0;
        int p = s;
        for (int i = 0; i < nums.size(); i++) {
            if (p - nums[i] < 0) {
                p = s;
                n += 1;
            }
            p -= nums[i];
        }
        return n+1;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = std::accumulate(nums.begin(), nums.end(), 0) + 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int n = calcArrays(nums, mid);
            if (n > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};