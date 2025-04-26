#include "util.h"

class Solution {
private:
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode *> ans;
        // base case
        if (lo > hi) {
            ans.emplace_back(nullptr);
            return ans;
        }

        for (int i = lo; i <= hi; i++) {
            vector<TreeNode *> left_tree = build(lo, i-1);
            vector<TreeNode *> right_tree = build(i + 1, hi);
            for (auto left: left_tree) {
                for (auto right: right_tree) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};