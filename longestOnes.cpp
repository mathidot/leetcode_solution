#include "util.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int count = k;
        int ans = std::numeric_limits<int>::min();
        while (right < nums.size()) {
            ans = std::max(ans, right - left + 1);
            if (nums[right] == 1) {
                right++;
                ans = std::max(ans, right - left);
            } else if (nums[right] == 0 && count > 0) {
                right++;
                count--;
                ans = std::max(ans, right - left);
            } else {
                while (left <= right) {
                    if (nums[left] == 0) {
                        count++;
                        left++;
                        break;
                    } else {
                        left++;
                    }
                }
            }
        }
        ans = std::max(ans, right - left);
        return ans;
    }

    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int windowOneCount = 0;
        int ans = 0;
        while (right < nums.size()) {
            // 扩大窗口
            if (nums[right] == 1) {
                windowOneCount++;
            }
            right++;

            while (right - left - windowOneCount > k) {
                if (nums[left] == 1) {
                    windowOneCount--;
                }
                left++;
            }
            ans = std::max(ans, right - left);
        }
        return ans;
    }
};