#include "util.h"

class Solution {
private:
    int sum = 0;
    void traverse(TreeNode *root, int path) {
        if(root->left == nullptr && root->right == nullptr) {
            path = path * 2 + root->val;
            sum += path;
            return;
        }

        if (root->left != nullptr) {
            traverse(root->left, path*2+root->val);
        }
        if (root->right != nullptr) {
            traverse(root->right, path*2+root->val);
        }
        return;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum =  0;
        if (root == nullptr) return 0;
        traverse(root, 0);
        return sum;
    }
};