#include "util.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        int upper_bound = 0, lower_bound = m-1;
        int left_bound = 0, right_bound = n-1;
        std::vector<int> ans;
        while(ans.size() < m*n) {
            if (upper_bound <= lower_bound) {
                for (int i = left_bound; i <= right_bound; i++) {
                    ans.push_back(matrix[upper_bound][i]);
                }
                upper_bound++;
            }

            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) {
                    ans.push_back(matrix[i][right_bound]);
                }
                right_bound--;
            }

            if (upper_bound <= lower_bound) {
                for (int i = right_bound; i >= left_bound; i--) {
                    ans.push_back(matrix[lower_bound][i]);
                }
                lower_bound--;
            }

            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    ans.push_back(matrix[i][left_bound]);
                }
                left_bound++;
            }
        }
        return ans;
    }
};