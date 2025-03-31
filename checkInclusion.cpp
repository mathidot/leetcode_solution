#include "util.h"

class Solution {
public:
    bool isSubset(string s1, std::unordered_map<char, int> rec) {
        for (char c: s1) {
            if (rec.find(c) == rec.end()) {
                return false;
            } else {
                rec[c] -= 1;
                if (rec[c] < 0) return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        std::unordered_map<char, int> need, window;
        int cnt = 0;
        for (char c: s1) {
            need[c]++;
        }

        while (right < s2.size()) {
            char rc = s2[right];
            if (need.count(rc) == 0) {
                cnt++;
            } else {
                if (window[rc] < need[rc]) {
                    window[rc]++;
                } else {
                    window[rc]++;
                    cnt++;
                }
            }
            right++;
            // [left, right)
            printf("[l:%d, r:%d), cnt:%d, str:%s\n", left, right, cnt, s2.substr(left, right-left));
            while (left < right && cnt != 0) {
                int lc = s2[left];
                if (need.count(lc) == 0) {
                    cnt--;
                } else if (need[lc] < window[lc]) {
                    window[lc]--;
                    cnt--;
                } else {
                    window[lc]--;
                }
                left++;
            }
            if ((right - left) == s1.length()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    auto res = solution.checkInclusion("abcdxabcde", "abcdeabcdx");
    return 0;
}