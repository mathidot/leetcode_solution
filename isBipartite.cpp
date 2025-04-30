#include "util.h"

enum Color{
    Red = 0,
    Black = 1
};

class Solution {
private:
    vector<bool> visited;
    vector<Color> colors;
    bool ans = true;
    void dfs(vector<vector<int>> &graph, int index) {
        if (!ans) return;
        visited[index] = true;

        for (auto neighbor: graph[index]) {
            if (!visited[neighbor]) {
                colors[neighbor] = colors[index] == Red ? Black : Red;
                dfs(graph, neighbor);
            } else {
                if (colors[index] == colors[neighbor]) {
                    ans = false;
                    return;
                }
            }
        }
        return;
    }

    void bfs(vector<vector<int>> &graph, int start) {
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty() && ans) {
            int v = q.front();
            q.pop();

            for (int w : graph[v]) {
                if (!visited[w]) {
                    colors[w] = colors[v] == Red ? Black : Red;
                    visited[w] = true;
                    q.push(w);
                } else {
                    if (colors[w] == colors[v]) {
                        ans = false;
                        return;
                    }
                }
            }
        }

    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        visited.resize(n, false);
        colors.resize(n, Red);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(graph, i);
            }
        }
        return ans;
    }
};