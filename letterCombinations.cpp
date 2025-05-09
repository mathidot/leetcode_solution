#include "util.h"

class Solution {
private:
    std::unordered_map<char, std::vector<char>> dict = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}};
    vector<string> res;
    string track;

    void backtrack(std::string &digits, int index) {
        if (track.size() == digits.size()) {
            res.push_back(track);
            return;
        }

        auto alphas = dict[digits[index]];

        for (int i = 0; i < alphas.size(); i++) {
            track.push_back(alphas[i]);
            backtrack(digits, index+1);
            track.pop_back();
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if (digits.empty()) return {};
        backtrack(digits, 0);
        return res;
    }
};