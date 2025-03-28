#include "util.h"

class Solution {
public:
    string Palindrome(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindromeI(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            string s1 = Palindrome(s, i, i);
            string s2 = Palindrome(s, i, i+1);
            res = res.length() > s1.length() ? res: s1;
            res = res.length() > s2.length() ? res: s2;
        }
        return res;
    }


    string longestPalindrome(string s) {
        int s_len = s.size();
        if (s_len == 0) return "";
        if (s_len == 1) return s;
        int len_max = 1;
        int start = 0;
        vector<vector<int>> dp(s_len, vector<int>(s_len, 0));
        for (int i = 0; i < s_len; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= s_len; len++) {
            for (int left = 0; left < s_len; left++) {
                int right = left + len - 1;
                if (right >= s_len) break;

                if (len == 2 && s[left] == s[right]) {
                    dp[left][right] = 1;
                    if (len > len_max) {
                        len_max = len;
                        start = left;
                    }
                }

                if (dp[left + 1][right-1] == 1 && s[left] == s[right]) {
                    dp[left][right] = 1;
                    ans = s.substr(left, len);
                    if (len > len_max) {
                        len_max = len;
                        start = left;
                    }
                }
            }
        }

        return s.substr(start, len_max);
    }
};