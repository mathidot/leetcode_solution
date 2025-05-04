#include "util.h"

#include <vector>
#include <unordered_map>
#include <utility> // for pair

class Graph {
private:
    // 使用邻接表表示图
    std::vector<std::vector<std::pair<int, int>>> adjList; // 存储(邻居节点, 权重)
    
    // 检查节点ID是否有效
    bool isValidNode(int node) const {
        return node >= 0 && node < adjList.size();
    }

public:
    // 构造函数，创建指定节点数的图
    explicit Graph(int nodeCount = 0) : adjList(nodeCount) {}

    // 添加有向边
    void addDirectedEdge(int from, int to, int weight) {
        if (!isValidNode(from) || !isValidNode(to)) return;
        adjList[from].emplace_back(to, weight);
    }

    // 添加无向边
    void addUndirectedEdge(int node1, int node2, int weight) {
        addDirectedEdge(node1, node2, weight);
        addDirectedEdge(node2, node1, weight);
    }

    // 返回图中节点数量
    int size() const {
        return adjList.size();
    }

    // 返回指定节点的所有邻居节点ID
    std::vector<int> neighbors(int node) const {
        std::vector<int> result;
        if (!isValidNode(node)) return result;
        
        for (const auto& [neighbor, _] : adjList[node]) {
            result.push_back(neighbor);
        }
        return result;
    }

    // 返回两个节点之间的权重
    int weight(int from, int to) const {
        if (!isValidNode(from) || !isValidNode(to)) {
            return std::numeric_limits<int>::max(); // 无效节点返回"无穷大"
        }
        
        for (const auto& [neighbor, weight] : adjList[from]) {
            if (neighbor == to) {
                return weight;
            }
        }
        return std::numeric_limits<int>::max(); // 无边连接返回"无穷大"
    }

    // 可选：打印图结构（调试用）
    void print() const {
        for (int i = 0; i < adjList.size(); ++i) {
            std::cout << "Node " << i << " -> ";
            for (const auto& [neighbor, weight] : adjList[i]) {
                std::cout << neighbor << "(" << weight << ") ";
            }
            std::cout << std::endl;
        }
    }
};

class GraphDouble {
private:
    // 修改权重为 double 类型
    std::vector<std::vector<std::pair<int, double>>> adjList;

    bool isValidNode(int node) const {
        return node >= 0 && node < adjList.size();
    }

public:
    explicit GraphDouble(int nodeCount = 0) : adjList(nodeCount) {}

    // 修改权重参数为 double
    void addDirectedEdge(int from, int to, double weight) {
        if (!isValidNode(from) || !isValidNode(to)) return;
        adjList[from].emplace_back(to, weight);
    }

    void addUndirectedEdge(int node1, int node2, double weight) {
        addDirectedEdge(node1, node2, weight);
        addDirectedEdge(node2, node1, weight);
    }

    int size() const { return adjList.size(); }

    std::vector<int> neighbors(int node) const {
        std::vector<int> result;
        if (!isValidNode(node)) return result;
        for (const auto& [neighbor, _] : adjList[node]) {
            result.push_back(neighbor);
        }
        return result;
    }

    // 返回 double 类型权重
    double weight(int from, int to) const {
        if (!isValidNode(from) || !isValidNode(to)) {
            return 0.0; // 无效节点返回0概率
        }
        for (const auto& [neighbor, weight] : adjList[from]) {
            if (neighbor == to) return weight;
        }
        return 0.0; // 无边连接返回0概率
    }
};

// 自定义 State 结构体
struct State {
    int node;
    int distance;
    
    // 构造函数
    State(int n, int d) : node(n), distance(d) {}
    
    // 重载比较运算符用于优先队列
    bool operator>(const State& other) const {
        return distance > other.distance;
    }
};

vector<int> dijkstra(int start, const Graph& graph) {
    const int V = graph.size();
    
    // 初始化距离数组
    vector<int> distTo(V, numeric_limits<int>::max());
    distTo[start] = 0;

    // 使用 priority_queue 和 greater 比较
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.emplace(start, 0);

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        // 跳过非最短路径
        if (current.distance > distTo[current.node]) {
            continue;
        }

        // 遍历邻居节点
        for (int neighbor : graph.neighbors(current.node)) {
            int newDist = current.distance + graph.weight(current.node, neighbor);
            
            // 如果找到更短路径
            if (newDist < distTo[neighbor]) {
                distTo[neighbor] = newDist;
                pq.emplace(neighbor, newDist);
            }
        }
    }

    return distTo;
}