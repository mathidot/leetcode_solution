#include "util.h"

class SolutionI {
public:
    void shiftOne(vector<vector<int>>& grid) {
        for (auto &vec: grid) {
            int last = vec.back();
            vec.pop_back();
            vec.insert(vec.begin(), last);
        }
        int last = grid[grid.size()-1][0];
        for (int i = grid.size()-2; i >= 0 ; i--) {
            grid[i+1][0] = grid[i][0];
        }
        grid[0][0] = last;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid);
        for (int i = 0; i < k; i++) {
            shiftOne(ans);
        }
        return ans;
    }
};

class SolutionII {
public:
    std::pair<int, int> convertCoordinate(int index, int rows, int cols) {
        int x = index / cols;
        int y = index % cols;
        return {x, y};
    }

    void reverse(vector<vector<int>> &grid, int start, int count) {
        int left = start, right = start + count - 1;
        int m = grid.size(), n = grid.front().size();
        while (left < right) {
            auto [x1, y1] = convertCoordinate(left, m, n);
            auto [x2, y2] = convertCoordinate(right, m, n);
            std::swap(grid[x1][y1], grid[x2][y2]);
            left++;
            right--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid.front().size();
        k = k % (m * n);
        reverse(grid, 0, m*n-k);
        reverse(grid, m*n-k, k);
        reverse(grid, 0, m*n);
        return grid;
    }
}