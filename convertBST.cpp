#include "util.h"

class Solution {
private:
    int sum = 0;
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
        return;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};