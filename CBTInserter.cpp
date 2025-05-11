#include "util.h"

class CBTInserter {
private:
    TreeNode *root;
public:
    CBTInserter(TreeNode* root_): root(root_) {}
    
    int insert(int val) {
        std::queue<TreeNode *> q;
        q.push(root);

        for (int step = 0; !q.empty(); step++) {
            const size_t level_size = q.size();
            for (size_t i = 0; i < level_size; i++) {
                auto node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr) {
                    node->left = new TreeNode(val);
                    return node->val;
                }

                if (node->left != nullptr && node->right == nullptr) {
                    node->right = new TreeNode(val);
                    return node->val;
                }

                q.push(node->left);
                q.push(node->right);
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};