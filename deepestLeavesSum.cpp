#include "util.h"

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == nullptr) return 0;
        std::queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            size_t sz = q.size();
            sum = 0;
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
        }
        
        return sum;
    }
};