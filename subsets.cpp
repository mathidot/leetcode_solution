#include "util.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;

    void backtrack(vector<int> &nums, int start) {
        res.push_back(track);

        for (int i = start; i< nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i+1);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        track.clear();
        backtrack(nums, 0);
        return res;
    }
};