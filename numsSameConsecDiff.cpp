#include "util.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    void dfs(int n, int k) {
        if (track.size() == n) {
            res.push_back(track);
            return;
        }

        if (track.size() == 0) {
            for (int i = 1; i <= 9; i++) {
                track.push_back(i);
                dfs(n, k);
                track.pop_back();
            }
        } else {
            for (int i = 0; i <= 9; i++) {
                if (std::abs(i - track.back()) == k) {
                    track.push_back(i);
                    dfs(n, k);
                    track.pop_back();
                }
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        res.clear();
        track.clear();
       
        vector<int> ans;
        dfs(n, k);
        for (auto digits: res) {
            int num = 0;
            for (int i = 0; i < digits.size(); i++) {
                num = num * 10 + digits[i];
            }
            ans.push_back(num);
        }
        return ans;
    }
};