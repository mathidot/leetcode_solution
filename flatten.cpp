#include "util.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        (void)traverse(root);
    }

    TreeNode* traverse(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *left_node = traverse(root->left);
        TreeNode *right_node = traverse(root->right);

        root->left = nullptr;
        if (left_node != nullptr) {
            root->right = left_node;
            TreeNode *node = left_node;
            while (node->right != nullptr) {
                node = node->right;
            }
            node->right = right_node;
        } else {
            root->right = right_node;
        }
        return root;
    }
};