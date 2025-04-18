#include "util.h"

class Solution {
private:
    bool _deserialize(deque<string> &tokens) {
        if (tokens.empty()) return false;
        string token = tokens.front();
        tokens.pop_front();
        if (token == "#") return true;
        return _deserialize(tokens) && _deserialize(tokens);
    }
public:
    bool isValidSerialization(string preorder) {
        deque<string> tokens;
        string token;
        stringstream ss(preorder);
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        return _deserialize(tokens) && tokens.empty();
    }

    bool isValidSerializationI(string preorder) {
        int edge = 1;
        stringstream ss(preorder);
        string node;
        while (getline(ss, node, ',')) {
            if (node == "#") {
                edge -= 1;
                if (edge < 0) {
                    return false;
                }
            } else {
                edge -= 1;
                if (edge < 0) {
                    return false;
                }
                edge += 2;
            }
        }
        return edge == 0;
    }
};