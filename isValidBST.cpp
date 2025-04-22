#include "util.h"

class Solution {
private:
    bool traverse(TreeNode *root, TreeNode *min_node, TreeNode *max_node) {
        if (root == nullptr) return true;
        if (min_node != nullptr && root->val <= min_node->val) return false;
        if (max_node != nullptr && root->val >= max_node->val) return false;
        
        return traverse(root->left, min_node, root) &&
                traverse(root->right, root, max_node);
    }
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root, nullptr, nullptr);
    }
};