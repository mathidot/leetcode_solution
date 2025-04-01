#include "util.h"

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        std::unordered_map<int, std::vector<int>> diagonalVector;
        int m = mat.size(), n = mat.front().size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diagonal_id = i - j;
                diagonalVector[diagonal_id].push_back(mat[i][j]);
            }
        }
        
        for (auto &vecMap: diagonalVector) {
            std::sort(vecMap.second.begin(), vecMap.second.end(), std::greater<int>());
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int diagonal_id = i - j;
                ans[i][j] = diagonalVector[diagonal_id].back();
                diagonalVector[diagonal_id].pop_back();
            }
        }
        return ans;
    }
};