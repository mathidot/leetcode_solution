#include "util.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int left = 0, right = 0;
        std::unordered_map<char, int> window;
        int ans = 1;

        while(right < s.size()) {
            char rc = s[right];
            right++;
            window[rc]++;

            while (left < right && window[rc] >= 2) {
                char lc = s[left];
                left++;
                window[lc]--;
            }

            ans = std::max(ans, right-left);
        }
        return ans;
    }
};