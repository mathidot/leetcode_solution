#include "util.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        vector<bool> used(nums.size(), false);
        backtrack(nums, res, track, used);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, vector<vector<int>>& res, 
                  vector<int>& track, vector<bool>& used) {
        if (track.size() == nums.size()) {
            res.push_back(track);  // 直接使用track，避免临时构造vector
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // 做选择
            used[i] = true;
            track.push_back(nums[i]);
            
            backtrack(nums, res, track, used);
            
            // 撤销选择
            track.pop_back();
            used[i] = false;
        }
    }
};