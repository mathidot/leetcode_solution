#include "util.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};
        vector<double> ans;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            size_t sz = q.size();
            double sum = 0.0;
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += static_cast<double>(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            sum = sum / static_cast<double>(sz);
            ans.push_back(sum);
        }
        return ans;
    }
};