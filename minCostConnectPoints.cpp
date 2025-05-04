#include "util.h"
#include "UF.h"

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const size_t n = points.size();
        vector<vector<int>> edges;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                edges.push_back({static_cast<int>(i), static_cast<int>(j),
                    std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1])});
            }
        }

        std::sort(edges.begin(), edges.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[2] < rhs[2];
        });

        UF uf(n);

        int ans = 0;
        for (size_t i = 0; i < edges.size(); i++) {
            if (uf.connected(edges[i][0], edges[i][1])) {
                continue;
            }

            ans += edges[i][2];
            uf.union_(edges[i][0], edges[i][1]);
        }

        return ans = uf.count() == 1 ? ans : -1;
    }
};
