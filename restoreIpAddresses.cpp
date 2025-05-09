#include "util.h"

vector<string> transform(vector<vector<string>> &res) {
    vector<string> ips;
    for (const vector<string> &path: res) {
        string ip;
        for (int i = 0; i < path.size()-1; i++) {
            ip.append(path[i]);
            ip.append(".");
        }
        ip.append(path.back());
        ips.push_back(ip);
    }
    return ips;
}

bool isValid(string s) {
    if (s.empty()) return false;
    if (s.size() >= 4) return false;
    if (s.size() != 1 && s.front() == '0') {
        return false;
    }
    int num = stoi(s);
    if (num >=256 || num < 0) return false;
    return true;
}


class Solution {
private:
    vector<vector<string>> res;
    vector<string> track;
    void backtrack(string s, int pre_index, int start, int count) {
        if (count == 4 && start == s.size()) {
            res.push_back(track);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string str = s.substr(pre_index + 1, i - pre_index);
            if (isValid(str)) {
                track.push_back(str);
                backtrack(s, i, i + 1, count+1);
                track.pop_back();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        track.clear();
        backtrack(s, -1, 0, 0);
        auto ans = transform(res);
        return ans;
    }
};