#include "util.h"
#include "Dijkstra.h"

// 自定义 State 结构体
struct Node {
    int node;
    double distance;
    
    // 构造函数
    Node(int n, double d) : node(n), distance(d) {}
    
    // 重载比较运算符用于优先队列
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        GraphDouble graph(n);
        for (size_t i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            graph.addUndirectedEdge(from, to, weight);
        }

        vector<double> distTo(n, -1);

        std::priority_queue<Node, vector<Node>, less<Node>> pq;
        pq.emplace(start_node, 1.0);

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (current.node == end_node) {
                return current.distance;
            }

            if (current.distance < distTo[current.node]) {
                continue;
            }

            for (auto neighbor: graph.neighbors(current.node)) {
                double new_dist = current.distance * graph.weight(current.node, neighbor);
                if (new_dist > distTo[neighbor]) {
                    distTo[neighbor] = new_dist;
                    pq.emplace(neighbor, new_dist);
                }
            }            
        }

        return 0.0;
    }
};