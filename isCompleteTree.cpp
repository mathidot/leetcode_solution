#include "util.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        std::queue<TreeNode*> q;
        q.push(root);
        bool seen_null = false;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!node) {
                seen_null = true;
            } else {
                // 如果之前已经遇到过空节点，但当前节点非空，则不是完全二叉树
                if (seen_null) return false;
                
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};