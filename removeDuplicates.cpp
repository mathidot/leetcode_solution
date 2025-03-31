#include "util.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
    
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                int count = 0;
                while (fast + 1 < nums.size() && nums[fast] == nums[fast+1]) {
                    fast++;
                    count++;
                }
                if (count >= 1) {
                    nums[slow] = nums[fast];
                    nums[slow+1] = nums[fast];
                    slow += 2;
                } else {
                    nums[slow] = nums[fast];
                    slow += 1;
                }
            }
            fast++;
        }
        return slow+1;
    }

    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 2) return nums.size();
        int slow = 2;
        for (int fast = 2; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow-2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};