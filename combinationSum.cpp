#include "util.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> track;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, res, track, sum, target);
        return res;
    }

private:
    void backtrack(const vector<int>& nums, int start, 
                  vector<vector<int>>& res, vector<int>& track,
                    int &sum, int target)
    {
        if (sum == target) {
            res.push_back(track);  // 直接添加当前子集
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            sum += nums[i];
            backtrack(nums, i, res, track, sum, target);
            track.pop_back();
            sum -= nums[i];
        }
    }
};