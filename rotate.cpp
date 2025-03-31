#include "util.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto &vec: matrix) {
            std::reverse(vec.begin(), vec.end());
        }        
    }
};