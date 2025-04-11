#include "util.h"

class Solution {
    // 记录最大直径的长度
    int maxDiameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        // 后序位置，顺便计算最大直径
        int myDiameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, myDiameter);

        return 1 + max(leftMax, rightMax);
    }
};