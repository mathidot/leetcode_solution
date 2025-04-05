#include "util.h"


class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0, right = 0;
        std::vector<int> windowCharCount(26, 0);
        int windowMaxCount = 0;

        while (right < s.size()) {
            int rc = s[right] - 'A';
            right++;
            windowCharCount[rc]++;
            windowMaxCount = std::max(windowMaxCount, windowCharCount[rc]);
            while (left < right && (right - left - windowMaxCount) > k) {
                int lc = s[left] - 'A';
                left++;
                windowCharCount[lc]--;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};