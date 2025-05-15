#include "util.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> emailToIndexes;
        for (int i = 0; i < accounts.size(); i++) {
            vector<string> &account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                string email = account[j];
                emailToIndexes[email].push_back(i);
            }
        }

        // 计算合并后的账户
        vector<vector<string>> res;
        unordered_set<string> visitedEmails;

        for (const auto &[email, indexes]: emailToIndexes) {
            if (visitedEmails.count(email)) {
                continue;
            }

            deque<string> mergedEmail;
            queue<string> q;
            q.push(email);
            visitedEmails.insert(email);

            while (!q.empty()) {
                string current = q.front();
                q.pop();
                mergedEmail.push_back(current);
                for (int index: emailToIndexes[current]) {
                    vector<string> &account = accounts[index];
                    for (int j = 1; j < account.size(); j++) {
                        string nextEmail = account[j];
                        if (!visitedEmails.count(nextEmail)) {
                            q.push(nextEmail);
                            visitedEmails.insert(nextEmail);
                        }
                    }
                }
            }
            string username = accounts[emailToIndexes[email][0]][0];
            std::sort(mergedEmail.begin(), mergedEmail.end());
            mergedEmail.push_front(username);
            res.push_back(vector<string>(mergedEmail.begin(), mergedEmail.end()));
        }
        return res;
    }
};