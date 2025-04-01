#include "util.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t min_len = std::numeric_limits<size_t>::max();
        for (int i = 0; i < strs.size(); i++) {
            min_len = std::min(min_len, strs[i].size());
        }
        int ans = 0;
        if (min_len == 0) return "";
        for (int len = 0; len < min_len; len++) {
            bool done = true;
            for (int i = 0; i < strs.size(); i++) {
                if (i == 0) continue;
                if (strs[i][len] != strs[i-1][len]) {
                    done = false;
                    break;
                }                
            }
            if (done == true) {
                ans = len + 1;
            } else {
                break;
            }
        }
        return strs.front().substr(0, ans);
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    Solution solution;
    auto res = solution.longestCommonPrefix(strs);
}