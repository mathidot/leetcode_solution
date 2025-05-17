#include "util.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const size_t n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        vector<int> f;
        for (size_t i = 0; i < envelopes.size(); i++) {
            if (f.empty() || envelopes[i][1] > f.back()) {
                f.push_back(envelopes[i][1]);
            } else {
                auto it = std::lower_bound(f.begin(), f.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        return f.size();
    }
};