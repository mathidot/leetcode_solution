#include "util.h"

class Solution {
private:
struct SumNode {
    int sum = 0;
    int depth = 0;
    SumNode(int sum_, int depth_)
        : sum(sum_), depth(depth_) {}
};
    public:
    int maxLevelSum(TreeNode* root) {
        std::vector<SumNode> sum_nodes;
        std::queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            size_t sz = q.size();
            int sum = 0;
            depth++;
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            sum_nodes.push_back(SumNode{sum, depth});
        }

        std::sort(sum_nodes.begin(), sum_nodes.end(), [](SumNode &lhs, SumNode &rhs) {
            if (lhs.sum > rhs.sum) {
                return true;
            } else if (lhs.sum == rhs.sum) {
                return lhs.depth < rhs.depth;
            } else {
                return false;
            }
        });
        return sum_nodes.front().depth;
    }
};