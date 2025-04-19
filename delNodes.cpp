#include "util.h"

class Solution {
private:
    vector<TreeNode*> ans;
    std::unordered_set<int> to_delete;

    TreeNode* traverse(TreeNode *root) {
        if (root == nullptr) return nullptr;
        root->left = traverse(root->left);
        root->right = traverse(root->right);
        if (this->to_delete.count(root->val)) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ans.clear();
        this->to_delete = unordered_set(to_delete.begin(), to_delete.end());
        root = traverse(root);
        if (root && !this->to_delete.count(root->val)) {
            ans.push_back(root);
        }
        return ans;
    }
};