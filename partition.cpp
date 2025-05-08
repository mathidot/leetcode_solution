#include "util.h"

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

class Solution {
private:
    vector<vector<string>> res;
    vector<string> track;

    void backtrack(string s, int pre_index, int start) {
        if (start == s.size()) {
            res.push_back(track);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string str = s.substr(pre_index + 1, i - pre_index);
            if (isPalindrome(str)) {
                track.push_back(str);
                backtrack(s, i, i + 1);
                track.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        res.clear();
        track.clear();
        backtrack(s, -1, 0);
        return res;
    }
};