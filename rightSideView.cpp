#include "util.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        std::queue<TreeNode *> q;
        if (root == nullptr) return ans;
        q.push(root);
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            size_t sz = q.size();
            for (size_t i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
            }
        }
        return ans; 
    }
    // DFS 递归遍历解法
    vector<int> rightSideView_DFS(TreeNode* root) {
        res.clear();
        depth = 0;
        traverse(root);
        return res;
    }

private:
    vector<int> res;
    // 记录递归的层数
    int depth = 0;

    // 二叉树遍历函数
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序遍历位置
        depth++;
        if (res.size() < depth) {
            // 这一层还没有记录值
            // 说明 root 就是右侧视图的第一个节点
            res.push_back(root->val);
        }
        // 注意，这里反过来，先遍历右子树再遍历左子树
        // 这样首先遍历的一定是右侧节点
        traverse(root->right);
        traverse(root->left);
        // 后序遍历位置
        depth--;
    }
};