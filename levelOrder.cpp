#include "util.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            size_t sz = q.size();
            vector<int> temp_vec;
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                temp_vec.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(temp_vec);
        }
        std::reverse(ans.begin(), ans.begin());
        return ans;
    }
};