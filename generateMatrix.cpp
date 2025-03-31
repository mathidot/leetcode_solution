#include "util.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int left_bound = 0, right_bound = n - 1;
        int upper_bound = 0, lower_bound = n - 1;
        int current_ptr = 1;

        while (current_ptr <= n*n) {
            if (upper_bound <= lower_bound) {
                for (int i = left_bound; i <= right_bound; i++) {
                    ans[upper_bound][i] = current_ptr;
                    current_ptr++;
                }
                upper_bound++;
            }

            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) {
                    ans[i][right_bound] = current_ptr;
                    current_ptr++;
                }
                right_bound--;
            }

            if (upper_bound <= lower_bound) {
                for (int i = right_bound; i >= left_bound; i--) {
                    ans[lower_bound][i] = current_ptr;
                    current_ptr++;
                }
                lower_bound--;
            }

            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    ans[i][left_bound] = current_ptr;
                    current_ptr++;
                }
                left_bound++;
            }
        }
        return ans;
    }
};