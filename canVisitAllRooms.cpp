#include "util.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        if (n == 0) return true;
        
        unordered_set<int> visited;
        queue<int> q;
        
        // 从房间0开始
        q.push(0);
        visited.insert(0);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int key : rooms[current]) {
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push(key);
                }
            }
        }
        
        return visited.size() == n;
    }
};