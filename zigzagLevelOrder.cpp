#include "util.h"

enum class Direction{
    LEFT_TO_RIGHT = 1,
    RIGHT_TO_LEFT = 2
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        Direction direction = Direction::LEFT_TO_RIGHT;
        if (root == nullptr) return {};
        std::queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            size_t sz = q.size();
            vector<int> temp_vec(sz);
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                int index = direction == Direction::LEFT_TO_RIGHT ? i : sz-1-i;
                temp_vec[index] = node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(temp_vec);
            direction = direction == Direction::LEFT_TO_RIGHT ?
                Direction::RIGHT_TO_LEFT : Direction::LEFT_TO_RIGHT;
        }
        return ans;
    }
};