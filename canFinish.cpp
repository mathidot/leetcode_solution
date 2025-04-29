#include "util.h"

vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph = vector<vector<int>>(numCourses, vector<int>());
    for (const auto &prerequisity: prerequisites) {
        int from = prerequisity.back(), to = prerequisity.front();
        graph[from].push_back(to);
    }
    return graph;
}

class Solution {
private:
    vector<bool> visited;
    vector<bool> on_path;
    bool hasCycle = false;
    void dfs(const vector<vector<int>> &graph, int index) {
        if (hasCycle) {
            return;
        }
        if (on_path[index]) {
            hasCycle = true;
            return;
        }
        if (visited[index]) {
            return;
        }
        on_path[index] = true;
        visited[index] = true;
        for (auto i : graph[index]) {
            dfs(graph, i);
        }
        on_path[index] = false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited = vector<bool>(numCourses, false);
        on_path = vector<bool>(numCourses, false);
        auto graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                dfs(graph, i);
            }
        }
        return !hasCycle;
    }
};

class SolutionBfs {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisities) {
        auto graph = buildGraph(numCourses, prerequisities);
        vector<int> indegre(numCourses, 0);
        for(const auto &edge: prerequisities) {
            indegre[edge[0]]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegre[i] == 0) {
                q.push(i);
            }
        }

        // 记录遍历的节点个数
        int count = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            count++;
            for (int next: graph[cur]) {
                indegre[next]--;
                if (indegre[next] == 0) {
                    q.push(next);
                }
            }
        }

        return count == numCourses;
    }
};