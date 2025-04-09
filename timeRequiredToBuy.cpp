#include "util.h"

struct Node {
    int tickets;
    int index;
    Node(int tickets_, int index_): tickets(tickets_), index(index_) {}
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        std::deque<Node> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push_back(Node{tickets[i], i});
        }

        int time = 0;
        while (!q.empty()) {
            auto top_node = q.front();
            q.pop_front();
            top_node.tickets--;
            time++;
            if (top_node.tickets == 0 && top_node.index == k) {
                return time;
            }

            if (top_node.tickets > 0) {
                q.push_back(top_node);
            }
        }
        return -1;
    }
};