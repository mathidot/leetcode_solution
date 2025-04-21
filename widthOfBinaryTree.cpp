#include "util.h"

class Solution {
public:
    struct Node {
        TreeNode* node;
        unsigned long long index;  // 使用unsigned long long增加范围
    };

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<Node> q;
        q.push({root, 0});
        unsigned long long max_width = 1;
        
        while (!q.empty()) {
            size_t level_size = q.size();
            unsigned long long level_first_index = q.front().index;  // 当前层第一个节点的索引
            
            unsigned long long first_index = 0, last_index = 0;
            
            for (size_t i = 0; i < level_size; ++i) {
                Node current = q.front();
                q.pop();
                
                // 相对当前层第一个节点的偏移量
                unsigned long long relative_index = current.index - level_first_index;
                
                if (i == 0) first_index = relative_index;
                if (i == level_size - 1) last_index = relative_index;
                
                // 子节点索引基于相对值计算
                if (current.node->left) {
                    q.push({current.node->left, 2 * relative_index});
                }
                if (current.node->right) {
                    q.push({current.node->right, 2 * relative_index + 1});
                }
            }
            
            max_width = max(max_width, last_index - first_index + 1);
        }
        
        return static_cast<int>(max_width);
    }
};
