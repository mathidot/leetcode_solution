#include "util.h"


class Solution {
    // store max depth
    int res = 0;

    // record depth of current node
    int depth = 0;

public:
    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) return;
        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            res = std::max(res, depth);
        }
        traverse(root->left);
        traverse(root->right);
        depth--;
    }
};