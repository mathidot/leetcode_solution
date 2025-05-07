#include "util.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, res, track);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, int start, 
                  vector<vector<int>>& res, vector<int>& track) {
        res.push_back(track);  // 直接添加当前子集
        
        for (int i = start; i < nums.size(); ++i) {
            // 跳过重复元素，避免生成重复子集
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            track.push_back(nums[i]);
            backtrack(nums, i + 1, res, track);
            track.pop_back();
        }
    }
};