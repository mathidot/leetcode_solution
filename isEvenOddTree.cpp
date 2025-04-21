#include "util.h"

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool isEvenLevel = true;
        std::queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int prevVal = isEvenLevel ? -1 : INT_MAX; // Initialize based on level type

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (isEvenLevel) {
                    if (node->val % 2 == 0 || (i > 0 && node->val <= prevVal)) {
                        return false;
                    }
                } else {
                    if (node->val % 2 != 0 || (i > 0 && node->val >= prevVal)) {
                        return false;
                    }
                }

                prevVal = node->val;

                // Push children
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            isEvenLevel = !isEvenLevel;
            level++;
        }
        return true;
    }
};