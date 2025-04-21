#include "util.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            size_t sz = q.size();
            int max_val = std::numeric_limits<int>::min();
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                max_val = std::max(max_val, node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(max_val);
        }        
        return ans;
    }
};