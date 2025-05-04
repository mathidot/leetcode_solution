#include "util.h"
#include "Dijkstra.h"

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int rows = heights.size();
        const int cols = heights.front().size();
        std::vector<std::pair<int, int>> directions =
            {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        Graph graph(rows * cols);

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                int index = x * rows + y;
                for (auto dir : directions) {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;
                    int index_new = new_x * rows + new_y;
                    if (new_x>=0 && new_x<rows && new_y>=0 && new_y<cols) {
                        graph.addDirectedEdge(index, index_new, std::abs(heights[x][y]-heights[new_x][new_y]));
                    }
                }
            }
        }

        return 0;
    }
};