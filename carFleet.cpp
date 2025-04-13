#include "util.h"

struct Node {
    int position{};
    double time{};
    Node(int position_, double time_): position(position_), time(time_) {}
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Node> cars;
        for(size_t i = 0; i < position.size(); i++) {
            cars.push_back(Node{position[i],
                static_cast<double>(target - position[i]) / static_cast<double>(speed[i])});
        }

        std::sort(cars.begin(), cars.end(), [](const Node &lhs, const Node &rhs){
            return lhs.position < rhs.position;
        });

        int ans = 0;
        stack<Node> s;
        for (size_t i = 0; i < cars.size(); i++) {
            while (!s.empty() && s.top().time <= cars[i].time) {
                s.pop();
            }
            s.push(cars[i]);
        }
        
        return s.size();
    }
};