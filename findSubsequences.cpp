#include "util.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(vector<int> &nums, int start) {
        if (track.size() >= 2) {
            res.push_back(track);
        }
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {
            if ((!track.empty() && track.back() > nums[i]) || used.count(nums[i]) != 0) {
                continue;
            }

            used.insert(nums[i]);
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            used.erase(nums[i]);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        track.clear();
        vector<bool> used(nums.size(), false);
        backtrack(nums, 0);
        return res;
    }
};