#include "util.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        std::unordered_map<char, int> need, window;
        for (char c: p) {
            need[c]++;
        }
        int valid = 0;
        std::vector<int> ans;

        while (right < s.size()) {
            char rc = s[right];
            right++;
            
            if (need.count(rc) != 0) {
                window[rc]++;
                if (window[rc] == need[rc]) {
                    valid++;
                }
            }

            while (right-left > p.size()) {
                char lc = s[left];
                left++;
                if (need.count(lc) != 0) {
                    if (window[lc] == need[lc]) {
                        valid--;
                    }
                    window[lc]--;
                }
            }
            if (valid == need.size()) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};