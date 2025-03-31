#include "util.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int alpha_num = 0;
        int valid = 0;
        string ans = "";
        int min_len = __INT_MAX__;
        std::unordered_map<char, int> need, window;
        for (auto c: t) {
            need[c]++;
        }

        while (right < s.size()) {
            char c = s[right];
            if (need.count(c) != 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid += 1;
                }
            }
            right++;
            while (left <= right) {
                char c = s[left];
                if (need.find(c) == need.end()) {
                    left++;
                } else {
                    if (window[c] > need[c]) {
                        left++;
                        window[c]--;
                    } else {
                        break;
                    }
                }
            }
            if (valid == need.size()) {
                if (right-left < min_len) {
                    min_len = right - left;
                    ans = s.substr(left, min_len);
                }
            }
        }

        return ans;
    }
};