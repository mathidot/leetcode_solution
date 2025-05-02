#include "util.h"

enum Color {
    Black = 0,
    Red = 1
};

class Solution {
private:
    vector<bool> visited;
    vector<int> colors;
    bool flag = true;

    vector<vector<int>> buildGraph(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> graph(n, vector<int>{});
        for (auto dislike: dislikes) {
            int from = dislike[0], to = dislike[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        return graph;
    }

    void dfs(vector<vector<int>> &graph, int v) {
        if (!flag) {
            return;
        }
        visited[v] = true;

        for (auto w : graph[v]) {
            if (!visited[w]) {
                colors[w] = colors[v] == Black ? Red : Black;
                dfs(graph, w);
            } else {
                if (colors[w] == colors[v]) {
                    flag = false;
                    return;
                }
            }
        }
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        auto graph = buildGraph(n + 1, dislikes);
        visited.resize(n + 1, false);
        colors.resize(n + 1, Black);

        for (int v = 1; v <= n; v++) {
            if (!visited[v]) {
                colors[v] = Black;
                dfs(graph, v);
            }
        }
        return flag;
    }
};