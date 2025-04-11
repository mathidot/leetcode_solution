#include "util.h"

class Solution {
public:
    TreeNode* invertTreeI(TreeNode* root) {
        if (root != nullptr) traverse(root);
        return root;
    }

    void traverse(TreeNode* root) {
        if(root != NULL) {
            // *** 前序位置 ***
            // 每一个节点需要做的事就是交换它的左右子节点
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            // 遍历框架，去遍历左右子树的节点
            traverse(root->left);
            traverse(root->right);
        }
    }

    // 定义：将以 root 为根的这棵二叉树翻转，返回翻转后的二叉树的根节点
    TreeNode* invertTreeII(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        // 利用函数定义，先翻转左右子树
        TreeNode* left = invertTreeII(root->left);
        TreeNode* right = invertTreeII(root->right);

        // 然后交换左右子节点
        root->left = right;
        root->right = left;

        // 和定义逻辑自恰：以 root 为根的这棵二叉树已经被翻转，返回 root
        return root;
    }   
};