#include "util.h"
#include "Dijkstra.h"

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return 0;
        const int rows = heights.size();
        const int cols = heights.front().size();
        std::vector<std::pair<int, int>> directions =
            {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> distTo(rows * cols, numeric_limits<int>::max());
        distTo[0] = 0;
        std::priority_queue<State, vector<State>, greater<State>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.distance > distTo[current.node]) {
                continue;
            }

            int row = current.node / cols;
            int col = current.node % cols;

            if (row == rows-1 && col == cols - 1) {
                return current.distance;
            }            

            for (auto dir : directions) {
                int new_row = row + dir.first;
                int new_col = col + dir.second;
                int index_new = new_row * cols + new_col;
                if (new_row>=0 && new_row<rows && new_col>=0 && new_col<cols) {
                    int newDist = max(distTo[current.node],
                        abs(heights[new_row][new_col] - heights[row][col]));
                    if (newDist < distTo[index_new]) {
                        distTo[index_new] = newDist;
                        pq.emplace(index_new, newDist);
                    }
                }
            }
        }

        return -1;
    }
};