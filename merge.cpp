#include "util.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int p = 0;
        vector<int> nums(m+n, 0);
        while(p1 < m && p2 < n) {
            if (nums1[p1] <= nums2[p2]) {
                nums[p++] = nums1[p1++];
            } else {
                nums[p++] = nums2[p2++];
            }
        }
        while (p1 < m) {
            nums[p++] = nums1[p1++];
        }
        while (p2 < m) {
            nums[p++] = nums2[p2++];
        }
        for (int i = 0; i < m+n; i++) {
            nums1[i] = nums[i];
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    solution.merge(nums1, 1, nums2, 0);
}