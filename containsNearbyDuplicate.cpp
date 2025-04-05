#include "util.h"

class Solution {
public:
    bool containsNearbyDuplicateI(vector<int>& nums, int k) {
        int left = 0, right = 0;
        std::unordered_set<int> window;
        while (right < nums.size()) {
            int right_num = nums[right];
            if (window.count(right_num)) return true;
            window.insert(right_num);
            right++;
            while (right - left > k) {
                window.erase(nums[left]);
                left++;
            }

        }
        return false;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int left = 0, right = 0;
        multiset<int> window;
        while (right < nums.size()) {
            int right_num = nums[right];
            
            // 检查是否存在满足条件的元素
            auto it = window.lower_bound(right_num - valueDiff);
            if (it != window.end() && *it <= (right_num + valueDiff)) {
                return true;
            }
            
            // 添加当前元素到窗口
            window.insert(right_num);
            right++;
            
            // 维护窗口大小不超过indexDiff
            while (left < right && (right - left) > indexDiff) {
                int left_num = nums[left];
                window.erase(left_num);
                left++;
            }
        }
        
        return false;
    }
};