#include "util.h"
#include "Dijkstra.h"

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph graph(n);
        for (const auto &time: times) {
            graph.addDirectedEdge(time[0]-1, time[1]-1, time[2]); // 节点编号转为0-based
        }
        auto distTo = dijkstra(k-1, graph); // 节点编号转为0-based
        auto maxTime = *max_element(distTo.begin(), distTo.end());
        int result = maxTime == numeric_limits<int>::max() ? -1 : maxTime;
        return result;
    }
};