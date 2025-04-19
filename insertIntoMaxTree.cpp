#include "util.h"

class Solution {
private:
    TreeNode* traverse(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val < val) {
            TreeNode *temp = root;
            root = new TreeNode(val);
            root->left = temp;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return traverse(root, val);
    }
};