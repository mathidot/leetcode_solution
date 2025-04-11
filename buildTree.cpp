#include "util.h"

class Solution {
private:
    TreeNode* constructI(vector<int>::iterator pre_left, vector<int>::iterator pre_right,
                       vector<int>::iterator in_left, vector<int>::iterator in_right, 
                       int depth = 0) 
    {
        if (pre_left == pre_right) {
            return nullptr;
        }

        // 在中序序列中找到根节点位置
        auto in_it = find(in_left, in_right, *pre_left);
        // 创建当前节点
        TreeNode* node = new TreeNode(*pre_left);
        size_t left_size = distance(in_left, in_it);


        // 递归构建左右子树
        node->left = constructI(pre_left + 1, pre_left + 1 + left_size,
                              in_left, in_it, depth + 1);
        node->right = constructI(pre_left + 1 + left_size, pre_right,
                               in_it + 1, in_right, depth + 1);
        return node;
    }

    TreeNode* constructII(vector<int>::iterator in_left, vector<int>::iterator in_right,
                            vector<int>::iterator post_left, vector<int>::iterator post_right)
    {
        if (in_left == in_right) return nullptr;
        auto in_it = find(in_left, in_right, *(post_right-1));
        TreeNode* node = new TreeNode(*(post_right-1));
        size_t left_size = std::distance(in_left, in_it);
        size_t right_size = std::distance(in_it+1, in_right);
        node->left = constructII(in_left, in_it, post_left, post_left+left_size);
        node->right = constructII(in_it+1, in_right, post_left+left_size, post_right-1);
        return node;
    }

public:
    TreeNode* buildTreeI(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = constructI(preorder.begin(), preorder.end(),
                                 inorder.begin(), inorder.end());
        return root;
    }

    TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = constructII(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        return root;
    }
};

// 辅助函数：打印树的结构（可选）
void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;
    string indent(depth * 2, ' ');
    cout << indent << root->val << endl;
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}