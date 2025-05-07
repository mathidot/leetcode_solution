#include "util.h"

class Solution {
private:
    void backtrack(const vector<int> &nums, vector<vector<int>> &res,
                vector<int> &track, vector<bool> &used) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }

            // 做选择
            used[i] = true;
            track.push_back(nums[i]);
            
            backtrack(nums, res, track, used);
            
            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }

    void backtrack(const vector<int> &nums, vector<vector<int>> &res,
                vector<int> &track, vector<bool> &used) {
        if (track.size() == nums.size()) {
            res.push_back(vector<int>(track.begin(), track.end()));
            return;
        }

        // 记录之前树枝上元素的值
        // 注意同层级的元素比较要放在循环外面
        int prevNum = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            // 排除不合法的选择
            if (used[i]) {
                continue;
            }
            if (nums[i] == prevNum) {
                continue;
            }
            /*
            如果要在不同层级之间进行比较
            int newPrevLevelNum = nums[i]; // 传递给下一层
            backtrack(..., newPreLevelNum)
            */

            track.push_back(nums[i]);
            used[i] = true;
            // 记录这条树枝上的值
            prevNum = nums[i];
            backtrack(nums, res, track, used);
            track.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtrack(nums, res, track, used);
        return res;
    }
};