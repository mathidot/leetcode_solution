#include "util.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;

    void backtrack(int start, int n, int k) {
        if (k == track.size()) {
            res.push_back(track);
            return;
        }

        for (int i = start; i <= n; i++) {
            track.push_back(i);
            backtrack(i+1, n, k);
            track.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
       res.clear();
       track.clear();
       backtrack(1, n, k);
       return res; 
    }
};