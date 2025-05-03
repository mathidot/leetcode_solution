#include "util.h"
#include "UF.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind<int> uf;
        vector<int> ans{};
        for(const auto &edge: edges) {
            uf.add(edge[0]);
            uf.add(edge[1]);
            if (uf.isConnected(edge[0], edge[1])) {
                ans = edge;
            } else {
                uf.unionSets(edge[0], edge[1]);
            }
        }

        return ans;
    }
};