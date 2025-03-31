#include "util.h"

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int left = 0, right = s.size()-1;
        while(left < right) {
            while (left < s.size() && !std::isalnum(s[left])) left++;
            while (right >= 0 && !std::isalnum(s[right])) right--;
            if (left >= right) return true;

            char lc = std::tolower(s[left]);
            char rc = std::tolower(s[right]);
            if (lc != rc) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};